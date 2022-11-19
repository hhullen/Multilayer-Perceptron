#ifndef TRAINING_H
#define TRAINING_H

#include <QDialog>
#include <QFileDialog>
#include <QLabel>
#include <QTime>
#include <QTimer>
#include <QVBoxLayout>
#include <QWidget>
#include <vector>

#include "confirmationdialog.h"
#include "graph.h"
#include "progressbar.h"

using std::vector;

namespace Ui {
class Training;
}

namespace s21 {

enum class TrainingMode { STANDART, CROSSVALID };
enum class TrainingState { RUNNING, AWAITING };

class Training : public QWidget {
  Q_OBJECT

 public:
  explicit Training(QWidget *parent = nullptr);
  ~Training();
  QString GetTrainingFilePath();
  QString GetTestingFilePath();
  QString GetSavingPath();
  TrainingMode GetMode();
  size_t GetEpochs();
  size_t GetGroups();
  double GetLearningRate();
  void SetCurrentEpoch(size_t value);
  void SetCurrentGroup(size_t value);
  void SetTrainingProgress(size_t value);
  void SetTestingProgress(size_t value);
  void Terminate();
  void UpdateGraphData(vector<double> &data);

 signals:
  void SaveWeightsSignal();
  void BackSignal();
  void TerminateSignal();
  void RunSignal();
  void SentMessageSignal(QString message);
  void UpdateLearningRateSignal(double value);

 private:
  Ui::Training *ui_;
  TrainingMode current_mode_;
  QTimer process_timer_;
  QTime *time_;
  QVBoxLayout *progress_layout_;
  QVBoxLayout *graph_layout_;
  ProgressBar *testing_progress_;
  ProgressBar *training_progress_;
  Graph *errors_graph_;
  QString saving_path_;
  size_t graph_data_size_;

  void ManageHint();
  void OpenTrainingFile();
  void OpenTestingFile();
  void OpenNewFile(QLabel *field);
  void ChangeTrainingMode(int index);
  void Start();
  void Stop();
  void SwitchState(TrainingState state);
  void IncreaseTimer();
  void SetTimerField();
  void SetUpLayout();
  void SetGraphRangeH(int value);
  void ChooseSavingDir();
  void MakeFileName();
  void SetupConnections();
};

}  // namespace s21

#endif  // TRAINING_H
