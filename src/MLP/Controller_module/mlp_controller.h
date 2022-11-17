#ifndef SRC_MLP_CONTROLLER_MODULE_MLP_CONTROLLER_H
#define SRC_MLP_CONTROLLER_MODULE_MLP_CONTROLLER_H

#include "../Model_module/mlp_model.h"
using s21::MLPModel;

namespace s21 {

class MLPController {
 public:
  MLPController(MLPModel *model);
  bool Create(Implementation type, size_t layers, string wcfg_path,
              WCFGMode wcfg_mode);
  char Classify(vector<double> *pixels, double *confidence);
  bool SaveWeights(string save_path);
  void RunTraining(string train_dataset, string test_dataset,
                   size_t epochs_or_groups, double learning_rate);

 private:
  MLPModel *model_;
};

}  // namespace s21

#endif  // SRC_MLP_CONTROLLER_MODULE_MLP_CONTROLLER_H
