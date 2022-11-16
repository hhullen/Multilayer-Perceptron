#include "option.h"
#include "ui_option.h"

namespace s21 {

Option::Option(QWidget *parent) :
    QWidget(parent),
    ui_(new Ui::Option) {
    ui_->setupUi(this);

    SetSystemInfo();
    ClearConfigPath();
    ui_->btn_open_config->setDisabled(true);

    connect(ui_->btn_back, &QPushButton::clicked, this, &Option::BackSignal);
    connect(ui_->btn_open_config, &QPushButton::clicked, this, &Option::OpenConfigFile);
    connect(ui_->combo_box_weights_type, &QComboBox::currentIndexChanged, this, &Option::SwitchButtonState);
}

Option::~Option() {
    delete ui_;
}

QComboBox *Option::GetImplementationSwitcher() {
    return ui_->combo_box_realization;
}

QComboBox *Option::GetLayersSwitcher() {
    return ui_->combo_box_layers;
}

QString Option::GetConfigPath() {
    return ui_->label_config_file_path->text();
}

void Option::ClearConfigPath() {
    ui_->label_config_file_path->setText("");
}

void Option::OpenConfigFile() {
    QString file_path = QFileDialog::getOpenFileName(this, "Open .wcfg file", "/Users",
                                                "wcfg (*.wcfg);;");
    if (!file_path.isEmpty()) {
        ui_->label_config_file_path->setText(file_path);
        emit ConfigChosen();
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
        system("cat /proc/cpuinfo  | grep 'model name' > proc.inf");
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
    if (index == WeightsMode::RANDOM) {
        ui_->btn_open_config->setDisabled(true);
    } else if (index == WeightsMode::FILE) {
        ui_->btn_open_config->setDisabled(false);
    }
}

}
