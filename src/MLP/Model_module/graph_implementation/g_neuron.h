#ifndef SRC_MLP_MODEL_MODULE_GRAPH_IMPLEMENTATION_G_NEURON_H
#define SRC_MLP_MODEL_MODULE_GRAPH_IMPLEMENTATION_G_NEURON_H

#include <vector>

using std::vector;

namespace s21 {

class GNeuron {
 public:
  GNeuron() : error_(0), value_(0) {
    rights_.clear();
    lefts_.clear();
    weights_.clear();
  }

  ~GNeuron() {
    rights_.clear();
    lefts_.clear();
    weights_.clear();
  }

  void ConnectL(GNeuron *neuron) {
    lefts_.push_back(neuron);
    weights_.push_back(0);
  }

  void ConnectR(GNeuron *neuron) { rights_.push_back(neuron); }

  vector<double> &get_weights() { return weights_; }
  double get_value() { return value_; }
  double get_value_l(size_t index) { return lefts_[index]->get_value(); }
  double get_value_r(size_t index) { return rights_[index]->get_value(); }
  GNeuron *get_neuron_l(size_t index) { return lefts_[index]; }
  GNeuron *get_neuron_r(size_t index) { return rights_[index]; }
  vector<GNeuron *> *get_layer_l() { return &lefts_; }
  vector<GNeuron *> *get_layer_r() { return &rights_; }
  double get_error() { return error_; }

  void set_value(double value) { value_ = value; }
  void set_error(double value) { error_ = value; }

 private:
  double error_;
  double value_;
  vector<GNeuron *> rights_;
  vector<GNeuron *> lefts_;
  vector<double> weights_;
};

}  // namespace s21

#endif  // SRC_MLP_MODEL_MODULE_GRAPH_IMPLEMENTATION_G_NEURON_H
