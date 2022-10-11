#ifndef SRC_MODEL_MODULE_PERCEPTRON_H
#define SRC_MODEL_MODULE_PERCEPTRON_H

#include "perceptron_layer.h"

namespace S21 {

class Perceptron {
 public:
  Perceptron(int hidden);
  ~Perceptron();

 private:
  PerceptronLayer *input_layer_;
  PerceptronLayer *output_layer_;
  vector<PerceptronLayer> *hidden_layers_;
};

}  // namespace S21

#endif  // SRC_MODEL_MODULE_PERCEPTRON_H
