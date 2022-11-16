#ifndef TRAINING_H
#define TRAINING_H

#include <QWidget>
#include <QLabel>
#include <QFileDialog>
#include <QTimer>
#include <QTime>
#include <QVBoxLayout>
#include "progressbar.h"
#include "graph.h"

namespace Ui {
class Training;
}

namespace s21 {

enum TrainingMode { STANDART, CROSSVALID };
enum TrainingState { RUNNING, AWAITING };

class Training : public QWidget
{
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
    void SetProcessTermination();
    void SetTrainingProgress(size_t value);
    void SetTestingProgress(size_t value);

signals:
    void SaveWeightsSignal();
    void BackSignal();
    void Terminate();
    void Run();


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

}

#endif // TRAINING_H
