#ifndef SRC_MLP_MODEL_MODULE_MATRIX_IMPLEMENTATION_PERCEPTRON_LAYER_H
#define SRC_MLP_MODEL_MODULE_MATRIX_IMPLEMENTATION_PERCEPTRON_LAYER_H

#include "../../include/matrix_lib/matrix.h"

using hhullen::Matrix;

namespace s21 {

enum class LayerType { INPUT, OTHER };

class PerceptronLayer {
 public:
  PerceptronLayer(LayerType is_input_layer, int neurons, int neurons_left = 0) {
    if (is_input_layer == LayerType::OTHER) {
      weights_gradient_ = new Matrix(neurons, neurons_left);
      layer_ = new Matrix(neurons, neurons_left);
      errors_ = new Matrix(neurons, 1);
    } else if (is_input_layer == LayerType::INPUT) {
      weights_gradient_ = nullptr;
      errors_ = nullptr;
      layer_ = nullptr;
    }
    neurons_ = new Matrix(neurons, 1);
  }

  ~PerceptronLayer() {
    if (weights_gradient_) {
      weights_gradient_->~Matrix();
      delete weights_gradient_;
      weights_gradient_ = nullptr;
    }
    if (neurons_) {
      neurons_->~Matrix();
      delete neurons_;
      neurons_ = nullptr;
    }
    if (errors_) {
      errors_->~Matrix();
      delete errors_;
      errors_ = nullptr;
    }
    if (layer_) {
      layer_->~Matrix();
      delete layer_;
      layer_ = nullptr;
    }
  }

  Matrix *get_d_weights() { return weights_gradient_; }
  Matrix *get_neurons() { return neurons_; }
  Matrix *get_weights() { return layer_; }
  Matrix *get_errors() { return errors_; }

 private:
  Matrix *weights_gradient_;
  Matrix *neurons_;
  Matrix *errors_;
  Matrix *layer_;
};

}  // namespace s21

#endif  // SRC_MLP_MODEL_MODULE_MATRIX_IMPLEMENTATION_PERCEPTRON_LAYER_H
