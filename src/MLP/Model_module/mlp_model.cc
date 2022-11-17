#include "mlp_model.h"

namespace s21 {

MLPModel::MLPModel() : matrix_mlp_(nullptr) {}

bool MLPModel::CreatePerceptron(Implementation type, size_t layers,
                                string wcfg_path, WCFGMode wcfg_mode) {
  bool returnable = false;

  implementation_ = type;
  if (implementation_ == Implementation::MATRIX) {
    RemoveObject(matrix_mlp_);
    matrix_mlp_ = new Perceptron(kNEURONS_IN, layers, kNEURONS_OUT);
    returnable = ConfigurateObject(matrix_mlp_, wcfg_mode, wcfg_path);
  } else if (implementation_ == Implementation::GRAPH) {
    std::cout << "graph implementation creation\n";
  }

  return returnable;
}

char MLPModel::Classify(vector<double> *pixels, double *confidence) {
  char returnable;

  if (implementation_ == Implementation::MATRIX) {
    Matrix input(pixels->size(), 0);
    CopyData(*pixels, input);
    matrix_mlp_->set_input_neurons(input);
    matrix_mlp_->Run();
    returnable = matrix_mlp_->get_recognized_letter();
  } else if (implementation_ == Implementation::GRAPH) {
    std::cout << "graph implementation classify\n";
  }

  return returnable;
}

bool MLPModel::SaveWeights(string save_path) {
  bool returnable = false;

  if (implementation_ == Implementation::MATRIX) {
    returnable = matrix_mlp_->SaveConfig(save_path);
  } else if (implementation_ == Implementation::GRAPH) {
    std::cout << "graph implementation saving\n";
  }

  return returnable;
}

void MLPModel::RemoveObject(Perceptron *obj) {
  if (obj) {
    obj->Terminate();
    delete obj;
  }
}

bool MLPModel::ConfigurateObject(Perceptron *obj, WCFGMode wcfg_mode,
                                 string wcfg_path) {
  bool returnable = false;

  if (wcfg_mode == WCFGMode::FILE) {
    returnable = obj->UploadConfig(wcfg_path);
  } else if (wcfg_mode == WCFGMode::RANDOM) {
    obj->FillWithRandom();
    returnable = true;
  }

  return returnable;
}

void MLPModel::CopyData(vector<double> &pixels, Matrix &input) {
  for (size_t i = 0; i < input.get_rows(); ++i) {
    input(i, 0) = pixels[i];
  }
}

}  // namespace s21
