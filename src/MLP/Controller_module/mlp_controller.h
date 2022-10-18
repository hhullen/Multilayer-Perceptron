#ifndef SRC_MLP_CONTROLLER_MODULE_MLP_CONTROLLER_H
#define SRC_MLP_CONTROLLER_MODULE_MLP_CONTROLLER_H

#include "../Model_module/perceptron.h"
using s21::Perceptron;

namespace s21 {

class MLPController {
 public:
  MLPController(Perceptron *model);

 private:
};

}  // namespace s21

#endif  // SRC_MLP_CONTROLLER_MODULE_MLP_CONTROLLER_H