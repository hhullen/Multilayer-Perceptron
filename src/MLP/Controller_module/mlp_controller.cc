#include "mlp_controller.h"

namespace s21 {

MLPController::MLPController(MLPModel *model) : model_(model) {}

bool MLPController::Create(Implementation type, size_t layers, string wcfg_path,
                           WCFGMode wcfg_mode) {
  return model_->CreatePerceptron(type, layers, wcfg_path, wcfg_mode);
}

char MLPController::Classify(vector<double> *pixels, double *confidence) {
  return model_->Classify(pixels, confidence);
}

bool MLPController::SaveWeights(string save_path) {
  return model_->SaveWeights(save_path);
}

void MLPController::RunTraining(string train_dataset, string test_dataset,
                                size_t epochs_or_groups, double learning_rate) {
  model_->RunTraining(train_dataset, test_dataset, epochs_or_groups,
                      learning_rate);
}

void MLPController::RunCrossValidation(string dataset_path, size_t groups,
                                       double learning_rate) {
  model_->RunCrossValidation(dataset_path, groups, learning_rate);
}

void MLPController::UpdateLearningRate(double learning_rate) {
  model_->UpdateLearningRate(learning_rate);
}

void MLPController::UpdateTrainingState(size_t *current_epoch,
                                        vector<double> **avg_accuracy,
                                        size_t *training_progress,
                                        size_t *testing_progress,
                                        bool *is_running) {
  model_->UpdateTrainingState(current_epoch, avg_accuracy, training_progress,
                              testing_progress, is_running);
}

void MLPController::RunTesting(string test_dataset, double coeff) {
  model_->RunTesting(test_dataset, coeff);
}

void MLPController::UpdateTestingState(size_t *testing_progress,
                                       bool *is_running) {
  model_->UpdateTestingState(testing_progress, is_running);
}

void MLPController::TerminateProcess() { model_->TerminateProcess(); }

}  // namespace s21