#include "testing.h"
#include "ui_testing.h"

namespace s21 {

Testing::Testing(QWidget *parent) :
    QWidget(parent),
    ui_(new Ui::Testing) {
    ui_->setupUi(this);

    SetUpLayout();
    progress_bar_ = new ProgressBar();
    ui_->widget_progress->setLayout(progress_layout_);
    progress_layout_->addWidget(progress_bar_);
    SetTestingProgress(0);
    progress_bar_->SetName("Testing progress:");
    ui_->btn_test_terminate->setVisible(false);
    ui_->format_info->setVisible(false);
    time_ = new QTime(0,0,0);
    SetTimerField();

    connect(ui_->btn_open_testing_file, &QPushButton::clicked, this, &Testing::OpenDatasetFile);
    connect(ui_->btn_back, &QPushButton::clicked, this, &Testing::BackSignal);
    connect(ui_->btn_test_run, &QPushButton::clicked, this, &Testing::StartTesting);
    connect(ui_->btn_test_terminate, &QPushButton::clicked, this, &Testing::StopTesting);
    connect(ui_->btn_info, &QPushButton::clicked, this, &Testing::SwitchInfoHint);
    connect(&process_timer_, &QTimer::timeout, this, &Testing::IncreaseTimer);
}

Testing::~Testing()
{
    delete ui_;
}

void Testing::AddTableRow(QChar letter, double precision, double recall, double f_measure) {
    TestTableRow *row = new TestTableRow();
    row->SetLetter(letter);
    row->SetPrecision(precision);
    row->SetRecall(recall);
    row->SetFMeasure(f_measure);
    table_layout_->addWidget(row);
}

void Testing::ClearFields() {
    while (table_layout_->count() > 0)  {
        table_layout_->itemAt(0)->widget()->hide();
        table_layout_->removeItem(table_layout_->itemAt(0));
    }
    ui_->label_correctly_value->setText("0 / 0");
    ui_->label_avg_accuracy_value->setText("0 %");
}

void Testing::SetTestingProgress(size_t value) {
    progress_bar_->SetProgressValue(value);
}

void Testing::SetCorrectlyClassified(size_t correct, size_t total) {
    QLabel *field = ui_->label_correctly_value;
    field->setText(QString::number(correct) + " / " + QString::number(total));
}

void Testing::SetAVGAccuracy(double value) {
    QLabel *field = ui_->label_avg_accuracy_value;
    if (value < 0) {
        value = 0;
    }
    field->setText(QString::number(value) + " %");
}

QString Testing::GetTestingFilePath() {
    return ui_->label_testing_file_path->text();
}

double Testing::GetSamplePart() {
    return ui_->line_edit_sample_part->text().toDouble();
}

void Testing::Terminate() {
    SwitchState(TestingState::AWAITING);
    process_timer_.stop();
}

void Testing::SetUpLayout() {
    progress_layout_ = new QVBoxLayout();
    progress_layout_->setAlignment(Qt::AlignTop);
    progress_layout_->setSpacing(0);
    progress_layout_->setContentsMargins(0,0,0,0);

    table_layout_ = new QVBoxLayout();
    table_layout_->setAlignment(Qt::AlignTop);
    table_layout_->setSpacing(0);
    table_layout_->setContentsMargins(0,0,0,0);
    ui_->output_table_content->setLayout(table_layout_);
}

void Testing::OpenDatasetFile() {
    QString file_path = QFileDialog::getOpenFileName(this, "Open .csv file", "/Users",
                                                "csv (*.csv);;");
    if (!file_path.isEmpty()) {
        ui_->label_testing_file_path->setText(file_path);
    }
}

void Testing::StartTesting() {
    bool is_empty_file_path = ui_->label_testing_file_path->text().isEmpty();
    if (is_empty_file_path) {
        emit SentMessageSignal("No file path to testing dataset");
    } else {
        SetTestingProgress(0);
        ClearFields();
        SwitchState(TestingState::RUNNING);
        process_timer_.start();
        delete time_;
        time_ = new QTime(0,0,0);
        SetTimerField();
        process_timer_.start(1000);
        emit RunSignal();
    }
}

void Testing::StopTesting() {
    ConfirmationDialog dialog(this, "Terminate testing process?");
    dialog.exec();

    if (dialog.result() == QDialog::DialogCode::Accepted) {
        SwitchState(TestingState::AWAITING);
        process_timer_.stop();
        emit TerminateSignal();
    }
}

void Testing::SwitchState(TestingState state) {
    bool switcher;
    if (state == TestingState::RUNNING) {
        switcher = true;
    } else if (state == TestingState::AWAITING) {
        switcher = false;
    }
    ui_->btn_open_testing_file->setDisabled(switcher);
    ui_->btn_test_run->setVisible(!switcher);
    ui_->btn_test_terminate->setVisible(switcher);
    ui_->line_edit_sample_part->setDisabled(switcher);
}

void Testing::SwitchInfoHint() {
    if (ui_->format_info->isVisible()) {
        ui_->format_info->setVisible(false);
    } else {
        ui_->format_info->setVisible(true);
    }
}

void Testing::IncreaseTimer() {
    *time_ = time_->addSecs(1);
    SetTimerField();
}

void Testing::SetTimerField() {
    QString time = time_->toString(Qt::DateFormat::TextDate);
    ui_->label_time_value->setText(time);
}

}
