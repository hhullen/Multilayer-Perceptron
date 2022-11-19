#ifndef TESTING_H
#define TESTING_H

#include <QFileDialog>
#include <QTime>
#include <QTimer>
#include <QVBoxLayout>
#include <QWidget>

#include "confirmationdialog.h"
#include "progressbar.h"
#include "testtablerow.h"

namespace Ui {
class Testing;
}

namespace s21 {

enum class TestingState { RUNNING, AWAITING };

class Testing : public QWidget {
  Q_OBJECT

 public:
  explicit Testing(QWidget *parent = nullptr);
  ~Testing();
  void AddTableRow(QChar letter, double precision, double recall,
                   double f_measure);
  void ClearFields();
  void SetTestingProgress(size_t value);
  void SetCorrectlyClassified(size_t correct, size_t total);
  void SetAVGAccuracy(double value);
  QString GetTestingFilePath();
  double GetSamplePart();
  void Terminate();

 signals:
  void BackSignal();
  void RunSignal();
  void TerminateSignal();
  void SentMessageSignal(QString message);

 private:
  Ui::Testing *ui_;
  ProgressBar *progress_bar_;
  QVBoxLayout *progress_layout_;
  QVBoxLayout *table_layout_;
  QTimer process_timer_;
  QTime *time_;

  void SetUpLayout();
  void OpenDatasetFile();
  void StartTesting();
  void StopTesting();
  void SwitchState(TestingState state);
  void SwitchInfoHint();
  void IncreaseTimer();
  void SetTimerField();
};

}  // namespace s21

#endif  // TESTING_H
