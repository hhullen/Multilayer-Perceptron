#include "training.h"
#include "ui_training.h"

namespace s21 {

Training::Training(QWidget *parent) :
    QWidget(parent),
    ui_(new Ui::Training), graph_data_size_(1) {
    ui_->setupUi(this);
    ui_->format_info->setVisible(false);
    ui_->btn_training_terminate->setVisible(false);
    time_ = new QTime(0, 0, 0);

    SetUpLayout();
    testing_progress_ = new ProgressBar();
    training_progress_ = new ProgressBar();
    training_progress_->SetName("Training progress:");
    testing_progress_->SetName("Testing progress:");
    testing_progress_->SetProgressValue(0);
    training_progress_->SetProgressValue(0);
    ui_->widget_progress->setLayout(progress_layout_);
    progress_layout_->addWidget(training_progress_);
    progress_layout_->addWidget(testing_progress_);

    ui_->widget_error_graph->setLayout(graph_layout_);
    errors_graph_ = new Graph();
    errors_graph_->SetRangeX(0, ui_->spin_box_groups_or_epochs->value());
    graph_layout_->addWidget(errors_graph_);

    SetupConnections();
}

Training::~Training() {
    delete ui_;
}

QString Training::GetTrainingFilePath() {
    return ui_->label_training_file_path->text();
}

QString Training::GetTestingFilePath() {
    return ui_->label_testing_file_path->text();
}

QString Training::GetSavingPath() {
    QString path = saving_path_;
    saving_path_.clear();
    return path;
}

TrainingMode Training::GetMode() {
    return current_mode_;
}

size_t Training::GetEpochs() {
    return ui_->spin_box_groups_or_epochs->value();
}

size_t Training::GetGroups() {
    return ui_->spin_box_groups_or_epochs->value();
}

double Training::GetLearningRate() {
    return ui_->spin_box_learning_rate->value();
}

void Training::SetCurrentEpoch(size_t value) {
    ui_->label_current_epoch_or_group_value->setText(QString::number(value));
}

void Training::SetCurrentGroup(size_t value) {
    ui_->label_current_epoch_or_group_value->setText(QString::number(value));
}

void Training::SetTrainingProgress(size_t value) {
    training_progress_->SetProgressValue(value);
}

void Training::SetTestingProgress(size_t value) {
    testing_progress_->SetProgressValue(value);
}

void Training::Terminate() {
    SwitchState(TrainingState::AWAITING);
    process_timer_.stop();
}

void Training::ManageHint() {
    if (ui_->format_info->isVisible()) {
        ui_->format_info->setVisible(false);
    } else {
        ui_->format_info->setVisible(true);
    }
}

void Training::OpenTrainingFile() {
    OpenNewFile(ui_->label_training_file_path);
}

void Training::OpenTestingFile() {
    OpenNewFile(ui_->label_testing_file_path);
}

void Training::OpenNewFile(QLabel *field) {
    QString file_path = QFileDialog::getOpenFileName(this, "Open .csv file", "/Users",
                                                "csv (*.csv);;");
    if (!file_path.isEmpty()) {
       field->setText(file_path);
    }
}

void Training::ChangeTrainingMode(int index) {
    if (index == (int)TrainingMode::STANDART) {
        ui_->label_groups_or_epochs->setText("Epochs: ");
        ui_->label_rightclassified->setText("Cerrunt epoch:");
        ui_->btn_open_testing_file->setDisabled(false);
    } else if (index == (int)TrainingMode::CROSSVALID) {
        ui_->label_groups_or_epochs->setText("Groups: ");
        ui_->label_rightclassified->setText("Current group:");
        ui_->btn_open_testing_file->setDisabled(true);
    }
    current_mode_ = (TrainingMode)index;
}

void Training::Start() {
    TrainingMode mode = GetMode();
    bool is_train_dataset = GetTrainingFilePath().isEmpty();
    bool is_test_dataset = GetTestingFilePath().isEmpty();
    if (mode == TrainingMode::STANDART && (is_train_dataset || is_test_dataset)) {
        emit SentMessageSignal("No file path to training and testing datasets");
    } else if (mode == TrainingMode::CROSSVALID && is_train_dataset) {
        emit SentMessageSignal("No file path to training dataset");
    }else {
        errors_graph_->Clear();
        graph_data_size_ = 1;
        errors_graph_->SetRangeY(0, 1.2);
        SetCurrentEpoch(0);
        testing_progress_->SetProgressValue(0);
        training_progress_->SetProgressValue(0);
        delete time_;
        time_ = new QTime(0, 0, 0);
        SetTimerField();
        emit RunSignal();
        SwitchState(TrainingState::RUNNING);
        process_timer_.start(1000);
    }
}

void Training::Stop() {
    ConfirmationDialog dialog(this, "Terminate training process?");
    dialog.exec();

    if (dialog.result() == QDialog::DialogCode::Accepted) {
        emit TerminateSignal();
        Terminate();
    }
}

void Training::SwitchState(TrainingState state) {
    bool switcher = false;
    if (state == TrainingState::RUNNING) {
        switcher = true;
    } else if (state == TrainingState::AWAITING) {
        switcher = false;
    }
    ui_->btn_training_terminate->setVisible(switcher);
    ui_->btn_training_run->setVisible(!switcher);
    ui_->btn_open_training_file->setDisabled(switcher);
    ui_->btn_open_testing_file->setDisabled(switcher);
    ui_->btn_save_weights->setDisabled(switcher);
    ui_->combo_training_mode->setDisabled(switcher);
    ui_->spin_box_groups_or_epochs->setDisabled(switcher);
}

void Training::IncreaseTimer() {
    *time_ = time_->addSecs(1);
    SetTimerField();
}

void Training::SetTimerField() {
    QString time = time_->toString(Qt::DateFormat::TextDate);
    ui_->label_time_value->setText(time);
}

void Training::SetUpLayout() {
    progress_layout_ = new QVBoxLayout();
    progress_layout_->setAlignment(Qt::AlignBottom);
    progress_layout_->setSpacing(2);
    progress_layout_->setContentsMargins(0,0,0,0);

    graph_layout_ = new QVBoxLayout();
    graph_layout_->setAlignment(Qt::AlignTop);
    graph_layout_->setSpacing(0);
    graph_layout_->setContentsMargins(0,0,0,0);
}

void Training::SetGraphRangeH(int value) {
    errors_graph_->SetRangeX(0, value);
}

void Training::ChooseSavingDir() {
    QString file_path = QFileDialog::getExistingDirectory(
          this, "Choose folder to save weights", "/Users",
          QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if (!file_path.isEmpty()) {
        saving_path_.clear();
        saving_path_ = file_path;
        MakeFileName();
        emit SaveWeightsSignal();
    }
}

void Training::MakeFileName() {
    QDateTime date_time;
      saving_path_.append("/MLPerceptron_" +
                          date_time.currentDateTime().toString("yyyy_MM_dd_hh_mm_ss") + ".wcfg");
}

void Training::UpdateGraphData(std::vector<double> &data) {
    for (; graph_data_size_ <= data.size(); ++graph_data_size_) {
        if (graph_data_size_ == 1) {
            errors_graph_->AddPoint(0, 1 - data[graph_data_size_ - 1]);
        }
        errors_graph_->AddPoint(graph_data_size_, 1 - data[graph_data_size_ - 1]);
    }
}

void Training::SetupConnections() {
    connect(ui_->btn_back, &QPushButton::clicked, this, &Training::BackSignal);
    connect(ui_->btn_info, &QPushButton::clicked, this, &Training::ManageHint);
    connect(ui_->btn_open_training_file, &QPushButton::clicked, this, &Training::OpenTrainingFile);
    connect(ui_->btn_open_testing_file, &QPushButton::clicked, this, &Training::OpenTestingFile);
    connect(ui_->combo_training_mode, &QComboBox::currentIndexChanged, this, &Training::ChangeTrainingMode);
    connect(ui_->btn_training_run, &QPushButton::clicked, this, &Training::Start);
    connect(ui_->btn_training_terminate, &QPushButton::clicked, this, &Training::Stop);
    connect(&process_timer_, &QTimer::timeout, this, &Training::IncreaseTimer);
    connect(ui_->spin_box_groups_or_epochs, &QSpinBox::valueChanged, this, &Training::SetGraphRangeH);
    connect(ui_->btn_save_weights, &QPushButton::clicked, this, &Training::ChooseSavingDir);
    connect(ui_->spin_box_learning_rate, &QDoubleSpinBox::valueChanged, this, &Training::UpdateLearningRateSignal);
}

}
