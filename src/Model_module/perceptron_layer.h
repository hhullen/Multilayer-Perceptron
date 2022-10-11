#ifndef SRC_MODEL_MODULE_PERCEPTRON_LAYER_H
#define SRC_MODEL_MODULE_PERCEPTRON_LAYER_H

#include <vector>
using std::vector;

namespace S21 {

class PerceptronLayer {
 public:
  PerceptronLayer() { neurons_ = new vector<Neuron *>; }
  ~PerceptronLayer() { delete neurons_; }

  void setup_new_neuron(double value, double weight) {
    neurons_->push_back(new Neuron());
    neurons_->back()->value = value;
    neurons_->back()->weight = weight;
  }

  double get_value(int i) { return neurons_->at(i)->value; }

  double get_weight(int i) { return neurons_->at(i)->weight; }

 private:
  struct Neuron {
    double value;
    double weight;
  };
  vector<Neuron *> *neurons_;
  vector<Neuron> gg;
};

}  // namespace S21

#endif  // SRC_MODEL_MODULE_PERCEPTRON_LAYER_H