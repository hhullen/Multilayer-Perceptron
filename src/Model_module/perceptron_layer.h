#ifndef SRC_MODEL_MODULE_PERCEPTRON_LAYER_H
#define SRC_MODEL_MODULE_PERCEPTRON_LAYER_H

#include <vector>

#include "../include/matrix/matrix.h"

using S21::S21Matrix;
using std::vector;

namespace S21 {

class PerceptronLayer {
 public:
  // PerceptronLayer() { neurons_ = new vector<Neuron *>; }
  // ~PerceptronLayer() { delete neurons_; }

  // void set_new_neuron(double value, double weight) {
  //   neurons_->push_back(new Neuron());
  //   neurons_->back()->value = value;
  //   neurons_->back()->weight = weight;
  // }

  // double get_value(int i) { return (*neurons_)[i]->value; }
  // double get_weight(int i) { return (*neurons_)[i]->weight; }
  // int get_neurons_amount() { return neurons_->size(); }

 private:
  // struct Neuron {
  //   double value;
  //   double weight;
  // };
  // vector<Neuron *> *neurons_;
  S21Matrix layer_;
  S21Matrix neurons_;
};

}  // namespace S21

#endif  // SRC_MODEL_MODULE_PERCEPTRON_LAYER_H
