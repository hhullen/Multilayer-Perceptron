#include "mainwindow.h"

#include "./ui_mainwindow.h"

namespace s21 {

MainWindow::MainWindow(MLPController *controller, QWidget *parent)
    : controller_(controller), QMainWindow(parent), ui_(new Ui::MainWindow) {
  ui_->setupUi(this);
  main_layout_ = new QVBoxLayout();
  main_layout_->setAlignment(Qt::AlignTop);
  main_layout_->setSpacing(0);
  main_layout_->setContentsMargins(0, 0, 0, 0);
  ui_->centralwidget->setLayout(main_layout_);
  classifier_widget_ = new Classifier();
  menu_widget_ = new MainMenu();
  option_widget_ = new Option();
  testing_widget_ = new Testing();
  training_widget_ = new Training();

  testing_widget_->SetTestingProgress(0);
  main_widget_ = menu_widget_;
  main_layout_->addWidget(main_widget_);

  SetupConfiguration();
  SetupConnections();
}

MainWindow::~MainWindow() {
  TerminateTraining();
  TerminateTesting();
  if (ui_) delete ui_;
  ui_ = nullptr;
  if (classifier_widget_) delete classifier_widget_;
  classifier_widget_ = nullptr;
  if (menu_widget_) delete menu_widget_;
  menu_widget_ = nullptr;
  if (option_widget_) delete option_widget_;
  option_widget_ = nullptr;
  if (testing_widget_) delete testing_widget_;
  testing_widget_ = nullptr;
  if (training_widget_) delete training_widget_;
  training_widget_ = nullptr;
  if (main_layout_) delete main_layout_;
  main_layout_ = nullptr;
}

void MainWindow::SetMode(QAbstractButton *btn) {
  if (btn->text() == "CLASSIFYING") {
    ChangeMode(classifier_widget_);
  } else if (btn->text() == "TRAINING") {
    ChangeMode(training_widget_);
  } else if (btn->text() == "TESTING") {
    ChangeMode(testing_widget_);
  } else if (btn->text() == "=") {
    ChangeMode(option_widget_);
  }
  main_layout_->addWidget(main_widget_);
}

void MainWindow::GetMainMenuSlot() { ChangeMode(menu_widget_); }

void MainWindow::ChangeMode(QWidget *widget) {
  main_widget_->setVisible(false);
  main_layout_->removeWidget(main_widget_);
  main_widget_ = widget;
  main_widget_->setVisible(true);
  main_layout_->addWidget(main_widget_);
}

void MainWindow::ClassifyLetter() {
  vector<double> *pixels = classifier_widget_->GetPixelsVector();
  double confidence = 0;
  char answer;

  answer = controller_->Classify(pixels, &confidence);

  classifier_widget_->SetAnswerLetter(answer + 'A');
  classifier_widget_->SetConfidence(confidence);
}

void MainWindow::ShowMessage(QString message) {
  ui_->statusbar->showMessage(message, 6000);
}

void MainWindow::SetupConfiguration() {
  Implementation type =
      (Implementation)option_widget_->GetImplementationSwitcher()
          ->currentIndex();
  size_t layers = option_widget_->GetLayersSwitcher()->currentIndex() + 2;
  QString file_path = option_widget_->GetConfigPath();
  WCFGMode wcfg_mode = (WCFGMode)option_widget_->GetWCFGMode()->currentIndex();
  bool is_successfuly = false;

  is_successfuly =
      controller_->Create(type, layers, file_path.toStdString(), wcfg_mode);
  if (!is_successfuly) {
    ShowMessage("Failed to setup configuration");
    menu_widget_->LockAll(true);
  } else {
    ShowMessage("Successfully configurated");
    menu_widget_->LockAll(false);
  }
}

void MainWindow::SaveWeights() {
  QString save_path = training_widget_->GetSavingPath();
  controller_->SaveWeights(save_path.toStdString());
}

void MainWindow::RunTraining() {
  TrainingMode mode = training_widget_->GetMode();
  QString train_dataset = training_widget_->GetTrainingFilePath();
  QString test_dataset = training_widget_->GetTestingFilePath();
  double learning_rate = training_widget_->GetLearningRate();

  if (mode == TrainingMode::STANDART) {
    size_t epochs = training_widget_->GetEpochs();
    controller_->RunTraining(train_dataset.toStdString(),
                             test_dataset.toStdString(), epochs, learning_rate);
  } else if (mode == TrainingMode::CROSSVALID) {
    size_t groups = training_widget_->GetGroups();
    controller_->RunCrossValidation(train_dataset.toStdString(), groups,
                                    learning_rate);
  }
  menu_widget_->LockTesting(true);
  menu_widget_->LockClassifier(true);
  option_widget_->Lock(true);
  training_update_.start(100);
}

void MainWindow::UpdateLearningRate(double value) {
  controller_->UpdateLearningRate(value);
}

void MainWindow::UpdateTrainingState() {
  size_t current_epoch = 0;
  vector<double> *avg_accuracy = nullptr;
  size_t training_progress = 0;
  size_t testing_progress = 0;
  bool is_running = true;

  controller_->UpdateTrainingState(&current_epoch, &avg_accuracy,
                                   &training_progress, &testing_progress,
                                   &is_running);
  training_widget_->SetCurrentEpoch(current_epoch);
  training_widget_->SetTrainingProgress(training_progress);
  training_widget_->SetTestingProgress(testing_progress);
  if (avg_accuracy) {
    training_widget_->UpdateGraphData(*avg_accuracy);
  }
  if (!is_running) {
    training_update_.stop();
    training_widget_->Terminate();
    training_widget_->SetTrainingProgress(100);
    training_widget_->SetTestingProgress(100);
    menu_widget_->LockTesting(false);
    menu_widget_->LockClassifier(false);
    option_widget_->Lock(false);
  }
}

void MainWindow::TerminateTraining() {
  controller_->TerminateProcess();
  training_update_.stop();
  menu_widget_->LockTesting(false);
  menu_widget_->LockClassifier(false);
  option_widget_->Lock(false);
}

void MainWindow::TerminateTesting() {
  controller_->TerminateProcess();
  testing_update_.stop();
  menu_widget_->LockTraining(false);
  menu_widget_->LockClassifier(false);
  option_widget_->Lock(false);
}

void MainWindow::RunTesting() {
  QString dataset_path = testing_widget_->GetTestingFilePath();
  double coeff = testing_widget_->GetSamplePart();

  controller_->RunTesting(dataset_path.toStdString(), coeff);
  menu_widget_->LockClassifier(true);
  menu_widget_->LockTraining(true);
  option_widget_->Lock(true);
  testing_update_.start(100);
}

void MainWindow::UpdateTestingState() {
  size_t testing_progress = 0;
  bool is_running = true;

  controller_->UpdateTestingState(&testing_progress, &is_running);
  testing_widget_->SetTestingProgress(testing_progress);

  if (!is_running) {
    testing_update_.stop();
    testing_widget_->Terminate();
    testing_widget_->SetTestingProgress(100);
    UpdateTestingMetrics();
    menu_widget_->LockTraining(false);
    menu_widget_->LockClassifier(false);
    option_widget_->Lock(false);
  }
}

void MainWindow::UpdateTestingMetrics() {
  vector<map<size_t, double>> metrics;
  size_t correct = 0;
  size_t all = 0;
  double avg_accuracy = 0;

  controller_->UpdateMetrics(metrics, &correct, &all, &avg_accuracy);
  map<size_t, double> &precision_ = metrics[0];
  map<size_t, double> &recall_ = metrics[1];
  map<size_t, double> &f_measure_ = metrics[2];

  for (size_t i = 0; i < precision_.size(); ++i) {
    testing_widget_->AddTableRow(QChar((int)(i + 'A')), precision_[i] * 100,
                                 recall_[i] * 100, f_measure_[i] * 100);
  }
  testing_widget_->SetAVGAccuracy(avg_accuracy * 100);
  testing_widget_->SetCorrectlyClassified(correct, all);
}

void MainWindow::SetupConnections() {
  connect(menu_widget_->GetMenuItemsGroup(), &QButtonGroup::buttonClicked, this,
          &MainWindow::SetMode);
  connect(classifier_widget_, &Classifier::ReadySignal, this,
          &MainWindow::ClassifyLetter);
  connect(classifier_widget_, &Classifier::SentMessage, this,
          &MainWindow::ShowMessage);

  connect(classifier_widget_, &Classifier::BackSignal, this,
          &MainWindow::GetMainMenuSlot);
  connect(option_widget_, &Option::BackSignal, this,
          &MainWindow::GetMainMenuSlot);
  connect(testing_widget_, &Testing::BackSignal, this,
          &MainWindow::GetMainMenuSlot);
  connect(training_widget_, &Training::BackSignal, this,
          &MainWindow::GetMainMenuSlot);

  connect(classifier_widget_, &Classifier::SentMessage, this,
          &MainWindow::ShowMessage);
  connect(option_widget_, &Option::ConfigChosen, this,
          &MainWindow::SetupConfiguration);
  connect(training_widget_, &Training::SaveWeightsSignal, this,
          &MainWindow::SaveWeights);
  connect(training_widget_, &Training::SentMessageSignal, this,
          &MainWindow::ShowMessage);
  connect(training_widget_, &Training::RunSignal, this,
          &MainWindow::RunTraining);
  connect(training_widget_, &Training::UpdateLearningRateSignal, this,
          &MainWindow::UpdateLearningRate);
  connect(training_widget_, &Training::TerminateSignal, this,
          &MainWindow::TerminateTraining);
  connect(&training_update_, &QTimer::timeout, this,
          &MainWindow::UpdateTrainingState);
  connect(testing_widget_, &Testing::SentMessageSignal, this,
          &MainWindow::ShowMessage);
  connect(testing_widget_, &Testing::RunSignal, this, &MainWindow::RunTesting);
  connect(testing_widget_, &Testing::TerminateSignal, this,
          &MainWindow::TerminateTesting);
  connect(&testing_update_, &QTimer::timeout, this,
          &MainWindow::UpdateTestingState);
}

}  // namespace s21
