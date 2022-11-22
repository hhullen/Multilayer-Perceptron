#include "perceptron.h"

namespace s21 {

Perceptron::Perceptron(int input_neurons, int hidden_layers, int output_neurons)
    : layers_(nullptr),
      output_layer_(nullptr),
      input_layer_(nullptr),
      training_progress_percent_(0),
      training_dataset_lines_(0),
      training_dataset_path_(""),
      training_start_(0),
      training_rate_(0.01),
      expected_sym_(0),
      output_sym_(0),
      current_epoch_(0),
      answer_confidence_(0),
      training_strings_(0),
      epochs_(5),
      testing_progress_percent_(0),
      testing_dataset_lines_(0),
      testing_dataset_path_(""),
      testing_strings_(0),
      right_answers_(0),
      all_answers_(0),
      cross_testing_begin_(0),
      cross_testing_end_(0),
      terminated_(false),
      running_(false),
      under_training_(false) {
  layers_ = new vector<PerceptronLayer *>(hidden_layers + 2);
  (*layers_)[0] = new PerceptronLayer(LayerType::INPUT, input_neurons);
  int prev_neurons_amount = input_neurons;

  ++hidden_layers;
  for (int i = 1; i < hidden_layers; ++i) {
    int neurons = kHIDDEN_NEURONS;
    (*layers_)[i] =
        new PerceptronLayer(LayerType::OTHER, neurons, prev_neurons_amount);
    prev_neurons_amount = neurons;
  }

  (*layers_)[hidden_layers] = new PerceptronLayer(
      LayerType::OTHER, output_neurons, prev_neurons_amount);
  input_layer_ = (*layers_).front();
  output_layer_ = (*layers_).back();
}

Perceptron::~Perceptron() {
  for (int i = 0; i < layers_->size(); ++i) {
    (*layers_)[i]->~PerceptronLayer();
    if ((*layers_)[i]) {
      delete (*layers_)[i];
      (*layers_)[i] = nullptr;
    }
  }
  layers_->clear();
  delete layers_;
  layers_ = nullptr;
}

void Perceptron::FillWithRandom() {
  for (size_t i = 1; i < layers_->size(); ++i) {
    FillMatrixRandom(*(*layers_)[i]->get_weights());
  }
}

void Perceptron::FillMatrixRandom(Matrix &matrix) {
  int cols = matrix.get_cols(), rows = matrix.get_rows();

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      matrix(i, j) = (fmod(rand(), kRANDOM_FACTOR) / kRANDOM_FACTOR * 2) - 1;
    }
  }
}

bool Perceptron::SaveConfig(const string &path) {
  ofstream file;
  bool returnable = false;
  string extended;

  extended = path;
  extended.append(to_string(input_layer_->get_neurons()->get_rows()) + "_" +
                  to_string(layers_->size() - 2) + "_" +
                  to_string(output_layer_->get_neurons()->get_rows()) +
                  ".wcfg");
  file.open(extended, ios_base::binary & ios_base::app);
  if (file.is_open()) {
    SaveLayers(file);
    returnable = true;
    file.close();
  }

  return returnable;
}

void Perceptron::SaveLayers(ofstream &file) {
  for (size_t i = 1; i < layers_->size(); ++i) {
    Matrix &p_weights = *(*layers_)[i]->get_weights();
    WriteMAtrixSize(file, p_weights);
    WriteMatrix(file, p_weights);
  }
}

void Perceptron::WriteMAtrixSize(ofstream &file, Matrix &matrix) {
  int rows = matrix.get_rows();
  int cols = matrix.get_cols();
  file.write((char *)&rows, sizeof(int));
  file.write((char *)&cols, sizeof(int));
}

void Perceptron::WriteMatrix(ofstream &file, Matrix &matrix) {
  for (int i = 0; i < matrix.get_rows(); ++i) {
    for (int j = 0; j < matrix.get_cols(); ++j) {
      double value = matrix(i, j);
      file.write((char *)&value, sizeof(double));
    }
  }
}

bool Perceptron::UploadConfig(const string &path) {
  ifstream file(path, ios_base::binary);
  bool returnable = false;

  if (file.is_open() && UploadLayers(file)) {
    returnable = true;
    file.close();
  }

  return returnable;
}

bool Perceptron::UploadLayers(ifstream &file) {
  int rows, cols, frows, fcols;
  bool returnable = true;

  for (size_t i = 1; i < layers_->size() && returnable; ++i) {
    Matrix &p_weights = *(*layers_)[i]->get_weights();
    GetMatrixAndDataSizes(p_weights, &rows, &cols, file, &frows, &fcols);

    if (rows == frows && cols == fcols && ReadMatrix(file, p_weights)) {
      returnable = true;
    } else {
      returnable = false;
    }
  }

  return returnable;
}

bool Perceptron::ReadMatrix(ifstream &file, Matrix &matrix) {
  int i = 0, j = matrix.get_cols();
  bool returnable = false;
  double value;

  for (; i < matrix.get_rows() && j == matrix.get_cols(); ++i) {
    j = 0;
    for (; j < matrix.get_cols() && file.read((char *)&value, sizeof(double));
         ++j) {
      matrix(i, j) = value;
    }
  }
  if (i == matrix.get_rows() && j == matrix.get_cols()) {
    returnable = true;
  }

  return returnable;
}

void Perceptron::GetMatrixAndDataSizes(Matrix &matrix, int *rows, int *cols,
                                       ifstream &file, int *frows, int *fcols) {
  *rows = matrix.get_rows();
  *cols = matrix.get_cols();
  file.read((char *)frows, sizeof(int));
  file.read((char *)fcols, sizeof(int));
}

void Perceptron::Run() {
  terminated_ = false;

  for (size_t i = 1; i < layers_->size(); ++i) {
    Matrix &weights = *(*layers_)[i]->get_weights();
    Matrix &neurons = *(*layers_)[i - 1]->get_neurons();
    Matrix &new_neurons = *(*layers_)[i]->get_neurons();
    new_neurons = weights * neurons;
    Activate(new_neurons);
  }
  output_sym_ = GetAnswer();
}

void Perceptron::Activate(Matrix &matrix) {
  for (size_t i = 0; i < matrix.get_rows(); ++i) {
    matrix(i, 0) = Sigmoid(matrix(i, 0));
  }
}

double Perceptron::Sigmoid(const double value) {
  return 1 / (1 + pow(kEXPONENT, -value));
}

double Perceptron::SigmoidDerivative(const double value) {
  return value * (1 - value);
}

char Perceptron::GetAnswer() {
  Matrix &output = *output_layer_->get_neurons();
  size_t neurons = output.get_rows();
  char returnable = 0;
  double higher = 0;

  for (size_t i = 0; i < neurons; ++i) {
    if (output(i, 0) > higher) {
      higher = output(i, 0);
      answer_confidence_ = higher * 100;
      returnable = i;
    }
  }

  return returnable;
}

bool Perceptron::Train(const string &learn_dataset_path,
                       const string &test_dataset_path,
                       double test_sample_coeff) {
  bool returnable = false;

  under_training_ = true;
  running_ = true;
  terminated_ = false;
  avg_accuracy_.clear();
  training_dataset_path_ = learn_dataset_path;
  testing_dataset_path_ = test_dataset_path;
  returnable = CalculateFile(training_dataset_path_, &training_dataset_lines_);
  if (test_sample_coeff > 1 || test_sample_coeff < 0) {
    test_sample_coeff = 0;
  }

  training_strings_ = training_dataset_lines_ * test_sample_coeff;
  if (returnable) {
    for (current_epoch_ = 1;
         !terminated_ && returnable && current_epoch_ <= epochs_;
         ++current_epoch_) {
      DatasetLearning(0, 0);
      returnable = Test(testing_dataset_path_, 1);
    }
    --current_epoch_;
  }

  under_training_ = false;
  running_ = false;
  terminated_ = false;
  return returnable;
}

bool Perceptron::CalculateFile(string &dataset_path, size_t *dataset_lines) {
  ifstream file(dataset_path);
  bool returnable = false;
  string line;

  *dataset_lines = 0;
  if (file.is_open()) {
    while (!getline(file, line, '\n').eof()) {
      ++*dataset_lines;
    }
    ++*dataset_lines;
    file.close();
    returnable = true;
  }

  return returnable;
}

void Perceptron::DatasetLearning(size_t test_chunk_begin,
                                 size_t test_chunk_end) {
  ifstream file;
  string line;
  size_t iterator = 0;

  training_progress_percent_ = 0;
  file.open(training_dataset_path_);
  if (file.is_open()) {
    while (!terminated_ && !getline(file, line, '\n').eof()) {
      if (IsOutOfArea(iterator, test_chunk_begin, test_chunk_end) ||
          iterator == 0) {
        FillInput(line);
        Run();
        Backpropagation();
      }
      training_progress_percent_ =
          TrackProgress(iterator + 1, training_dataset_lines_);
      ++iterator;
    }
    training_progress_percent_ =
        TrackProgress(iterator + 1, training_dataset_lines_);
    file.close();
  }
}

size_t Perceptron::TrackProgress(size_t current, size_t total) {
  return current / (double)total * 100;
}

void Perceptron::FillInput(string &line) {
  Matrix &p_input = *input_layer_->get_neurons();
  size_t input_size = p_input.get_rows();
  size_t file_iter = 2;

  expected_sym_ = stod(line.data(), nullptr) - 1;
  for (size_t i = 0; i < input_size; ++i) {
    if (file_iter < line.size() && line.size() > 2) {
      while (!IsAsciiNumber(line[file_iter])) {
        ++file_iter;
      }
      p_input(i, 0) = stod(&line.data()[file_iter], nullptr) / 255.0;
      while (IsAsciiNumber(line[file_iter])) {
        ++file_iter;
      }
    } else {
      p_input(i, 0) = 0;
    }
  }
}

bool Perceptron::IsAsciiNumber(const char sym) {
  return sym >= '0' && sym <= '9';
}

bool Perceptron::IsInOfArea(size_t line_number, size_t chunk_begin,
                            size_t chunk_end) {
  return line_number >= chunk_begin && line_number <= chunk_end;
}

bool Perceptron::IsOutOfArea(size_t line_number, size_t chunk_begin,
                             size_t chunk_end) {
  return line_number < chunk_begin || line_number > chunk_end;
}

void Perceptron::Backpropagation() {
  int i = layers_->size() - 2;
  CorrectOutputLayerWeights(*(*layers_)[i], *output_layer_);

  for (; i > 0; --i) {
    CorrectHiddenLayerWeights(*(*layers_)[i - 1], *(*layers_)[i],
                              *(*layers_)[i + 1]);
  }
}

void Perceptron::CorrectOutputLayerWeights(PerceptronLayer &layer_l,
                                           PerceptronLayer &layer) {
  Matrix &neurons_l = *layer_l.get_neurons();
  Matrix &d_weights = *layer.get_d_weights();
  Matrix &neurons = *layer.get_neurons();
  Matrix &errors = *layer.get_errors();
  Matrix &weights = *layer.get_weights();

  GetOutputLayerErrors(neurons, errors);
  CalculateGradient(neurons_l, errors, weights);
}

void Perceptron::GetOutputLayerErrors(const Matrix &neurons, Matrix &errors) {
  for (size_t i = 0; i < neurons.get_rows(); ++i) {
    if (i == expected_sym_) {
      errors(i, 0) = (neurons(i, 0) - 1) * SigmoidDerivative(neurons(i, 0));
    } else {
      errors(i, 0) = neurons(i, 0) * SigmoidDerivative(neurons(i, 0));
    }
  }
}

void Perceptron::CorrectHiddenLayerWeights(PerceptronLayer &layer_l,
                                           PerceptronLayer &layer,
                                           PerceptronLayer &layer_r) {
  Matrix &neurons_l = *layer_l.get_neurons();
  Matrix &weights_r = *layer_r.get_weights();
  Matrix &d_weights = *layer.get_d_weights();
  Matrix &errors_r = *layer_r.get_errors();
  Matrix &neurons = *layer.get_neurons();
  Matrix &weights = *layer.get_weights();
  Matrix &errors = *layer.get_errors();

  GetHiddenLayerErrors(weights_r, errors_r, neurons, errors);
  CalculateGradient(neurons_l, errors, weights);
}

void Perceptron::GetHiddenLayerErrors(const Matrix &weights_r,
                                      const Matrix &errors_r,
                                      const Matrix &neurons, Matrix &errors) {
  errors = weights_r.transpose() * errors_r;
  for (size_t i = 0; i < errors.get_rows(); ++i) {
    errors(i, 0) *= SigmoidDerivative(neurons(i, 0));
  }
}

void Perceptron::CalculateGradient(const Matrix &neurons_l,
                                   const Matrix &errors, Matrix &weights) {
  for (size_t i = 0; i < errors.get_rows(); ++i) {
    for (size_t j = 0; j < neurons_l.get_rows(); ++j) {
      weights(i, j) -= neurons_l(j, 0) * errors(i, 0) * training_rate_;
    }
  }
}

void Perceptron::Terminate() { terminated_ = true; }

bool Perceptron::Test(const string &dataset_path, double test_sample_coeff) {
  bool returnable = false;
  ifstream file;

  running_ = true;
  testing_progress_percent_ = 0;
  testing_dataset_path_ = dataset_path;
  returnable = CalculateFile(testing_dataset_path_, &testing_dataset_lines_);
  if (test_sample_coeff > 1 || test_sample_coeff < 0) {
    test_sample_coeff = 1;
  }
  testing_strings_ = testing_dataset_lines_ * test_sample_coeff;
  file.open(dataset_path);
  if (returnable && file.is_open()) {
    RunTesting(file, 0, testing_strings_);
    file.close();
  }
  testing_progress_percent_ = 0;

  if (!under_training_) {
    running_ = false;
    terminated_ = false;
  }
  return returnable;
}

void Perceptron::RunTesting(ifstream &file, size_t test_chunk_begin,
                            size_t test_chunk_end) {
  size_t iterator = 0;
  string line;

  CleanMetrics();
  while (!terminated_ && !getline(file, line, '\n').eof()) {
    if (IsInOfArea(iterator, test_chunk_begin, test_chunk_end)) {
      FillInput(line);
      Run();
      UpdateMetrics(right_answers_, letters_);
    }
    testing_progress_percent_ =
        TrackProgress(iterator + 1, testing_dataset_lines_);
    ++iterator;
  }
  testing_progress_percent_ =
      TrackProgress(iterator + 1, testing_dataset_lines_);

  avg_accuracy_.push_back(right_answers_ / (double)testing_strings_);
  FinishMetrics(right_answers_, letters_);
}

void Perceptron::CleanMetrics() {
  right_answers_ = 0;
  precision_.clear();
  recall_.clear();
  f_measure_.clear();
  letters_.clear();
}

void Perceptron::UpdateMetrics(size_t &right_answers,
                               map<size_t, size_t> &letters) {
  ++letters[expected_sym_];
  if (expected_sym_ == output_sym_) {
    ++right_answers;
    ++precision_[expected_sym_];
    ++recall_[expected_sym_];
  }
}

void Perceptron::FinishMetrics(size_t &right_answers,
                               map<size_t, size_t> &letters) {
  all_answers_ = testing_strings_;
  for (size_t i = 0; i < precision_.size(); ++i) {
    precision_[i] /= (double)right_answers;
    recall_[i] /= (double)letters[i];
    f_measure_[i] = FMeasure(precision_[i], recall_[i]);
  }
}

double Perceptron::FMeasure(double precision, double recall) {
  return 2 * precision * recall / (double)(precision + recall);
}

bool Perceptron::CrossValidation(const string &learn_dataset_path,
                                 size_t groups) {
  bool returnable = false;

  running_ = true;
  terminated_ = false;
  training_dataset_path_ = learn_dataset_path;
  returnable = CalculateFile(training_dataset_path_, &training_dataset_lines_);
  training_strings_ = training_dataset_lines_;
  testing_dataset_lines_ = training_dataset_lines_;
  if (groups > training_strings_ / 2) {
    groups = training_strings_ / 2;
  }

  if (returnable) {
    RunCrossValidating(groups);
  }

  running_ = false;
  return returnable;
}

void Perceptron::RunCrossValidating(size_t groups) {
  size_t cross_testing_shift = 0;
  ifstream file;

  cross_testing_begin_ = 0;
  cross_testing_shift = training_strings_ / groups;
  testing_strings_ = cross_testing_shift;
  cross_testing_end_ = cross_testing_shift;
  avg_accuracy_.clear();
  current_epoch_ = 1;
  while (!terminated_ && cross_testing_end_ < training_strings_) {
    DatasetLearning(cross_testing_begin_, cross_testing_end_);
    file.open(training_dataset_path_);
    if (file.is_open()) {
      RunTesting(file, cross_testing_begin_, cross_testing_end_);
      file.close();
    }
    cross_testing_begin_ += cross_testing_shift;
    cross_testing_end_ += cross_testing_shift;
    ++current_epoch_;
  }
  --current_epoch_;
  if (file.is_open()) {
    file.close();
  }
}

bool Perceptron::IsRunning() { return running_; }

bool Perceptron::set_input_neurons(Matrix &matrix) {
  Matrix &input = *input_layer_->get_neurons();
  bool returnable = true;

  if (matrix.get_cols() != input.get_cols() ||
      matrix.get_rows() != input.get_rows()) {
    returnable = false;
  } else {
    input = matrix;
  }

  return returnable;
}

void Perceptron::set_epochs_amount(size_t epochs) { epochs_ = epochs; }

Matrix *Perceptron::get_output_neurons() {
  return output_layer_->get_neurons();
}

size_t Perceptron::get_training_progress() {
  return training_progress_percent_;
}

size_t Perceptron::get_testing_progress() { return testing_progress_percent_; }

char Perceptron::get_recognized_letter() { return output_sym_; }

double Perceptron::get_answer_confidence() { return answer_confidence_; }

void Perceptron::set_learning_rate(double value) { training_rate_ = value; }

size_t Perceptron::get_current_epoch() { return current_epoch_; }

vector<double> *Perceptron::get_avg_accuracy() { return &avg_accuracy_; }

void Perceptron::get_metrics(vector<map<size_t, double>> &metrics,
                             size_t *correct, size_t *all,
                             double *avg_accuracy) {
  metrics.push_back(precision_);
  metrics.push_back(recall_);
  metrics.push_back(f_measure_);
  *correct = right_answers_;
  *all = all_answers_;
  *avg_accuracy = avg_accuracy_.back();
}

}  // namespace s21
