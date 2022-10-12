#ifndef SRC_MODEL_MODULE_PERCEPTRON_H
#define SRC_MODEL_MODULE_PERCEPTRON_H

#include <cmath>

#include "container/vector.h"
#include "perceptron_layer.h"
using S21::PerceptronLayer;
using S21::vector;
using std::ceil;
using std::pow;

namespace S21 {

const double kINPUT_LAYER_CONST = 4.33769082;
const double kDELTA_CONST = 3.40634218;
const double kEXPONENT = 2.71828182845904523536028747135266250;
const int kFACTOR = 60000;

class Perceptron {
 public:
  Perceptron(int input_neurons, int hidden_neurons, int output_neurons);
  ~Perceptron();

 private:
  PerceptronLayer *input_layer_;
  PerceptronLayer *output_layer_;
  vector<PerceptronLayer *> *hidden_layers_;

  int GetNeuronsToHiddenLayer(int layers_amount, int layer_number);
};

}  // namespace S21

#endif  // SRC_MODEL_MODULE_PERCEPTRON_H
