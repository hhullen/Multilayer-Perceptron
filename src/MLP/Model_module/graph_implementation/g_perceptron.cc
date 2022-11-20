#include "g_perceptron.h"

namespace s21 {

GPerceptron::GPerceptron(int input_neurons, int hidden_layers,
                         int output_neurons) {
  state_.under_training_ = false;
  state_.answer_confidence_ = 0;
  state_.terminated_ = false;
  train_.current_epoch_ = 0;
  train_.dataset_path_ = "";
  state_.expected_sym_ = 0;
  state_.running_ = false;
  state_.output_sym_ = 0;

  train_.current_epoch_ = 0;
  train_.dataset_path_ = "";
  train_.progress_ = 0;
  train_.strings_ = 0;
  train_.file.clear();
  train_.epochs_ = 5;
  train_.start_ = 0;
  train_.rate_ = 0;

  test_.dataset_path_ = "";
  test_.progress_ = 0;
  test_.strings_ = 0;
  test_.file.clear();

  metric_.avg_accuracy_.clear();
  metric_.f_measure_.clear();
  metric_.precision_.clear();
  metric_.right_answers_ = 0;
  metric_.all_answers_ = 0;
  metric_.letters_.clear();
  metric_.recall_.clear();

  cross_v_.begin_ = 0;
  cross_v_.end_ = 0;

  ConfigurateSize(input_neurons, hidden_layers, output_neurons);
  p_input_ = &layers_.front();
  p_output_ = &layers_.back();
  ConnectLayers();
}

GPerceptron::~GPerceptron() {
  metric_.avg_accuracy_.clear();
  metric_.precision_.clear();
  metric_.f_measure_.clear();
  metric_.letters_.clear();
  metric_.recall_.clear();
  train_.file.clear();
  test_.file.clear();
}

double &GPerceptron::w_element(vector<GNeuron> &layer, size_t i, size_t j) {
  return layer[i].get_weights()[j];
}

void GPerceptron::ConfigurateSize(int input_neurons, int hidden_layers,
                                  int output_neurons) {
  layers_.resize(hidden_layers + 2);
  layers_.shrink_to_fit();
  layers_.front().resize(input_neurons);
  layers_.front().shrink_to_fit();
  layers_.back().resize(output_neurons);
  layers_.back().shrink_to_fit();
  for (size_t i = 1; i < layers_.size() - 1; ++i) {
    layers_[i].resize(kHIDDEN_NEURONS);
    layers_[i].shrink_to_fit();
  }
}

void GPerceptron::ConnectLayers() {
  for (size_t i = 0; i < layers_.size(); ++i) {
    if (i == 0) {
      ConnectNeurons(nullptr, p_input_, &layers_[i + 1]);
    } else if (i == layers_.size() - 1) {
      ConnectNeurons(&layers_[i - 1], p_output_, nullptr);
    } else {
      ConnectNeurons(&layers_[i - 1], &layers_[i], &layers_[i + 1]);
    }
  }
}

void GPerceptron::ConnectNeurons(vector<GNeuron> *prev,
                                 vector<GNeuron> *current,
                                 vector<GNeuron> *next) {
  for (size_t i = 0; i < current->size(); ++i) {
    for (size_t j = 0; prev && j < prev->size(); ++j) {
      (*current)[i].ConnectL(&(*prev)[j]);
    }
    for (size_t k = 0; next && k < next->size(); ++k) {
      (*current)[i].ConnectR(&(*next)[k]);
    }
  }
}

bool GPerceptron::UploadConfig(const string &path) {
  ifstream file(path, ios_base::binary);
  bool returnable = false;

  if (file.is_open() && UploadLayers(file)) {
    returnable = true;
    file.close();
  }

  return returnable;
}

bool GPerceptron::UploadLayers(ifstream &file) {
  int neurons, weights, fneurons, fweights;
  bool returnable = true;

  for (size_t i = 1; i < layers_.size() && returnable; ++i) {
    vector<GNeuron> &layer = layers_[i];
    neurons = layer.size();
    weights = layer.front().get_weights().size();
    file.read((char *)&fneurons, sizeof(int));
    file.read((char *)&fweights, sizeof(int));

    if (neurons == fneurons && weights == fweights && ReadMatrix(file, layer)) {
      returnable = true;
    } else {
      returnable = false;
    }
  }

  return returnable;
}

bool GPerceptron::ReadMatrix(ifstream &file, vector<GNeuron> &layer) {
  int weights = layer.front().get_weights().size();
  int neurons = layer.size();
  bool returnable = false;
  int i = 0, j = weights;
  double value;

  for (; i < neurons && j == weights; ++i) {
    j = 0;
    for (; j < weights && file.read((char *)&value, sizeof(double)); ++j) {
      w_element(layer, i, j) = value;
    }
  }
  if (i == neurons && j == weights) {
    returnable = true;
  }

  return returnable;
}

bool GPerceptron::SaveConfig(const string &path) {
  ofstream file;
  bool returnable = false;
  string extended;

  extended = path;
  extended.append(to_string(p_input_->size()) + "_" +
                  to_string(layers_.size() - 2) + "_" +
                  to_string(p_output_->size()) + ".wcfg");
  file.open(extended, ios_base::binary & ios_base::app);
  if (file.is_open()) {
    SaveLayers(file);
    returnable = true;
    file.close();
  }

  return returnable;
}

void GPerceptron::SaveLayers(ofstream &file) {
  for (size_t i = 1; i < layers_.size(); ++i) {
    WriteDataSize(file, layers_[i]);
    WriteData(file, layers_[i]);
  }
}

void GPerceptron::WriteDataSize(ofstream &file, vector<GNeuron> &layer) {
  int neurons = layer.size();
  int weights = layer.front().get_weights().size();

  file.write((char *)&neurons, sizeof(int));
  file.write((char *)&weights, sizeof(int));
}

void GPerceptron::WriteData(ofstream &file, vector<GNeuron> &layer) {
  int weights = layer.front().get_weights().size();
  int neurons = layer.size();
  for (int i = 0; i < neurons; ++i) {
    for (int j = 0; j < weights; ++j) {
      double value = w_element(layer, i, j);
      file.write((char *)&value, sizeof(double));
    }
  }
}

void GPerceptron::FillWithRandom() {
  for (size_t i = 1; i < layers_.size(); ++i) {
    FillMatrixRandom(layers_[i]);
  }
}

void GPerceptron::FillMatrixRandom(vector<GNeuron> &layer) {
  int weights = layer.front().get_weights().size();
  int neurons = layer.size();

  for (int i = 0; i < neurons; ++i) {
    for (int j = 0; j < weights; ++j) {
      w_element(layer, i, j) =
          (fmod(rand(), kRANDOM_FACTOR) / kRANDOM_FACTOR * 2) - 1;
      std::cout << w_element(layer, i, j) << " RAND\n";
    }
  }
}

bool GPerceptron::IsRunning() { return state_.running_; }

void GPerceptron::Terminate() { state_.terminated_ = true; }

void GPerceptron::Run() {
  state_.terminated_ = false;

  for (size_t i = 1; i < layers_.size(); ++i) {
    WeightedSum(layers_[i]);
    Activate(layers_[i]);
  }
  state_.output_sym_ = GetAnswer();
}

void GPerceptron::WeightedSum(vector<GNeuron> &layer) {
  int weights = layer.front().get_weights().size();
  int neurons = layer.size();
  double sum = 0;

  for (size_t i = 0; i < neurons; ++i) {
    sum = 0;
    for (size_t j = 0; j < weights; ++j) {
      sum += w_element(layer, i, j) * layer[i].get_value_l(j);
    }
    layer[i].set_value(sum);
  }
}

void GPerceptron::Activate(vector<GNeuron> &layer) {
  for (size_t i = 0; i < layer.size(); ++i) {
    layer[i].set_value(Sigmoid(layer[i].get_value()));
  }
}

double GPerceptron::Sigmoid(const double value) {
  return 1 / (1 + pow(kEXPONENT, -value));
}

double GPerceptron::SigmoidDerivative(const double value) {
  return value * (1 - value);
}

char GPerceptron::GetAnswer() {
  size_t neurons = p_output_->size();
  char returnable = 0;
  double higher = 0;

  for (size_t i = 0; i < neurons; ++i) {
    double value = (*p_output_)[i].get_value();
    std::cout << value << "\n";
    if (value > higher) {
      higher = value;
      state_.answer_confidence_ = higher * 100;
      returnable = i;
    }
  }

  return returnable;
}

bool GPerceptron::set_input_neurons(vector<double> input) {
  size_t i = 0;
  bool returnable = true;

  if (p_input_->size() != input.size()) {
    returnable = false;
  } else {
    for (; i < p_input_->size(); ++i) {
      (*p_input_)[i].set_value(input[i]);
    }
  }

  return returnable;
}

bool GPerceptron::Train(const string &learn_dataset_path,
                        const string &test_dataset_path,
                        double test_sample_coeff) {
  bool returnable = false;

  state_.under_training_ = true;
  state_.running_ = true;
  state_.terminated_ = false;
  metric_.avg_accuracy_.clear();
  train_.dataset_path_ = learn_dataset_path;
  test_.dataset_path_ = test_dataset_path;
  train_.file.clear();
  returnable = UploadDataset(train_.dataset_path_, train_.file);
  if (test_sample_coeff > 1 || test_sample_coeff < 0) {
    test_sample_coeff = 0;
  }

  train_.strings_ = train_.file.size() * test_sample_coeff;
  if (returnable) {
    for (train_.current_epoch_ = 1; !state_.terminated_ && returnable &&
                                    train_.current_epoch_ <= train_.epochs_;
         ++train_.current_epoch_) {
      DatasetTraining(0, 0);
      // returnable = Test(test_.dataset_path_, 1);
    }
    --train_.current_epoch_;
  }

  state_.under_training_ = false;
  state_.running_ = false;
  return returnable;
}

bool GPerceptron::UploadDataset(string &dataset_path,
                                vector<vector<double>> &file_up) {
  ifstream file(dataset_path);
  bool returnable = false;
  string line;

  size_t iter = 0;
  file_up.push_back(vector<double>());
  if (file.is_open()) {
    while (!getline(file, line, '\n').eof()) {
      LoadLine(line, file_up[iter]);
      file_up.push_back(vector<double>());
      ++iter;
    }
    file_up.pop_back();
    file.close();
    returnable = true;
  } else {
    file_up.clear();
  }

  return returnable;
}

void GPerceptron::LoadLine(string &line, vector<double> &num_line) {
  size_t line_size = line.size();
  size_t file_iter = 2;

  num_line.push_back(stod(line.data(), nullptr) - 1);
  for (size_t i = 0; i < line_size; ++i) {
    while (!IsAsciiNumber(line[file_iter])) {
      ++file_iter;
    }
    num_line.push_back(stod(&line.data()[file_iter], nullptr) / 255);
    while (IsAsciiNumber(line[file_iter])) {
      ++file_iter;
    }
  }
}

void GPerceptron::DatasetTraining(size_t test_chunk_begin,
                                  size_t test_chunk_end) {
  size_t dataset_size = train_.file.size();
  size_t iterator = 0;

  train_.progress_ = 0;
  for (size_t i = 0; !state_.terminated_ && i < dataset_size; ++i) {
    if (IsOutOfArea(iterator, test_chunk_begin, test_chunk_end)) {
      FillInput(train_.file[i]);
      Run();
      Backpropagation();
    }
    train_.progress_ = TrackProgress(iterator + 1, dataset_size);
    ++iterator;
  }
  train_.progress_ = TrackProgress(iterator + 1, dataset_size);
}

bool GPerceptron::IsAsciiNumber(const char sym) {
  return sym >= '0' && sym <= '9';
}

bool GPerceptron::IsInOfArea(size_t line_number, size_t chunk_begin,
                             size_t chunk_end) {
  return line_number >= chunk_begin && line_number <= chunk_end;
}

bool GPerceptron::IsOutOfArea(size_t line_number, size_t chunk_begin,
                              size_t chunk_end) {
  return line_number < chunk_begin || line_number > chunk_end;
}

void GPerceptron::FillInput(vector<double> &num_line) {
  size_t input_size = p_input_->size();

  state_.expected_sym_ = (char)num_line[0];
  for (size_t i = 0; i < input_size; ++i) {
    if (i < num_line.size()) {
      (*p_input_)[i].set_value(num_line[i]);
    } else {
      (*p_input_)[i].set_value(0);
    }
  }
}

size_t GPerceptron::TrackProgress(size_t current, size_t total) {
  return current / (double)total * 100;
}

void GPerceptron::Backpropagation() {
  // int i = layers_->size() - 2;
  // CorrectOutputLayerWeights(*(*layers_)[i], *output_layer_);

  // for (; i > 0; --i) {
  //   CorrectHiddenLayerWeights(*(*layers_)[i - 1], *(*layers_)[i],
  //                             *(*layers_)[i + 1]);
  // }
}

}  // namespace s21