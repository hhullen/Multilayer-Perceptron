#ifndef SRC_MLP_MODEL_MODULE_GRAPH_IMPLEMENTATION_G_PERCEPTRON_H
#define SRC_MLP_MODEL_MODULE_GRAPH_IMPLEMENTATION_G_PERCEPTRON_H

#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

#include "../const.h"
#include "g_neuron.h"

using s21::GNeuron;
using std::ceil;
using std::ifstream;
using std::ios_base;
using std::map;
using std::ofstream;
using std::pow;
using std::rand;
using std::stod;
using std::string;
using std::to_string;

namespace s21 {

class GPerceptron {
 public:
  GPerceptron(int input_neurons, int hidden_layers, int output_neurons);
  ~GPerceptron();

  bool Train(const string &train_dataset_path, const string &test_dataset_path,
             double test_sample_coeff);
  bool CrossValidation(const string &train_dataset_path, size_t groups);
  bool Test(const string &dataset_path, double test_sample_coeff);
  bool UploadConfig(const string &path);
  bool SaveConfig(const string &path);
  void FillWithRandom();
  bool IsRunning();
  void Terminate();
  void Run();

  bool set_input_neurons(vector<double> &input);
  void set_epochs_amount(size_t epochs);
  void set_learning_rate(double value);
  size_t get_training_progress();
  size_t get_testing_progress();
  char get_recognized_letter();
  double get_answer_confidence();
  size_t get_current_epoch();
  vector<double> *get_avg_accuracy();
  void get_metrics(vector<map<size_t, double>> &metrics, size_t *correct,
                   size_t *all, double *avg_accuracy);

 private:
  vector<vector<GNeuron>> layers_;
  vector<GNeuron> *p_output_;
  vector<GNeuron> *p_input_;

  struct State {
    double answer_confidence_;
    bool under_training_;
    char expected_sym_;
    bool terminated_;
    char output_sym_;
    bool running_;
  } state_;

  struct Train {
    size_t current_epoch_;
    string dataset_path_;
    vector<vector<double>> file;
    size_t progress_;
    size_t strings_;
    size_t epochs_;
    size_t start_;
    double rate_;
  } train_;

  struct Test {
    string dataset_path_;
    vector<vector<double>> file;
    size_t progress_;
    size_t strings_;
  } test_;

  struct Metrics {
    map<size_t, double> precision_;
    map<size_t, double> f_measure_;
    map<size_t, size_t> letters_;
    vector<double> avg_accuracy_;
    map<size_t, double> recall_;
    size_t right_answers_;
    size_t all_answers_;
  } metric_;

  struct CrossV {
    size_t begin_;
    size_t end_;
  } cross_v_;

  double &w_element(vector<GNeuron> &layer, size_t i, size_t j);
  void ConfigurateSize(int input_neurons, int hidden_layers,
                       int output_neurons);
  void ConnectLayers();
  void ConnectNeurons(vector<GNeuron> *prev, vector<GNeuron> *current,
                      vector<GNeuron> *next);
  bool UploadLayers(ifstream &file);
  bool ReadMatrix(ifstream &file, vector<GNeuron> &layer);
  void SaveLayers(ofstream &file);
  void WriteDataSize(ofstream &file, vector<GNeuron> &layer);
  void WriteData(ofstream &file, vector<GNeuron> &layer);
  void FillMatrixRandom(vector<GNeuron> &layer);
  void WeightedSum(vector<GNeuron> &layer);
  void Activate(vector<GNeuron> &layer);
  double Sigmoid(const double value);
  double SigmoidDerivative(const double value);
  char GetAnswer();
  bool UploadDataset(string &dataset_path, vector<vector<double>> &file_up);
  void LoadLine(string &line, vector<double> &num_line);
  void DatasetTraining(size_t test_chunk_begin, size_t test_chunk_end);
  bool IsAsciiNumber(const char sym);
  bool IsInOfArea(size_t line_number, size_t chunk_begin, size_t chunk_end);
  bool IsOutOfArea(size_t line_number, size_t chunk_begin, size_t chunk_end);
  void FillInput(vector<double> &num_line);
  size_t TrackProgress(size_t current, size_t total);
  void Backpropagation();
  void CorrectOutputLayerWeights(vector<GNeuron> &layer);
  void GetOutputLayerErrors(vector<GNeuron> &layer);
  void CorrectHiddenLayerWeights(vector<GNeuron> &layer);
  void GetHiddenLayerErrors(vector<GNeuron> &layer);
  void CalculateGradient(vector<GNeuron> &layer);
  void RunTesting(size_t test_chunk_begin, size_t test_chunk_end);
  void CleanMetrics();
  void UpdateMetrics(size_t &right_answers, map<size_t, size_t> &letters);
  void FinishMetrics(size_t &right_answers, map<size_t, size_t> &letters);
  double FMeasure(double precision, double recall);
  void RunCrossValidating(size_t groups);
};

}  // namespace s21

#endif  // SRC_MLP_MODEL_MODULE_GRAPH_IMPLEMENTATION_G_PERCEPTRON_H
