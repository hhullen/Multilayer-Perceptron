#include "perceptron.h"

#include <iostream>

namespace s21 {

Perceptron::Perceptron(int input_neurons, int hidden_layers,
                       int output_neurons) {
  layers_ = new vector<PerceptronLayer *>(hidden_layers + 2);
  (*layers_)[0] = new PerceptronLayer(LayerType::INPUT, input_neurons);
  int prev_neurons_amount = input_neurons;

  ++hidden_layers;
  for (int i = 1; i < hidden_layers; ++i) {
    // int neurons = GetNeuronsToHiddenLayer(hidden_layers, i);
    int neurons = 2;
    (*layers_)[i] =
        new PerceptronLayer(LayerType::OTHER, neurons, prev_neurons_amount);
    prev_neurons_amount = neurons;
  }

  (*layers_)[hidden_layers] = new PerceptronLayer(
      LayerType::OTHER, output_neurons, prev_neurons_amount);
  input_layer_ = (*layers_).front();
  output_layer_ = (*layers_).back();
}

Perceptron::~Perceptron() {
  delete input_layer_;
  delete output_layer_;
}

void Perceptron::FillWithRandom() {
  for (size_t i = 1; i < layers_->size(); ++i) {
    FillMatrixRandom(*(*layers_)[i]->get_weights());
  }
}

void Perceptron::FillMatrixRandom(Matrix &matrix) {
  for (int i = 0; i < matrix.get_rows(); ++i) {
    for (int j = 0; j < matrix.get_cols(); ++j) {
      matrix(i, j) = fmod(rand(), kRANDOM_FACTOR) / kRANDOM_FACTOR;
    }
  }
}

void Perceptron::ClearWeights() {
  for (size_t i = 1; i < layers_->size(); ++i) {
    FillMatrixZero(*(*layers_)[i]->get_weights());
  }
}

void Perceptron::FillMatrixZero(Matrix &matrix) {
  for (int i = 0; i < matrix.get_rows(); ++i) {
    for (int j = 0; j < matrix.get_cols(); ++j) {
      matrix(i, j) = 0.0;
    }
  }
}

bool Perceptron::SaveConfig(const string &path) {
  ofstream file(path, ios_base::binary & ios_base::app);
  bool returnable = false;

  if (file.is_open()) {
    SaveLayers(file);
    returnable = true;
    file.close();
  }

  return returnable;
}

void Perceptron::SaveLayers(ofstream &file) {
  Matrix *p_weights, *p_neurons;
  for (size_t i = 1; i < layers_->size(); ++i) {
    p_weights = (*layers_)[i]->get_weights();
    p_neurons = (*layers_)[i]->get_neurons();
    WriteMAtrixSize(file, *p_weights);
    WriteMatrix(file, *p_weights);
    WriteMatrix(file, *p_neurons);
  }
}

void Perceptron::WriteMAtrixSize(ofstream &file, Matrix &matrix) {
  int rows = matrix.get_rows();
  int cols = matrix.get_cols();
  file.write((char *)&rows, sizeof(int));
  file.write((char *)&cols, sizeof(int));
}

void Perceptron::WriteMatrix(ofstream &file, Matrix &matrix) {
  for (int i = 0; i < matrix.get_rows(); ++i) {
    for (int j = 0; j < matrix.get_cols(); ++j) {
      double value = matrix(i, j);
      file.write((char *)&value, sizeof(double));
    }
  }
}

bool Perceptron::UploadConfig(const string &path) {
  ifstream file(path, ios_base::binary);
  bool returnable = false;

  if (file.is_open() && UploadLayers(file)) {
    returnable = true;
    file.close();
  }

  return returnable;
}

bool Perceptron::UploadLayers(ifstream &file) {
  Matrix *p_weights, *p_neurons;
  int rows, cols, frows, fcols;
  bool returnable = true;

  for (size_t i = 1; i < layers_->size() && returnable; ++i) {
    p_weights = (*layers_)[i]->get_weights();
    p_neurons = (*layers_)[i]->get_neurons();
    GetMatrixAndDataSizes(*p_weights, &rows, &cols, file, &frows, &fcols);

    if (rows == frows && cols == fcols && ReadMatrix(file, *p_weights) &&
        ReadMatrix(file, *p_neurons)) {
      returnable = true;
    } else {
      returnable = false;
    }
  }

  return returnable;
}

bool Perceptron::ReadMatrix(ifstream &file, Matrix &matrix) {
  int i = 0, j = matrix.get_cols();
  bool returnable = false;
  double value;

  for (; i < matrix.get_rows() && j == matrix.get_cols(); ++i) {
    j = 0;
    for (; j < matrix.get_cols() && file.read((char *)&value, sizeof(double));
         ++j) {
      matrix(i, j) = value;
    }
  }
  if (i == matrix.get_rows() && j == matrix.get_cols()) {
    returnable = true;
  }

  return returnable;
}

void Perceptron::GetMatrixAndDataSizes(Matrix &matrix, int *rows, int *cols,
                                       ifstream &file, int *frows, int *fcols) {
  *rows = matrix.get_rows();
  *cols = matrix.get_cols();
  file.read((char *)frows, sizeof(int));
  file.read((char *)fcols, sizeof(int));
}

int Perceptron::GetNeuronsToHiddenLayer(int layers_amount, int layer_number) {
  return ceil(
      pow(kEXPONENT, -(kDELTA_CONST / (layers_amount + 1) * (layer_number + 1) +
                       kINPUT_LAYER_CONST)) *
      kFACTOR);
}

void Perceptron::PRINT() {
  std::cout << "PRINT\n";
  for (size_t i = 1; i < layers_->size(); ++i) {
    Matrix &matrix = *(*layers_)[i]->get_weights();
    for (int i = 0; i < matrix.get_rows(); ++i) {
      for (int j = 0; j < matrix.get_cols(); ++j) {
        std::cout << matrix(i, j) << " ";
      }
      std::cout << "\n";
    }
    std::cout << "\n";
  }
}

}  // namespace s21
