#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QTimer>
#include <QSysInfo>

#include "Controller_module/mlp_controller.h"
#include "Model_module/mlp_model.h"
#include "option.h"
#include "classifier.h"
#include "main_menu.h"
#include "testing.h"
#include "training.h"
using s21::MLPController;
using s21::MLPModel;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

namespace s21 {

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(MLPController *controller, QWidget *parent = nullptr);
  ~MainWindow();

private slots:
  void GetMainMenuSlot();

 private:
  Ui::MainWindow *ui_;
  MLPController *controller_;
  QVBoxLayout *main_layout_;
  QWidget *main_widget_;

  Classifier *classifier_widget_;
  MainMenu *menu_widget_;
  Option *option_widget_;
  Testing *testing_widget_;
  Training *training_widget_;

  QTimer training_update_;
  QTimer testing_update_;

  void ChangeMode(QWidget *widget);
  void ClassifyLetter();
  void ShowMessage(QString message);
  void SetMode(QAbstractButton *btn);

  void SetupConfiguration();
  void SaveWeights();
  void RunTraining();
  void UpdateLearningRate(double value);
  void UpdateTrainingState();
  void TerminateProcess();
  void RunTesting();
  void UpdateTestingState();
  void UpdateTestingMetrics();

  void SetupConnections();

};

}  // namespace s21

#endif  // MAINWINDOW_H
