#include "option.h"

#include "ui_option.h"

namespace s21 {

Option::Option(QWidget *parent)
    : QWidget(parent), ui_(new Ui::Option), is_locked_(false) {
  ui_->setupUi(this);

  SetSystemInfo();
  ClearConfigPath();
  ui_->btn_open_config->setDisabled(true);

  connect(ui_->btn_back, &QPushButton::clicked, this, &Option::BackSignal);
  connect(ui_->btn_back, &QPushButton::clicked, this, &Option::CheckFilePath);
  connect(ui_->btn_open_config, &QPushButton::clicked, this,
          &Option::OpenConfigFile);
  connect(ui_->combo_box_weights_type, &QComboBox::currentIndexChanged, this,
          &Option::SwitchButtonState);
  connect(ui_->combo_box_layers, &QComboBox::currentIndexChanged, this,
          &Option::ConfigChosen);
  connect(ui_->combo_box_realization, &QComboBox::currentIndexChanged, this,
          &Option::ConfigChosen);
}

Option::~Option() {
  if (ui_) delete ui_;
  ui_ = nullptr;
}

QComboBox *Option::GetImplementationSwitcher() {
  return ui_->combo_box_realization;
}

QComboBox *Option::GetLayersSwitcher() { return ui_->combo_box_layers; }

QComboBox *Option::GetWCFGMode() { return ui_->combo_box_weights_type; }

QString Option::GetConfigPath() { return ui_->label_config_file_path->text(); }

void Option::ClearConfigPath() { ui_->label_config_file_path->setText(""); }

void Option::Lock(bool state) {
  is_locked_ = state;
  if (ui_->combo_box_weights_type->currentIndex() == (int)WeightsMode::FILE) {
    ui_->btn_open_config->setDisabled(state);
  }
  ui_->combo_box_layers->setDisabled(state);
  ui_->combo_box_realization->setDisabled(state);
  ui_->combo_box_weights_type->setDisabled(state);
}

void Option::OpenConfigFile() {
  QString file_path = QFileDialog::getOpenFileName(this, "Open .wcfg file",
                                                   "/Users", "wcfg (*.wcfg);;");
  if (!file_path.isEmpty() && !is_locked_) {
    ui_->label_config_file_path->setText(file_path);
    if (!file_path.isEmpty()) {
      emit ConfigChosen();
    }
  }
}

void Option::SetSystemInfo() {
  QSysInfo info;
  ui_->label_host_value->setText(info.machineHostName());
  ui_->label_kernel_value->setText(info.kernelType());
  ui_->label_os_value->setText(info.prettyProductName());
  if (ui_->label_kernel_value->text() == "darwin") {
    system("sysctl -n machdep.cpu.brand_string > proc.inf");
  } else if (ui_->label_kernel_value->text() == "linux") {
    system(
        "cat /proc/cpuinfo | grep 'model name' | grep -o \":\s*.*$\" | grep -o "
        "\"[^:\s*\t*].*\" | grep -o \"\w.*\"  > proc.inf");
  }

  QString path = QCoreApplication::applicationDirPath() + "/proc.inf";
  ifstream file(path.toStdString());
  string line;
  if (file.is_open()) {
    getline(file, line, '\n');
    ui_->label_cpu_value->setText(QString(line.data()));
    file.close();
  } else {
    ui_->label_cpu_value->setText("n/a");
  }
}

void Option::SwitchButtonState(int index) {
  if (!is_locked_ && index == (int)WeightsMode::RANDOM) {
    ui_->combo_box_weights_type->setCurrentIndex((int)WeightsMode::RANDOM);
    ui_->btn_open_config->setDisabled(true);
    emit ConfigChosen();
  } else if (!is_locked_ && index == (int)WeightsMode::FILE) {
    ui_->combo_box_weights_type->setCurrentIndex((int)WeightsMode::FILE);
    ui_->btn_open_config->setDisabled(false);
  }
}

void Option::CheckFilePath() {
  if (ui_->label_config_file_path->text().isEmpty()) {
    SwitchButtonState((int)WeightsMode::RANDOM);
  }
}

}  // namespace s21
