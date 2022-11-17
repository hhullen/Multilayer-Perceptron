#include "perceptron.h"

#include <iostream>

namespace s21 {

Perceptron::Perceptron(int input_neurons, int hidden_layers, int output_neurons)
    : learning_rate_(0.01),
      learning_strings_(0),
      testing_strings_(0),
      epochs_(60) {
  layers_ = new vector<PerceptronLayer *>(hidden_layers + 2);
  (*layers_)[0] = new PerceptronLayer(LayerType::INPUT, input_neurons);
  int prev_neurons_amount = input_neurons;

  ++hidden_layers;
  for (int i = 1; i < hidden_layers; ++i) {
    // int neurons = GetNeuronsToHiddenLayer(hidden_layers, i);
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
  delete input_layer_;
  delete output_layer_;
}

void Perceptron::FillWithRandom() {
  for (size_t i = 1; i < layers_->size(); ++i) {
    FillMatrixRandom(*(*layers_)[i]->get_weights());
  }
}

void Perceptron::FillMatrixRandom(Matrix &matrix) {
  int cols = matrix.get_cols(), rows = matrix.get_rows();
  double elements = cols * rows;
  double value = -1;

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      matrix(i, j) = (fmod(rand(), kRANDOM_FACTOR) / kRANDOM_FACTOR * 2) - 1;
    }
  }
}

bool Perceptron::SaveConfig(const string &path) {
  ofstream file(path, ios_base::binary & ios_base::app);
  bool returnable = false;

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

int Perceptron::GetNeuronsToHiddenLayer(int layers_amount, int layer_number) {
  int returnable = ceil(
      pow(kEXPONENT, -(kDELTA_CONST / (layers_amount + 1) * (layer_number + 1) +
                       kINPUT_LAYER_CONST)) *
      kFACTOR);
  if (returnable < 1) {
    returnable = 1;
  }

  return returnable;
}

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

Matrix *Perceptron::get_output_neurons() {
  return output_layer_->get_neurons();
}

void Perceptron::set_epochs_amount(size_t epochs) { epochs_ = epochs; }

void Perceptron::Run() {
  terminated_ = false;
  for (size_t i = 1; i < layers_->size(); ++i) {
    Matrix &weights = *(*layers_)[i]->get_weights();
    Matrix &neurons = *(*layers_)[i - 1]->get_neurons();
    Matrix layer_out(weights * neurons);
    Activate(layer_out);
    *(*layers_)[i]->get_neurons() = layer_out;
  }
  output_sym_ = GetAnswer();

  if (output_sym_ == expected_sym_) {
    // std::cout << "\tright\n";
    ++in_a_row;
  } else {
    // std::cout << "\tnot\n";
    in_a_row = 0;
  }

  // if (in_a_row > 400) {
  //   Terminate();
  // }
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

  running_ = true;
  terminated_ = false;
  learning_dataset_path_ = learn_dataset_path;
  testing_dataset_path_ = test_dataset_path;
  returnable = CalculateFile(learning_dataset_path_, &learning_dataset_lines_);
  if (test_sample_coeff > 1 || test_sample_coeff < 0) {
    test_sample_coeff = 0;
  }

  learning_strings_ = learning_dataset_lines_ * test_sample_coeff;
  std::cout << "TESTING: " << learning_strings_ << " " << returnable << "\n";
  if (returnable) {
    avg_accuracy_.clear();
    for (size_t i = 0; !terminated_ && returnable && i < epochs_; ++i) {
      std::cout << "EPOCH: " << i << "\n";
      DatasetLearning(0, 0);
      returnable = Test(testing_dataset_path_, 1);
      // SaveConfig("cfg_42_5_60_0.01.bin");
    }
    std::cout << "IN A ROW IS: " << in_a_row << "\n";
  }

  running_ = false;
  return returnable;
}

bool Perceptron::CalculateFile(string &dataset_path, size_t *dataset_lines) {
  ifstream file(dataset_path);
  std::cout << dataset_path << "\n";
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
  std::cout << "LINES: " << *dataset_lines << "\n";

  return returnable;
}

void Perceptron::DatasetLearning(size_t test_chunk_begin,
                                 size_t test_chunk_end) {
  ifstream file;
  string line;
  size_t iterator = 0;

  size_t tmp = 0;

  learning_progress_percent_ = 0;
  file.open(learning_dataset_path_);
  if (file.is_open()) {
    while (!terminated_ && !getline(file, line).eof()) {
      if (IsOutOfArea(iterator, test_chunk_begin, test_chunk_end)) {
        FillInput(line);
        Run();
        Backpropagation();
      }
      learning_progress_percent_ =
          TrackProgress(iterator + 1, learning_dataset_lines_);
      ++iterator;

      // if (tmp != learning_progress_percent_) {
      //   printf("Learning progress: %ld\n", learning_progress_percent_);
      // }
      // tmp = learning_progress_percent_;
    }
    learning_progress_percent_ =
        TrackProgress(iterator + 1, learning_dataset_lines_);
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
      p_input(i, 0) = stod(&line.data()[file_iter], nullptr) / 255;
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
  CalculateGradient(neurons_l, errors, d_weights);
  d_weights.mul_number(learning_rate_);
  weights -= d_weights;
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
  CalculateGradient(neurons_l, errors, d_weights);
  d_weights.mul_number(learning_rate_);
  weights -= d_weights;
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
                                   const Matrix &errors, Matrix &d_weights) {
  for (size_t i = 0; i < errors.get_rows(); ++i) {
    for (size_t j = 0; j < neurons_l.get_rows(); ++j) {
      d_weights(i, j) = neurons_l(j, 0) * errors(i, 0);
    }
  }
}

void Perceptron::Terminate() {
  terminated_ = true;
  std::cout << "\n\nTERMINATED\n";
}

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

  running_ = false;
  return returnable;
}

void Perceptron::RunTesting(ifstream &file, size_t test_chunk_begin,
                            size_t test_chunk_end) {
  map<size_t, size_t> letters;
  size_t right_answers = 0;
  size_t iterator = 0;
  string line;

  size_t tmp = 0;

  precision_.clear();
  recall_.clear();
  f_measure_.clear();
  letters.clear();
  while (!getline(file, line).eof()) {
    if (IsInOfArea(iterator, test_chunk_begin, test_chunk_end)) {
      FillInput(line);
      Run();
      UpdateMetrics(right_answers, letters);
    }
    testing_progress_percent_ =
        TrackProgress(iterator + 1, testing_dataset_lines_);
    ++iterator;

    // if (tmp != testing_progress_percent_) {
    //   printf("Testing progress: %ld\n", tmp);
    // }
    // tmp = testing_progress_percent_;
  }
  testing_progress_percent_ =
      TrackProgress(iterator + 1, testing_dataset_lines_);
  avg_accuracy_.push_back(right_answers / (double)testing_strings_);
  FinishMetrics(right_answers, letters);
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
  std::cout << "PRECISION\tRECALL\t\tF-MEASURE\tAVG-ACC\t\tANSS\n";

  for (size_t i = 0; i < precision_.size(); ++i) {
    precision_[i] /= (double)right_answers;
    recall_[i] /= (double)letters[i];
    f_measure_[i] = FMeasure(precision_[i], recall_[i]);

    printf("%.3lf\t\t%.3lf\t\t%.3lf\t\t%.3lf\t\t%ld\n", precision_[i] * 100,
           recall_[i] * 100, f_measure_[i] * 100, avg_accuracy_.back() * 100,
           right_answers);
  }
}

double Perceptron::FMeasure(double precision, double recall) {
  return 2 * precision * recall / (double)(precision + recall);
}

bool Perceptron::CrossValidation(const string &learn_dataset_path,
                                 size_t groups) {
  bool returnable = false;

  terminated_ = false;
  learning_dataset_path_ = learn_dataset_path;
  returnable = CalculateFile(learning_dataset_path_, &learning_dataset_lines_);
  learning_strings_ = learning_dataset_lines_;
  testing_dataset_lines_ = learning_dataset_lines_;
  if (groups > learning_strings_ / 2) {
    groups = learning_strings_ / 2;
  }

  if (returnable) {
    RunCrossValidating(groups);
  }

  return returnable;
}

void Perceptron::RunCrossValidating(size_t groups) {
  size_t cross_testing_shift = 0;
  ifstream file;

  cross_testing_begin_ = 0;
  cross_testing_shift = learning_strings_ / groups;
  testing_strings_ = cross_testing_shift;
  cross_testing_end_ = cross_testing_shift;
  avg_accuracy_.clear();
  while (cross_testing_end_ < learning_strings_) {
    printf("TEST CHUNK: %ld - %ld\n", cross_testing_begin_, cross_testing_end_);
    DatasetLearning(cross_testing_begin_, cross_testing_end_);
    file.open(learning_dataset_path_);
    if (file.is_open()) {
      RunTesting(file, cross_testing_begin_, cross_testing_end_);
      file.close();
    }
    cross_testing_begin_ += cross_testing_shift;
    cross_testing_end_ += cross_testing_shift;
  }
  file.close();
}

bool Perceptron::IsRunning() { return running_; }

size_t Perceptron::get_learning_progress() {
  return learning_progress_percent_;
}

size_t Perceptron::get_testing_progress() { return testing_progress_percent_; }

char Perceptron::get_recognized_letter() { return output_sym_; }
}  // namespace s21
