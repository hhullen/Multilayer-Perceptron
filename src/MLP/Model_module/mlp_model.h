#ifndef SRC_MODEL_MODULE_MLP_MODEL_H
#define SRC_MODEL_MODULE_MLP_MODEL_H

#include "perceptron.h"
using s21::Perceptron;

namespace s21 {

class MLPModel {
 public:
  MLPModel() { matrix_mlp_ = nullptr; }

 private:
  Perceptron *matrix_mlp_;
};

}  // namespace s21

#endif  // SRC_MODEL_MODULE_MLP_MODEL_H