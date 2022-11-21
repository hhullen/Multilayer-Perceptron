#ifndef SRC_MODEL_MODULE_MLP_MODEL_H
#define SRC_MODEL_MODULE_MLP_MODEL_H

#include <thread>

#include "graph_implementation/g_perceptron.h"
#include "matrix_implementation/perceptron.h"
using s21::GPerceptron;
using s21::Perceptron;
using std::thread;

namespace s21 {

const int kNEURONS_IN = 784;
const int kNEURONS_OUT = 26;

enum class Implementation { MATRIX, GRAPH };
enum class WCFGMode { RANDOM, FILE };

class MLPModel {
 public:
  MLPModel();
  ~MLPModel();

  bool CreatePerceptron(Implementation type, size_t layers, string &wcfg_path,
                        WCFGMode wcfg_mode);
  char Classify(vector<double> *pixels, double *confidence);
  bool SaveWeights(string &save_path);
  void RunTraining(string train_dataset, string test_dataset,
                   size_t epochs_or_groups, double learning_rate);
  void RunCrossValidation(string dataset_path, size_t groups,
                          double learning_rate);
  void UpdateLearningRate(double learning_rate);
  void UpdateTrainingState(size_t *current_epoch, vector<double> **avg_accuracy,
                           size_t *training_progress, size_t *testing_progress,
                           bool *is_running);
  void RunTesting(string test_dataset, double coeff);
  void UpdateTestingState(size_t *testing_progress, bool *is_running);
  void UpdateMetrics(vector<map<size_t, double>> &metrics, size_t *correct,
                     size_t *all, double *avg_accuracy);
  void TerminateProcess();

 private:
  thread *run_thread_;

  Perceptron *matrix_mlp_;
  GPerceptron *graph_mlp_;
  Implementation implementation_;
  WCFGMode wcfg_mode_;

  void RemoveObject(Perceptron *obj);
  void RemoveObject(GPerceptron *obj);
  bool ConfigurateObject(Perceptron *obj, WCFGMode wcfg_mode,
                         string &wcfg_path);
  bool ConfigurateObject(GPerceptron *obj, WCFGMode wcfg_mode,
                         string &wcfg_path);
  void CopyData(vector<double> &pixels, Matrix &input);
  void delete_thread();
};

}  // namespace s21

#endif  // SRC_MODEL_MODULE_MLP_MODEL_H
