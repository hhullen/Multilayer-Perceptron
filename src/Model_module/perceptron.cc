#include "perceptron.h"

namespace S21 {

Perceptron::Perceptron(int hidden) {
  input_layer_ = new PerceptronLayer();
  output_layer_ = new PerceptronLayer();
  hidden_layers_ = new vector<PerceptronLayer>[hidden];
}

Perceptron::~Perceptron() {
  delete input_layer_;
  delete output_layer_;
  //   delete hidden_layers_;
}

}  // namespace S21
