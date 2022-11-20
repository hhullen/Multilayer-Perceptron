#ifndef SRC_MLP_MODEL_MODULE_GRAPH_IMPLEMENTATION_G_NEURON_H
#define SRC_MLP_MODEL_MODULE_GRAPH_IMPLEMENTATION_G_NEURON_H

#include <vector>

using std::vector;

namespace s21 {

class GNeuron {
 public:
  GNeuron() : errors_(0) {
    weights_gradients_.clear();
    rights_.clear();
    lefts_.clear();
    weights_.clear();
  }

  ~GNeuron() {
    weights_gradients_.clear();
    rights_.clear();
    lefts_.clear();
    weights_.clear();
  }

  void ConnectL(GNeuron *neuron) { lefts_.push_back(neuron); }
  void ConnectR(GNeuron *neuron) { rights_.push_back(neuron); }

 private:
  double errors_;
  vector<double> weights_gradients_;
  vector<GNeuron *> rights_;
  vector<GNeuron *> lefts_;
  vector<double> weights_;
};

}  // namespace s21

#endif  // SRC_MLP_MODEL_MODULE_GRAPH_IMPLEMENTATION_G_NEURON_H