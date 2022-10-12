#include "perceptron.h"

#include <iostream>

namespace S21 {

Perceptron::Perceptron(int input_neurons, int output_neurons,
                       int hidden_layers) {
  input_layer_ =
      new PerceptronLayer(PerceptronLayer::LayerType::INPUT, input_neurons);

  hidden_layers_ = new vector<PerceptronLayer *>(hidden_layers);
  int prev_neurons_amount = input_neurons;
  for (int i = 0; i < hidden_layers; ++i) {
    int neurons = GetNeuronsToHiddenLayer(hidden_layers, i);
    (*hidden_layers_)[i] = new PerceptronLayer(
        PerceptronLayer::LayerType::OTHER, neurons, prev_neurons_amount);
    prev_neurons_amount = neurons;
  }

  output_layer_ = new PerceptronLayer(PerceptronLayer::LayerType::OTHER,
                                      output_neurons, prev_neurons_amount);
}

Perceptron::~Perceptron() {
  delete input_layer_;
  delete output_layer_;
}

int Perceptron::GetNeuronsToHiddenLayer(int layers_amount, int layer_number) {
  return ceil(
      pow(kEXPONENT, -(kDELTA_CONST / (layers_amount + 1) * (layer_number + 1) +
                       kINPUT_LAYER_CONST)) *
      kFACTOR);
}

}  // namespace S21
