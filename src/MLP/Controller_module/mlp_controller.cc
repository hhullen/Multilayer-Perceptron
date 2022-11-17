#include "mlp_controller.h"

namespace s21 {

MLPController::MLPController(MLPModel* model) : model_(model) {}

bool MLPController::Create(Implementation type, size_t layers, string wcfg_path,
                           WCFGMode wcfg_mode) {
  return model_->CreatePerceptron(type, layers, wcfg_path, wcfg_mode);
}

char MLPController::Classify(vector<double>* pixels, double* confidence) {
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

}  // namespace s21