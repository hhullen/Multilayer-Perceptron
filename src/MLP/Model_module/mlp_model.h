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
  char Classify(vector<double> *pixels, *double confidence);

 private:
  Perceptron *matrix_mlp_;
  Implementation implementation_;
  WCFGMode wcfg_mode_;

  void RemoveObject(Perceptron *obj);
  bool ConfigurateObject(Perceptron *obj, WCFGMode wcfg_mode, string wcfg_path);
  void CopyData(vector<double> &pixels, Matrix &input);
};

}  // namespace s21

#endif  // SRC_MODEL_MODULE_MLP_MODEL_H
