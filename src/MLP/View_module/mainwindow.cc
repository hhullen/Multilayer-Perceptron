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

  SetupConnections();

//  connect(&message_timer_, &QTimer::timeout, this, &MainWindow::HideMessage);

//      int t[3000] =
//      {19,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,31,31,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,32,184,184,34,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,38,217,232,83,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,38,219,244,115,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,38,220,249,129,4,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,38,220,249,131,5,0,0,0,0,0,0,0,7,45,69,45,9,3,0,0,0,0,0,0,0,0,0,0,38,220,251,175,21,2,0,0,0,0,0,7,91,209,230,211,129,84,22,1,0,0,0,0,0,0,0,0,37,218,253,218,37,4,0,0,0,0,2,20,160,248,254,249,212,173,80,10,3,0,0,0,0,0,0,0,33,207,249,220,38,4,0,0,0,0,9,49,223,251,238,226,250,254,223,129,79,7,0,0,0,0,0,0,9,142,225,220,38,4,0,0,0,0,17,72,229,178,102,55,166,222,255,245,204,33,0,0,0,0,0,0,4,129,220,221,39,5,0,0,0,0,13,61,220,130,49,12,92,161,236,252,218,37,0,0,0,0,0,0,4,129,220,225,51,9,0,0,0,0,20,82,201,51,9,0,7,22,101,232,223,64,8,0,0,0,0,0,4,127,219,248,114,32,0,0,0,0,17,71,168,39,8,0,0,0,28,186,232,168,108,20,2,0,0,0,3,97,188,235,83,21,0,0,0,0,13,60,175,71,19,0,0,0,25,172,221,180,173,46,9,0,0,0,3,97,188,223,51,9,0,0,0,0,20,82,229,128,39,0,0,0,16,76,93,132,223,134,60,7,0,0,4,127,218,220,38,4,0,0,0,0,17,71,228,179,97,7,0,0,0,2,3,24,160,228,209,97,35,21,7,116,205,204,33,4,0,0,0,0,8,45,210,223,162,22,0,0,0,0,0,7,92,221,240,179,117,83,25,87,170,159,20,2,0,0,0,0,0,9,128,245,234,102,39,32,5,0,0,0,10,124,192,223,243,235,175,148,166,62,2,0,0,0,0,0,0,3,80,221,242,180,128,110,19,0,0,0,3,66,111,148,238,253,237,223,212,70,1,0,0,0,0,0,0,0,9,92,161,228,216,184,31,0,0,0,0,2,4,36,188,216,220,205,160,32,0,0,0,0,0,0,0,0,0,7,22,69,49,34,5,0,0,0,0,0,0,5,32,37,38,33,20,1,0,0,0,0,0,0,0,0,0,0,3,16,9,4,0,0,0,0,0,0,0,0,4,4,4,4,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
//      QImage img(28, 28, QImage::Format_ARGB32_Premultiplied);
//      size_t r = 0;
//      for (size_t i = 0; i < img.width(); ++i) {
//          for (size_t j = 0; j < img.height(); ++j) {
//              img.setPixelColor(i, j, QColor(t[r], t[r], t[r]));
//              qDebug() << QColor(t[r], t[r], t[r]);
//              ++r;
//          }
//      }
//      img.save("/Users/hhullen/PROJECTS/CPP7_MLP-0/src/screen.jpeg", "JPEG");
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
    qDebug() << "DATA READY";
    //    controller_->
}

void MainWindow::ShowMessage(QString message) {
     ui_->statusbar->showMessage(message, 6000);
}

void MainWindow::SetupConnections() {
    connect(menu_widget_->GetMenuItemsGroup(), &QButtonGroup::buttonClicked, this, &MainWindow::SetMode);
    connect(classifier_widget_, &Classifier::ReadySignal, this, &MainWindow::ClassifyLetter);
    connect(classifier_widget_, &Classifier::ClassifierAchtungSignal, this, &MainWindow::ShowMessage);

    connect(classifier_widget_, &Classifier::BackSignal, this, &MainWindow::GetMainMenuSlot);
    connect(option_widget_, &Option::BackSignal, this, &MainWindow::GetMainMenuSlot);
    connect(testing_widget_, &Testing::BackSignal, this, &MainWindow::GetMainMenuSlot);
    connect(training_widget_, &Training::BackSignal, this, &MainWindow::GetMainMenuSlot);

    connect(classifier_widget_, &Classifier::ClassifierAchtungSignal, this, &MainWindow::ShowMessage);
}

}  // namespace s21
