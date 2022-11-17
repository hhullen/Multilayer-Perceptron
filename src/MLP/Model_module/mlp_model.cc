#include "mlp_model.h"

namespace s21 {

MLPModel::MLPModel() : matrix_mlp_(nullptr) {}

bool MLPModel::CreatePerceptron(Implementation type, size_t layers,
                                string wcfg_path, WCFGMode wcfg_mode) {
  bool returnable = false;

  implementation_ = type;
  if (implementation_ == Implementation::MATRIX) {
    matrix_mlp_ = new Perceptron(kNEURONS_IN, layers, kNEURONS_OUT);
    if (wcfg_mode == WCFGMode::FILE) {
      returnable = matrix_mlp_->UploadConfig(wcfg_path);
    } else if (wcfg_mode == WCFGMode::RANDOM) {
      matrix_mlp_->FillWithRandom();
      returnable = true;
    }
  } else if (implementation_ == Implementation::GRAPH) {
    std::cout << "graph implementation\n";
  }

  return returnable;
}

}  // namespace s21
