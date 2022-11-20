#include "g_perceptron.h"

namespace s21 {

GPerceptron::GPerceptron(int input_neurons, int hidden_layers,
                         int output_neurons) {
  state_.answer_confidence_ = 0;
  state_.expected_sym_ = 0;
  state_.output_sym_ = 0;
  state_.running_ = false;
  state_.terminated_ = false;
  state_.under_training_ = false;
  train_.current_epoch_ = 0;
  train_.dataset_lines_ = 0;
  train_.dataset_path_ = "";
  train_.epochs_ = 5;
  train_.progress_ = 0;
  train_.rate_ = 0;
  train_.start_ = 0;
  train_.strings_ = 0;
  test_.dataset_lines_ = 0;
  test_.dataset_path_ = "";
  test_.progress_ = 0;
  test_.strings_ = 0;
  metric_.all_answers_ = 0;
  metric_.right_answers_ = 0;
  metric_.avg_accuracy_.clear();
  metric_.f_measure_.clear();
  metric_.letters_.clear();
  metric_.precision_.clear();
  metric_.recall_.clear();
  cross_v_.begin_ = 0;
  cross_v_.end_ = 0;

  ConfigurateSize(input_neurons, hidden_layers, output_neurons);
  ConnectLayers();
  p_input_ = &layers_.front();
  p_output_ = &layers_.back();
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

}  // namespace s21