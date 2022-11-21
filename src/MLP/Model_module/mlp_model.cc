#include "mlp_model.h"

namespace s21 {

MLPModel::MLPModel()
    : matrix_mlp_(nullptr),
      graph_mlp_(nullptr),
      run_thread_(nullptr),
      implementation_(Implementation::MATRIX),
      wcfg_mode_(WCFGMode::RANDOM) {}

MLPModel::~MLPModel() {
  if (matrix_mlp_) {
    delete matrix_mlp_;
  }
  matrix_mlp_ = nullptr;
  delete_thread();
}

bool MLPModel::CreatePerceptron(Implementation type, size_t layers,
                                string &wcfg_path, WCFGMode wcfg_mode) {
  bool returnable = false;

  implementation_ = type;
  if (implementation_ == Implementation::MATRIX) {
    RemoveObject(matrix_mlp_);
    matrix_mlp_ = new Perceptron(kNEURONS_IN, layers, kNEURONS_OUT);
    returnable = ConfigurateObject(matrix_mlp_, wcfg_mode, wcfg_path);
  } else if (implementation_ == Implementation::GRAPH) {
    RemoveObject(graph_mlp_);
    graph_mlp_ = new GPerceptron(kNEURONS_IN, layers, kNEURONS_OUT);
    returnable = ConfigurateObject(graph_mlp_, wcfg_mode, wcfg_path);
  }

  return returnable;
}

char MLPModel::Classify(vector<double> *pixels, double *confidence) {
  char returnable = 0;

  if (!matrix_mlp_->IsRunning() && implementation_ == Implementation::MATRIX) {
    Matrix input(pixels->size(), 1);
    CopyData(*pixels, input);
    matrix_mlp_->set_input_neurons(input);
    matrix_mlp_->Run();
    returnable = matrix_mlp_->get_recognized_letter();
    *confidence = matrix_mlp_->get_answer_confidence();
  } else if (!graph_mlp_->IsRunning() &&
             implementation_ == Implementation::GRAPH) {
    graph_mlp_->set_input_neurons(*pixels);
    graph_mlp_->Run();
    returnable = graph_mlp_->get_recognized_letter();
    *confidence = graph_mlp_->get_answer_confidence();
  }

  return returnable;
}

bool MLPModel::SaveWeights(string &save_path) {
  bool returnable = false;

  if (implementation_ == Implementation::MATRIX) {
    returnable = matrix_mlp_->SaveConfig(save_path);
  } else if (implementation_ == Implementation::GRAPH) {
    returnable = graph_mlp_->SaveConfig(save_path);
  }

  return returnable;
}

void MLPModel::RunTraining(string train_dataset, string test_dataset,
                           size_t epochs_or_groups, double learning_rate) {
  if (!matrix_mlp_->IsRunning() && implementation_ == Implementation::MATRIX) {
    delete_thread();
    matrix_mlp_->set_epochs_amount(epochs_or_groups);
    matrix_mlp_->set_learning_rate(learning_rate);
    run_thread_ = new thread(&Perceptron::Train, matrix_mlp_, train_dataset,
                             test_dataset, 1);
    run_thread_->detach();
  } else if (!graph_mlp_->IsRunning() &&
             implementation_ == Implementation::GRAPH) {
    delete_thread();
    graph_mlp_->set_epochs_amount(epochs_or_groups);
    graph_mlp_->set_learning_rate(learning_rate);
    run_thread_ = new thread(&GPerceptron::Train, graph_mlp_, train_dataset,
                             test_dataset, 1);
    run_thread_->detach();
  }
}

void MLPModel::RunCrossValidation(string dataset_path, size_t groups,
                                  double learning_rate) {
  if (!matrix_mlp_->IsRunning() && implementation_ == Implementation::MATRIX) {
    delete_thread();
    matrix_mlp_->set_learning_rate(learning_rate);
    run_thread_ = new thread(&Perceptron::CrossValidation, matrix_mlp_,
                             dataset_path, groups);
    run_thread_->detach();
  } else if (!graph_mlp_->IsRunning() &&
             implementation_ == Implementation::GRAPH) {
    delete_thread();
    graph_mlp_->set_learning_rate(learning_rate);
    run_thread_ = new thread(&GPerceptron::CrossValidation, graph_mlp_,
                             dataset_path, groups);
    run_thread_->detach();
  }
}

void MLPModel::UpdateLearningRate(double learning_rate) {
  if (implementation_ == Implementation::MATRIX) {
    matrix_mlp_->set_learning_rate(learning_rate);
  } else if (implementation_ == Implementation::GRAPH) {
    graph_mlp_->set_learning_rate(learning_rate);
  }
}

void MLPModel::UpdateTrainingState(size_t *current_epoch,
                                   vector<double> **avg_accuracy,
                                   size_t *training_progress,
                                   size_t *testing_progress, bool *is_running) {
  if (implementation_ == Implementation::MATRIX) {
    *current_epoch = matrix_mlp_->get_current_epoch();
    *avg_accuracy = matrix_mlp_->get_avg_accuracy();
    *training_progress = matrix_mlp_->get_training_progress();
    *testing_progress = matrix_mlp_->get_testing_progress();
    *is_running = matrix_mlp_->IsRunning();
  } else if (implementation_ == Implementation::GRAPH) {
    *current_epoch = graph_mlp_->get_current_epoch();
    *avg_accuracy = graph_mlp_->get_avg_accuracy();
    *training_progress = graph_mlp_->get_training_progress();
    *testing_progress = graph_mlp_->get_testing_progress();
    *is_running = graph_mlp_->IsRunning();
  }
}

void MLPModel::RunTesting(string test_dataset, double coeff) {
  if (!matrix_mlp_->IsRunning() && implementation_ == Implementation::MATRIX) {
    delete_thread();
    run_thread_ =
        new thread(&Perceptron::Test, matrix_mlp_, test_dataset, coeff);
    run_thread_->detach();
  } else if (!graph_mlp_->IsRunning() &&
             implementation_ == Implementation::GRAPH) {
    delete_thread();
    run_thread_ =
        new thread(&GPerceptron::Test, graph_mlp_, test_dataset, coeff);
    run_thread_->detach();
  }
}

void MLPModel::UpdateTestingState(size_t *testing_progress, bool *is_running) {
  if (implementation_ == Implementation::MATRIX) {
    *testing_progress = matrix_mlp_->get_testing_progress();
    *is_running = matrix_mlp_->IsRunning();
  } else if (implementation_ == Implementation::GRAPH) {
    *testing_progress = graph_mlp_->get_testing_progress();
    *is_running = graph_mlp_->IsRunning();
  }
}

void MLPModel::UpdateMetrics(vector<map<size_t, double>> &metrics,
                             size_t *correct, size_t *all,
                             double *avg_accuracy) {
  if (implementation_ == Implementation::MATRIX) {
    matrix_mlp_->get_metrics(metrics, correct, all, avg_accuracy);
  } else if (implementation_ == Implementation::GRAPH) {
    graph_mlp_->get_metrics(metrics, correct, all, avg_accuracy);
  }
}

void MLPModel::TerminateProcess() {
  if (implementation_ == Implementation::MATRIX) {
    matrix_mlp_->Terminate();
  } else if (implementation_ == Implementation::GRAPH) {
    graph_mlp_->Terminate();
  }
}

void MLPModel::RemoveObject(Perceptron *obj) {
  if (obj) {
    obj->Terminate();
    delete obj;
  }
}

void MLPModel::RemoveObject(GPerceptron *obj) {
  if (obj) {
    obj->Terminate();
    delete obj;
  }
}

bool MLPModel::ConfigurateObject(Perceptron *obj, WCFGMode wcfg_mode,
                                 string &wcfg_path) {
  bool returnable = false;

  if (wcfg_mode == WCFGMode::FILE) {
    returnable = obj->UploadConfig(wcfg_path);
  } else if (wcfg_mode == WCFGMode::RANDOM) {
    obj->FillWithRandom();
    returnable = true;
  }

  return returnable;
}

bool MLPModel::ConfigurateObject(GPerceptron *obj, WCFGMode wcfg_mode,
                                 string &wcfg_path) {
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

void MLPModel::delete_thread() {
  if (run_thread_) {
    delete run_thread_;
  }
  run_thread_ = nullptr;
}

}  // namespace s21
