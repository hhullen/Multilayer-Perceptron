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

//  connect(&message_timer_, &QTimer::timeout, this, &MainWindow::HideMessage);

//      int t[3000] =
//      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,19,18,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,20,150,120,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,50,219,203,32,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,115,245,217,37,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,16,159,251,205,33,0,0,0,0,0,0,0,0,0,1,3,4,4,2,0,0,0,0,0,0,0,0,0,9,140,249,190,39,0,0,0,0,0,0,2,4,11,66,94,125,125,77,8,0,0,0,0,0,0,0,0,16,159,251,243,113,4,0,0,0,1,8,77,125,141,216,237,249,249,218,77,2,0,0,0,0,0,0,0,8,139,250,250,127,4,0,1,20,52,96,218,249,250,254,254,254,254,249,125,4,0,0,0,0,0,0,0,4,127,250,250,127,4,1,35,158,220,234,253,254,254,251,251,252,254,250,127,4,0,0,0,0,0,0,0,4,127,250,250,129,14,47,164,245,254,254,254,251,220,153,160,179,247,250,127,4,0,0,0,0,0,0,0,4,127,250,252,191,143,208,247,254,254,253,232,171,79,15,17,53,222,250,127,4,0,0,0,0,0,0,0,4,125,249,254,252,251,254,254,253,232,207,95,22,3,0,0,37,217,250,127,4,0,0,0,0,0,0,0,2,82,232,254,255,254,254,253,219,95,47,7,0,0,0,0,37,217,250,127,4,0,0,0,0,0,0,0,0,22,171,251,254,253,234,202,90,9,1,0,0,0,0,0,37,217,250,127,4,0,0,0,0,0,0,0,0,3,78,201,217,202,95,34,7,0,0,0,0,0,0,0,39,217,250,127,4,0,0,0,0,0,0,0,0,0,7,32,37,32,7,0,0,0,0,0,0,0,0,2,82,233,250,127,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,127,249,250,127,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,22,172,252,250,127,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,82,232,254,245,114,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,139,250,251,206,46,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,32,203,246,176,78,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,37,215,207,48,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,32,170,90,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,27,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
//      QImage img(28, 28, QImage::Format_ARGB32_Premultiplied);
//      size_t r = 0;
//      for (size_t i = 0; i < img.width(); ++i) {
//          for (size_t j = 0; j < img.height(); ++j) {
//              img.setPixelColor(i, j, QColor(t[r], t[r], t[r]));
////              qDebug() << t[r];
//              ++r;
//          }
//      }
//      img = img.scaled(512, 512);
//      img.save("/Users/hhullen/PROJECTS/screen.bmp", "BMP");
}

MainWindow::~MainWindow() { delete ui_; }

void MainWindow::SetMode(QAbstractButton *btn) {
        if  (btn->text() == "CLASSIFYING") {
            ChangeMode(classifier_widget_);
        } else if (btn->text() == "TRAINING"){
            ChangeMode(training_widget_);
        } else if (btn->text() == "TESTING") {
            ChangeMode(testing_widget_);
        } else if (btn->text() == "=") {
            ChangeMode(option_widget_);
        }
        main_layout_->addWidget(main_widget_);
}

void MainWindow::GetMainMenuSlot() {
    ChangeMode(menu_widget_);
}

void MainWindow::ChangeMode(QWidget *widget){
    main_widget_->setVisible(false);
    main_layout_->removeWidget(main_widget_);
    main_widget_ = widget;
    main_widget_->setVisible(true);
    main_layout_->addWidget(main_widget_);
}

void MainWindow::ClassifyLetter() {
    vector<double>*pixels = classifier_widget_->GetPixelsVector();
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
    Implementation type = (Implementation)option_widget_->GetImplementationSwitcher()->currentIndex();
    size_t layers = option_widget_->GetLayersSwitcher()->currentIndex() + 2;
    QString file_path = option_widget_->GetConfigPath();
    WCFGMode wcfg_mode = (WCFGMode)option_widget_->GetWCFGMode()->currentIndex();
    bool is_successfuly = false;

    is_successfuly = controller_->Create(type, layers, file_path.toStdString(), wcfg_mode);
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
        controller_->RunTraining(train_dataset.toStdString(), test_dataset.toStdString(), epochs, learning_rate);
    } else if (mode == TrainingMode::CROSSVALID) {
        size_t groups = training_widget_->GetGroups();
        controller_->RunCrossValidation(train_dataset.toStdString(), groups, learning_rate);
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

    controller_->UpdateTrainingState(&current_epoch, &avg_accuracy, &training_progress, &testing_progress, &is_running);
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

void MainWindow::TerminateProcess() {
    controller_->TerminateProcess();
    training_update_.stop();
    menu_widget_->LockTesting(false);
    menu_widget_->LockClassifier(false);
    option_widget_->Lock(false);
}

void MainWindow::SetupConnections() {
    connect(menu_widget_->GetMenuItemsGroup(), &QButtonGroup::buttonClicked, this, &MainWindow::SetMode);
    connect(classifier_widget_, &Classifier::ReadySignal, this, &MainWindow::ClassifyLetter);
    connect(classifier_widget_, &Classifier::SentMessage, this, &MainWindow::ShowMessage);

    connect(classifier_widget_, &Classifier::BackSignal, this, &MainWindow::GetMainMenuSlot);
    connect(option_widget_, &Option::BackSignal, this, &MainWindow::GetMainMenuSlot);
    connect(testing_widget_, &Testing::BackSignal, this, &MainWindow::GetMainMenuSlot);
    connect(training_widget_, &Training::BackSignal, this, &MainWindow::GetMainMenuSlot);

    connect(classifier_widget_, &Classifier::SentMessage, this, &MainWindow::ShowMessage);
    connect(option_widget_, &Option::ConfigChosen, this, &MainWindow::SetupConfiguration);
    connect(training_widget_, &Training::SaveWeightsSignal, this, &MainWindow::SaveWeights);
    connect(training_widget_, &Training::SentMessageSignal, this, &MainWindow::ShowMessage);
    connect(training_widget_, &Training::RunSignal, this, &MainWindow::RunTraining);
    connect(training_widget_, &Training::UpdateLearningRateSignal, this, &MainWindow::UpdateLearningRate);
    connect(training_widget_, &Training::TerminateSignal, this, &MainWindow::TerminateProcess);
    connect(&training_update_, &QTimer::timeout, this, &MainWindow::UpdateTrainingState);
}

}  // namespace s21
