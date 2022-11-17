#ifndef SRC_MODEL_MODULE_PERCEPTRON_H
#define SRC_MODEL_MODULE_PERCEPTRON_H

#include <cmath>
#include <fstream>
#include <map>
#include <string>
#include <thread>
#include <vector>

#include "perceptron_layer.h"
using s21::PerceptronLayer;
using std::ceil;
using std::getline;
using std::ifstream;
using std::ios_base;
using std::map;
using std::ofstream;
using std::pow;
using std::printf;
using std::rand;
using std::stod;
using std::string;
using std::thread;
using std::vector;

namespace s21 {

const double kEXPONENT = 2.71828182845904523536028747135266250;
const double kINPUT_LAYER_CONST = 4.33769082;
const double kDELTA_CONST = 3.40634218;
const double kRANDOM_FACTOR = 4096.0;
const int kFACTOR = 60000;
const int kHIDDEN_NEURONS = 130;

class Perceptron {
 public:
  Perceptron(int input_neurons, int hidden_layers, int output_neurons);
  ~Perceptron();

  bool Train(const string &learn_dataset_path, const string &test_dataset_path,
             double test_sample_coeff);
  bool CrossValidation(const string &learn_dataset_path, size_t groups);
  bool Test(const string &dataset_path, double test_sample_coeff);
  bool UploadConfig(const string &path);
  bool SaveConfig(const string &path);
  void FillWithRandom();
  bool IsRunning();
  void Terminate();
  void Run();

  bool set_input_neurons(Matrix &matrix);
  void set_epochs_amount(size_t epochs);
  size_t get_learning_progress();
  size_t get_testing_progress();
  Matrix *get_output_neurons();

 private:
  vector<PerceptronLayer *> *layers_;
  PerceptronLayer *output_layer_;
  PerceptronLayer *input_layer_;
  bool running_;

  bool terminated_;
  size_t learning_progress_percent_;
  size_t learning_dataset_lines_;
  string learning_dataset_path_;
  size_t learning_strings_;
  size_t learning_start_;
  double learning_rate_;
  char expected_sym_;
  char output_sym_;
  double answer_confidence_;
  size_t epochs_;

  size_t in_a_row = 0;  // TEMP!!!

  size_t testing_progress_percent_;
  size_t testing_dataset_lines_;
  string testing_dataset_path_;
  size_t testing_strings_;

  map<size_t, double> precision_;
  map<size_t, double> f_measure_;
  vector<double> avg_accuracy_;
  map<size_t, double> recall_;

  size_t cross_testing_begin_;
  size_t cross_testing_end_;

  void FillMatrixRandom(Matrix &matrix);
  int GetNeuronsToHiddenLayer(int layers_amount, int layer_number);
  void SaveLayers(ofstream &file);
  void WriteMAtrixSize(ofstream &file, Matrix &matrix);
  void WriteMatrix(ofstream &file, Matrix &matrix);
  bool UploadLayers(ifstream &file);
  bool ReadMatrix(ifstream &file, Matrix &matrix);
  void GetMatrixAndDataSizes(Matrix &matrix, int *rows, int *cols,
                             ifstream &file, int *frows, int *fcols);
  void Activate(Matrix &matrix);
  double Sigmoid(const double value);
  double SigmoidDerivative(const double value);
  char GetAnswer();
  bool CalculateFile(string &dataset_path, size_t *dataset_lines);
  void DatasetLearning(size_t test_chunk_begin, size_t test_chunk_end);
  size_t TrackProgress(size_t current, size_t total);
  void FillInput(string &line);
  bool IsAsciiNumber(const char sym);
  bool IsInOfArea(size_t line_number, size_t chunk_begin, size_t chunk_end);
  bool IsOutOfArea(size_t line_number, size_t chunk_begin, size_t chunk_end);
  void Backpropagation();
  void CorrectOutputLayer();
  void CorrectOutputLayerWeights(PerceptronLayer &layer_l,
                                 PerceptronLayer &layer);
  void CorrectHiddenLayerWeights(PerceptronLayer &layer_l,
                                 PerceptronLayer &layer,
                                 PerceptronLayer &layer_r);
  void GetOutputLayerErrors(const Matrix &neurons, Matrix &errors);
  void GetHiddenLayerErrors(const Matrix &weights_r, const Matrix &errors_r,
                            const Matrix &neurons, Matrix &errors);
  void CalculateGradient(const Matrix &neurons_l, const Matrix &errors,
                         Matrix &d_weights);
  void RunTesting(ifstream &file, size_t test_chunk_begin,
                  size_t test_chunk_end);
  void UpdateMetrics(size_t &right_answers, map<size_t, size_t> &letters);
  void FinishMetrics(size_t &right_answers, map<size_t, size_t> &letters);
  void RunCrossValidating(size_t groups);
  double FMeasure(double precision, double recall);
};

}  // namespace s21

#endif  // SRC_MODEL_MODULE_PERCEPTRON_H
