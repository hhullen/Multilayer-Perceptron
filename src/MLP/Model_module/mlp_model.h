#ifndef SRC_MODEL_MODULE_MLP_MODEL_H
#define SRC_MODEL_MODULE_MLP_MODEL_H

#include "matrix_implementation/perceptron.h"
using s21::Perceptron;

namespace s21 {

const int kNEURONS_IN = 784;
const int kNEURONS_OUT = 26;

enum class Implementation { MATRIX, GRAPH };
enum class WCFGMode { RANDOM, FILE };

class MLPModel {
 public:
  MLPModel();

  bool CreatePerceptron(Implementation type, size_t layers, string wcfg_path,
                        WCFGMode wcfg_mode);

 private:
  Perceptron *matrix_mlp_;
  Implementation implementation_;
  WCFGMode wcfg_mode_;
};

}  // namespace s21

#endif  // SRC_MODEL_MODULE_MLP_MODEL_H
