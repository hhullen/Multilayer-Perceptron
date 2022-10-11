#include "perceptron.h"

#include <iostream>

namespace S21 {

Perceptron::Perceptron(int input_neurons, int output_neurons,
                       int hidden_layers) {
  input_layer_ = new PerceptronLayer();
  SetupDefaultLayers(input_layer_, input_neurons);
  std::cout << input_layer_->get_neurons_amount() << "\n";

  output_layer_ = new PerceptronLayer();
  SetupDefaultLayers(output_layer_, output_neurons);

  hidden_layers_ = new vector<PerceptronLayer *>(hidden_layers);
  for (int i = 0; i < hidden_layers; ++i) {
    int neurons = GetNeuronsToHiddenLayer(hidden_layers, i);
    (*hidden_layers_)[i] = new PerceptronLayer();
    SetupDefaultLayers((*hidden_layers_)[i], neurons);
    std::cout << (*hidden_layers_)[i]->get_neurons_amount() << "\n";
  }
  std::cout << output_layer_->get_neurons_amount() << "\n";
}

Perceptron::~Perceptron() {
  delete input_layer_;
  delete output_layer_;
}

void Perceptron::SetupDefaultLayers(PerceptronLayer *layer, int n) {
  for (int i = 0; i < n; ++i) {
    layer->set_new_neuron(0, 0);
  }
}

int Perceptron::GetNeuronsToHiddenLayer(int layers_amount, int layer_number) {
  return ceil(
      pow(kEXPONENT, -(kDELTA_CONST / (layers_amount + 1) * (layer_number + 1) +
                       kINPUT_LAYER_CONST)) *
      kFACTOR);
}

}  // namespace S21
