#ifndef SRC_MODEL_MODULE_PERCEPTRON_H
#define SRC_MODEL_MODULE_PERCEPTRON_H

#include <cmath>
#include <fstream>
#include <string>
#include <vector>

#include "perceptron_layer.h"
using s21::PerceptronLayer;
using std::ceil;
using std::ifstream;
using std::ios_base;
using std::ofstream;
using std::pow;
using std::rand;
using std::string;
using std::vector;

namespace s21 {
const double kINPUT_LAYER_CONST = 4.33769082;
const double kDELTA_CONST = 3.40634218;
const double kEXPONENT = 2.71828182845904523536028747135266250;
const int kFACTOR = 60000;
const double kRANDOM_FACTOR = 4096.0;

class Perceptron {
 public:
  Perceptron(int input_neurons, int hidden_layers, int output_neurons);
  ~Perceptron();

  bool SaveConfig(const string &path);
  bool UploadConfig(const string &path);
  void FillWithRandom();
  bool set_input_neurons(Matrix &matrix);
  void Run();
  void Activate(Matrix &matrix);
  double Sigmoid(const double &value);
  Matrix *get_output_neurons();

  void PRINT();  // !!!

 private:
  PerceptronLayer *input_layer_;
  PerceptronLayer *output_layer_;
  vector<PerceptronLayer *> *layers_;

  void FillMatrixRandom(Matrix &matrix);
  int GetNeuronsToHiddenLayer(int layers_amount, int layer_number);
  void SaveLayers(ofstream &file);
  void WriteMAtrixSize(ofstream &file, Matrix &matrix);
  void WriteMatrix(ofstream &file, Matrix &matrix);
  bool UploadLayers(ifstream &file);
  bool ReadMatrix(ifstream &file, Matrix &matrix);
  void GetMatrixAndDataSizes(Matrix &matrix, int *rows, int *cols,
                             ifstream &file, int *frows, int *fcols);
};

}  // namespace s21

#endif  // SRC_MODEL_MODULE_PERCEPTRON_H
