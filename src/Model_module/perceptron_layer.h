#ifndef SRC_MODEL_MODULE_PERCEPTRON_LAYER_H
#define SRC_MODEL_MODULE_PERCEPTRON_LAYER_H

#include "../include/matrix/matrix.h"

using S21::Matrix;

namespace S21 {

class PerceptronLayer {
 public:
  enum class LayerType { INPUT, OTHER };
  PerceptronLayer(LayerType is_input_layer, int neurons, int neurons_left = 0) {
    if (is_input_layer == LayerType::OTHER) {
      layer_ = new Matrix(neurons, neurons_left);
    }
    neurons_ = new Matrix(neurons, 1);
  }

  ~PerceptronLayer() {
    delete neurons_;
    delete layer_;
  }

  void set_layer(int neurons, int neurons_left) {
    if (layer_) {
      layer_->set_rows(neurons);
      layer_->set_cols(neurons_left);
    }
    neurons_->set_rows(neurons);
    neurons_->set_cols(1);
  }

 private:
  Matrix *layer_;
  Matrix *neurons_;
};

}  // namespace S21

#endif  // SRC_MODEL_MODULE_PERCEPTRON_LAYER_H
