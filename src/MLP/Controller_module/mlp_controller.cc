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

}  // namespace s21