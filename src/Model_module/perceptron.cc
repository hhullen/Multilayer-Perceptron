#include "perceptron.h"

#include <iostream>

namespace S21 {

Perceptron::Perceptron(int input_neurons, int hidden_layers,
                       int output_neurons) {
  input_layer_ =
      new PerceptronLayer(PerceptronLayer::LayerType::INPUT, input_neurons);

  hidden_layers_ = new vector<PerceptronLayer *>(hidden_layers);
  int prev_neurons_amount = input_neurons;
  for (int i = 0; i < hidden_layers; ++i) {
    int neurons = GetNeuronsToHiddenLayer(hidden_layers, i);
    (*hidden_layers_)[i] = new PerceptronLayer(
        PerceptronLayer::LayerType::OTHER, neurons, prev_neurons_amount);
    prev_neurons_amount = neurons;
  }

  output_layer_ = new PerceptronLayer(PerceptronLayer::LayerType::OTHER,
                                      output_neurons, prev_neurons_amount);
}

Perceptron::~Perceptron() {
  delete input_layer_;
  delete output_layer_;
}

bool Perceptron::SaveConfig(const string &path) {
  ofstream file(path, ios_base::binary & ios_base::app);
  bool returnable = false;

  if (file.is_open()) {
    SaveHiddenLayers(file);
    SaveOutputLayer(file);
    returnable = true;
    file.close();
  }

  return returnable;
}

void Perceptron::SaveHiddenLayers(ofstream &file) {
  Matrix *p_weights, *p_neurons;
  for (size_t i = 0; i < hidden_layers_->size(); ++i) {
    p_weights = (*hidden_layers_)[i]->get_weights();
    p_neurons = (*hidden_layers_)[i]->get_neurons();
    int rows = p_weights->get_rows(), cols = p_weights->get_cols();
    file.write((char *)&rows, sizeof(int));
    file.write((char *)&cols, sizeof(int));
    WriteMatrix(file, *p_weights);
    WriteMatrix(file, *p_neurons);
  }
}

void Perceptron::SaveOutputLayer(ofstream &file) {
  Matrix *p_weights = output_layer_->get_weights();
  int rows = p_weights->get_rows(), cols = p_weights->get_cols();
  file.write((char *)&rows, sizeof(int));
  file.write((char *)&cols, sizeof(int));
  WriteMatrix(file, *p_weights);
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

  if (file.is_open() && UploadHiddenLayers(file) && UploadOutputLayer(file)) {
    returnable = true;
    file.close();
  }

  return returnable;
}

bool Perceptron::UploadHiddenLayers(ifstream &file) {
  Matrix *p_weights, *p_neurons;
  int rows, cols, frows, fcols;
  bool returnable = true;

  for (size_t i = 0; i < hidden_layers_->size() && returnable; ++i) {
    p_weights = (*hidden_layers_)[i]->get_weights();
    p_neurons = (*hidden_layers_)[i]->get_neurons();
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

bool Perceptron::UploadOutputLayer(ifstream &file) {
  Matrix *p_weights = output_layer_->get_weights();
  int rows, cols, frows, fcols;
  bool returnable = true;

  GetMatrixAndDataSizes(*p_weights, &rows, &cols, file, &frows, &fcols);
  if (rows == frows && cols == fcols) {
    returnable = ReadMatrix(file, *p_weights);
  } else {
    returnable = false;
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

}  // namespace S21
