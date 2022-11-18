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
  void RunCrossValidation(string dataset_path, size_t groups,
                          double learning_rate);
  void UpdateLearningRate(double learning_rate);
  void UpdateTrainingState(size_t *current_epoch, vector<double> **avg_accuracy,
                           size_t *training_progress, size_t *testing_progress,
                           bool *is_running);
  void RunTesting(string test_dataset, double coeff);
  void UpdateTestingState(size_t *testing_progress, bool *is_running);
  void UpdateMetrics(vector<map<size_t, double>> &metrics, size_t *correct,
                     size_t *all, double *avg_accuracy);
  void TerminateProcess();

 private:
  MLPModel *model_;
};

}  // namespace s21

#endif  // SRC_MLP_CONTROLLER_MODULE_MLP_CONTROLLER_H
