/********************************************************************************
** Form generated from reading UI file 'option.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTION_H
#define UI_OPTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Option
{
public:
    QPushButton *btn_back;
    QLabel *label_name;
    QComboBox *combo_box_realization;
    QPushButton *btn_open_config;
    QLabel *label_config_file_path;
    QLabel *label_config_file;
    QLabel *label_realization;
    QLabel *label_os;
    QLabel *label_kernel;
    QLabel *label_cpu;
    QLabel *label_host;
    QLabel *label_cpu_value;
    QLabel *label_kernel_value;
    QLabel *label_os_value;
    QLabel *label_host_value;
    QLabel *label_layers;
    QComboBox *combo_box_layers;
    QComboBox *combo_box_weights_type;
    QLabel *label_realization_3;

    void setupUi(QWidget *Option)
    {
        if (Option->objectName().isEmpty())
            Option->setObjectName(QString::fromUtf8("Option"));
        Option->resize(1039, 600);
        Option->setMinimumSize(QSize(1039, 600));
        Option->setMaximumSize(QSize(1039, 600));
        QFont font;
        font.setFamilies({QString::fromUtf8("Microsoft Sans Serif")});
        Option->setFont(font);
        btn_back = new QPushButton(Option);
        btn_back->setObjectName(QString::fromUtf8("btn_back"));
        btn_back->setGeometry(QRect(10, 10, 32, 32));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Microsoft Sans Serif")});
        font1.setPointSize(20);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setKerning(false);
        btn_back->setFont(font1);
        btn_back->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: rgb(230, 230, 230);\n"
"	background-color: qlineargradient(x1: 0, y1: 0.5, x2: 1, y2: 0.5,\n"
"                                      stop: 0 #07BEFF stop: 1 #2B74FF);\n"
"	alternate-background-color: qlineargradient(x1: 0, y1: 0.5, x2: 1, y2: 0.5,\n"
"                                      stop: 0 #07BEFF stop: 1 #2B74FF);\n"
"	border: 1px solid rgba(255, 255, 255, 0);\n"
"	border-radius: 16px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    color: rgb(230, 230, 230);\n"
"	background-color: qlineargradient(x1: 0.3, y1: 0.5, x2: 1, y2: 0.5,\n"
"                                      stop: 0 #02BFFF stop: 1 #2E73FF);\n"
"	alternate-background-color: qlineargradient(x1: 0.3, y1: 0.5, x2: 1, y2: 0.5,\n"
"                                      stop: 0 #02BFFF stop: 1 #2E73FF);\n"
"	border: 1px solid rgba(255, 255, 255, 0);\n"
"	border-radius: 16px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	color: rgb(255, 255, 255);\n"
"    background-color: qlineargradient(x1: 0.3, y1: 0.5, x2: 1, y2: 0.5,\n"
"  "
                        "                                    stop: 0 #02BFFF stop: 1 #2E73FF);\n"
"  alternate-background-color: qlineargradient(x1: 0.3, y1: 0.5, x2: 1, y2: 0.5,\n"
"                                      stop: 0 #02BFFF stop: 1 #2E73FF);\n"
"  border-radius: 16px;\n"
"}"));
        label_name = new QLabel(Option);
        label_name->setObjectName(QString::fromUtf8("label_name"));
        label_name->setGeometry(QRect(270, 10, 500, 30));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Microsoft Sans Serif")});
        font2.setPointSize(23);
        font2.setBold(true);
        label_name->setFont(font2);
        label_name->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	alternate-background-color: rgba(0, 0, 0, 0);\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"	color: rgb(227, 226, 228);\n"
"}"));
        label_name->setAlignment(Qt::AlignCenter);
        combo_box_realization = new QComboBox(Option);
        combo_box_realization->addItem(QString());
        combo_box_realization->addItem(QString());
        combo_box_realization->setObjectName(QString::fromUtf8("combo_box_realization"));
        combo_box_realization->setGeometry(QRect(520, 100, 150, 32));
        combo_box_realization->setMinimumSize(QSize(150, 32));
        combo_box_realization->setMaximumSize(QSize(190, 32));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Microsoft Sans Serif")});
        font3.setPointSize(18);
        font3.setBold(true);
        combo_box_realization->setFont(font3);
        combo_box_realization->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"	selection-color: rgb(255, 255, 255);\n"
"	background-color: rgba(0, 0, 0, 0.0);\n"
"	alternate-background-color: rgba(0, 0, 0, 0);\n"
"	color: rgba(255, 255, 255, 0.7);\n"
"	border: 1px solid rgba(255, 255, 255, 0);\n"
"	selection-background-color: rgba(0,0,0, 0);\n"
"}\n"
"\n"
"QComboBox:disabled {\n"
"	selection-color: rgb(255, 255, 255);\n"
"	background-color: rgba(0, 0, 0, 0.0);\n"
"	alternate-background-color: rgba(0, 0, 0, 0);\n"
"	color: rgba(255, 255, 255, 0.3);\n"
"	border: 1px solid rgba(255, 255, 255, 0);\n"
"	selection-background-color: rgba(0,0,0, 0);\n"
"}"));
        combo_box_realization->setMaxVisibleItems(2);
        btn_open_config = new QPushButton(Option);
        btn_open_config->setObjectName(QString::fromUtf8("btn_open_config"));
        btn_open_config->setGeometry(QRect(520, 280, 150, 30));
        btn_open_config->setMinimumSize(QSize(150, 30));
        btn_open_config->setMaximumSize(QSize(150, 30));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Microsoft Sans Serif")});
        font4.setPointSize(18);
        font4.setBold(true);
        font4.setItalic(false);
        font4.setKerning(false);
        btn_open_config->setFont(font4);
        btn_open_config->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: rgb(230, 230, 230);\n"
"	background-color: qlineargradient(x1: 0, y1: 0.5, x2: 1, y2: 0.5,\n"
"                                      stop: 0 #73AF21 stop: 1 #598A1B);\n"
"	alternate-background-color: qlineargradient(x1: 0, y1: 0.5, x2: 1, y2: 0.5,\n"
"                                      stop: 0 #73AF21 stop: 1 #598A1B);\n"
"	border: 1px solid rgba(255, 255, 255, 0);\n"
"	border-radius: 14px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    color: rgb(230, 230, 230);\n"
"	background-color: qlineargradient(x1: 0.3, y1: 0.5, x2: 1, y2: 0.5,\n"
"                                      stop: 0 #8ED627 stop: 1 #6CA521);\n"
"	alternate-background-color: qlineargradient(x1: 0.3, y1: 0.5, x2: 1, y2: 0.5,\n"
"                                      stop: 0 #8ED627 stop: 1 #6CA521);\n"
"	border-radius: 14px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	color: rgb(255, 255, 255);\n"
"    background-color: qlineargradient(x1: 0.3, y1: 0.5, x2: 1, y2: 0.5,\n"
"                                      stop: 0 #8E"
                        "D627 stop: 1 #6CA521);\n"
"  alternate-background-color: qlineargradient(x1: 0.3, y1: 0.5, x2: 1, y2: 0.5,\n"
"                                      stop: 0 #8ED627 stop: 1 #6CA521);\n"
"  border-radius: 14px;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"	color: rgb(143,152,160);\n"
"	background-color: qlineargradient(x1: 0, y1: 0.5, x2: 1, y2: 0.5,\n"
"                                      stop: 0 #2C3C49 stop: 1 #53616F);\n"
"	alternate-background-color: qlineargradient(x1: 0, y1: 0.5, x2: 1, y2: 0.5,\n"
"                                      stop: 0 #2C3C49 stop: 1 #53616F);\n"
"	border: 1px solid rgba(0, 0, 0, 0);\n"
"	border-radius: 14px;\n"
"}"));
        label_config_file_path = new QLabel(Option);
        label_config_file_path->setObjectName(QString::fromUtf8("label_config_file_path"));
        label_config_file_path->setGeometry(QRect(240, 310, 430, 32));
        label_config_file_path->setMinimumSize(QSize(430, 32));
        label_config_file_path->setMaximumSize(QSize(430, 32));
        label_config_file_path->setFont(font3);
        label_config_file_path->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	alternate-background-color: rgba(0, 0, 0, 0);\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"	color: rgb(127, 126, 128);\n"
"}"));
        label_config_file_path->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_config_file = new QLabel(Option);
        label_config_file->setObjectName(QString::fromUtf8("label_config_file"));
        label_config_file->setGeometry(QRect(220, 280, 300, 32));
        label_config_file->setMinimumSize(QSize(300, 32));
        label_config_file->setMaximumSize(QSize(300, 32));
        label_config_file->setFont(font2);
        label_config_file->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	alternate-background-color: rgba(0, 0, 0, 0);\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"	color: rgb(227, 226, 228);\n"
"}"));
        label_config_file->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_realization = new QLabel(Option);
        label_realization->setObjectName(QString::fromUtf8("label_realization"));
        label_realization->setGeometry(QRect(220, 100, 300, 32));
        label_realization->setMinimumSize(QSize(300, 32));
        label_realization->setMaximumSize(QSize(300, 32));
        label_realization->setFont(font2);
        label_realization->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	alternate-background-color: rgba(0, 0, 0, 0);\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"	color: rgb(227, 226, 228);\n"
"}"));
        label_realization->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_os = new QLabel(Option);
        label_os->setObjectName(QString::fromUtf8("label_os"));
        label_os->setGeometry(QRect(220, 430, 300, 32));
        label_os->setMinimumSize(QSize(300, 32));
        label_os->setMaximumSize(QSize(300, 32));
        label_os->setFont(font3);
        label_os->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	alternate-background-color: rgba(0, 0, 0, 0);\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"	color: rgb(227, 226, 228);\n"
"}"));
        label_os->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_kernel = new QLabel(Option);
        label_kernel->setObjectName(QString::fromUtf8("label_kernel"));
        label_kernel->setGeometry(QRect(220, 460, 300, 32));
        label_kernel->setMinimumSize(QSize(300, 32));
        label_kernel->setMaximumSize(QSize(300, 32));
        label_kernel->setFont(font3);
        label_kernel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	alternate-background-color: rgba(0, 0, 0, 0);\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"	color: rgb(227, 226, 228);\n"
"}"));
        label_kernel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_cpu = new QLabel(Option);
        label_cpu->setObjectName(QString::fromUtf8("label_cpu"));
        label_cpu->setGeometry(QRect(220, 490, 300, 32));
        label_cpu->setMinimumSize(QSize(300, 32));
        label_cpu->setMaximumSize(QSize(300, 32));
        label_cpu->setFont(font3);
        label_cpu->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	alternate-background-color: rgba(0, 0, 0, 0);\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"	color: rgb(227, 226, 228);\n"
"}"));
        label_cpu->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_host = new QLabel(Option);
        label_host->setObjectName(QString::fromUtf8("label_host"));
        label_host->setGeometry(QRect(220, 400, 300, 32));
        label_host->setMinimumSize(QSize(300, 32));
        label_host->setMaximumSize(QSize(300, 32));
        label_host->setFont(font3);
        label_host->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	alternate-background-color: rgba(0, 0, 0, 0);\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"	color: rgb(227, 226, 228);\n"
"}"));
        label_host->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_cpu_value = new QLabel(Option);
        label_cpu_value->setObjectName(QString::fromUtf8("label_cpu_value"));
        label_cpu_value->setGeometry(QRect(520, 490, 510, 32));
        label_cpu_value->setMinimumSize(QSize(510, 32));
        label_cpu_value->setMaximumSize(QSize(510, 32));
        label_cpu_value->setFont(font3);
        label_cpu_value->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	alternate-background-color: rgba(0, 0, 0, 0);\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"	color: rgb(227, 226, 228);\n"
"}"));
        label_cpu_value->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_kernel_value = new QLabel(Option);
        label_kernel_value->setObjectName(QString::fromUtf8("label_kernel_value"));
        label_kernel_value->setGeometry(QRect(520, 460, 510, 32));
        label_kernel_value->setMinimumSize(QSize(510, 32));
        label_kernel_value->setMaximumSize(QSize(510, 32));
        label_kernel_value->setFont(font3);
        label_kernel_value->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	alternate-background-color: rgba(0, 0, 0, 0);\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"	color: rgb(227, 226, 228);\n"
"}"));
        label_kernel_value->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_os_value = new QLabel(Option);
        label_os_value->setObjectName(QString::fromUtf8("label_os_value"));
        label_os_value->setGeometry(QRect(520, 430, 510, 32));
        label_os_value->setMinimumSize(QSize(510, 32));
        label_os_value->setMaximumSize(QSize(510, 32));
        label_os_value->setFont(font3);
        label_os_value->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	alternate-background-color: rgba(0, 0, 0, 0);\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"	color: rgb(227, 226, 228);\n"
"}"));
        label_os_value->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_host_value = new QLabel(Option);
        label_host_value->setObjectName(QString::fromUtf8("label_host_value"));
        label_host_value->setGeometry(QRect(520, 400, 510, 32));
        label_host_value->setMinimumSize(QSize(510, 32));
        label_host_value->setMaximumSize(QSize(510, 32));
        label_host_value->setFont(font3);
        label_host_value->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	alternate-background-color: rgba(0, 0, 0, 0);\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"	color: rgb(227, 226, 228);\n"
"}"));
        label_host_value->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_layers = new QLabel(Option);
        label_layers->setObjectName(QString::fromUtf8("label_layers"));
        label_layers->setGeometry(QRect(220, 160, 300, 32));
        label_layers->setMinimumSize(QSize(300, 32));
        label_layers->setMaximumSize(QSize(300, 32));
        label_layers->setFont(font2);
        label_layers->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	alternate-background-color: rgba(0, 0, 0, 0);\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"	color: rgb(227, 226, 228);\n"
"}"));
        label_layers->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        combo_box_layers = new QComboBox(Option);
        combo_box_layers->addItem(QString());
        combo_box_layers->addItem(QString());
        combo_box_layers->addItem(QString());
        combo_box_layers->addItem(QString());
        combo_box_layers->setObjectName(QString::fromUtf8("combo_box_layers"));
        combo_box_layers->setGeometry(QRect(520, 160, 150, 32));
        combo_box_layers->setMinimumSize(QSize(150, 32));
        combo_box_layers->setMaximumSize(QSize(190, 32));
        combo_box_layers->setFont(font3);
        combo_box_layers->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"	selection-color: rgb(255, 255, 255);\n"
"	background-color: rgba(0, 0, 0, 0.0);\n"
"	alternate-background-color: rgba(0, 0, 0, 0);\n"
"	color: rgba(255, 255, 255, 0.7);\n"
"	border: 1px solid rgba(255, 255, 255, 0);\n"
"	selection-background-color: rgba(0,0,0, 0);\n"
"}\n"
"\n"
"QComboBox:disabled {\n"
"	selection-color: rgb(255, 255, 255);\n"
"	background-color: rgba(0, 0, 0, 0.0);\n"
"	alternate-background-color: rgba(0, 0, 0, 0);\n"
"	color: rgba(255, 255, 255, 0.3);\n"
"	border: 1px solid rgba(255, 255, 255, 0);\n"
"	selection-background-color: rgba(0,0,0, 0);\n"
"}"));
        combo_box_layers->setMaxVisibleItems(2);
        combo_box_weights_type = new QComboBox(Option);
        combo_box_weights_type->addItem(QString());
        combo_box_weights_type->addItem(QString());
        combo_box_weights_type->setObjectName(QString::fromUtf8("combo_box_weights_type"));
        combo_box_weights_type->setGeometry(QRect(520, 220, 150, 32));
        combo_box_weights_type->setMinimumSize(QSize(150, 32));
        combo_box_weights_type->setMaximumSize(QSize(190, 32));
        combo_box_weights_type->setFont(font3);
        combo_box_weights_type->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"	selection-color: rgb(255, 255, 255);\n"
"	background-color: rgba(0, 0, 0, 0.0);\n"
"	alternate-background-color: rgba(0, 0, 0, 0);\n"
"	color: rgba(255, 255, 255, 0.7);\n"
"	border: 1px solid rgba(255, 255, 255, 0);\n"
"	selection-background-color: rgba(0,0,0, 0);\n"
"}\n"
"\n"
"QComboBox:disabled {\n"
"	selection-color: rgb(255, 255, 255);\n"
"	background-color: rgba(0, 0, 0, 0.0);\n"
"	alternate-background-color: rgba(0, 0, 0, 0);\n"
"	color: rgba(255, 255, 255, 0.3);\n"
"	border: 1px solid rgba(255, 255, 255, 0);\n"
"	selection-background-color: rgba(0,0,0, 0);\n"
"}"));
        combo_box_weights_type->setMaxVisibleItems(2);
        label_realization_3 = new QLabel(Option);
        label_realization_3->setObjectName(QString::fromUtf8("label_realization_3"));
        label_realization_3->setGeometry(QRect(220, 220, 300, 32));
        label_realization_3->setMinimumSize(QSize(300, 32));
        label_realization_3->setMaximumSize(QSize(300, 32));
        label_realization_3->setFont(font2);
        label_realization_3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	alternate-background-color: rgba(0, 0, 0, 0);\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"	color: rgb(227, 226, 228);\n"
"}"));
        label_realization_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        retranslateUi(Option);

        QMetaObject::connectSlotsByName(Option);
    } // setupUi

    void retranslateUi(QWidget *Option)
    {
        Option->setWindowTitle(QCoreApplication::translate("Option", "Form", nullptr));
        btn_back->setText(QCoreApplication::translate("Option", "\342\235\260", nullptr));
        label_name->setText(QCoreApplication::translate("Option", "OPTION", nullptr));
        combo_box_realization->setItemText(0, QCoreApplication::translate("Option", "Matrix", nullptr));
        combo_box_realization->setItemText(1, QCoreApplication::translate("Option", "Graph", nullptr));

        btn_open_config->setText(QCoreApplication::translate("Option", "OPEN", nullptr));
        label_config_file_path->setText(QString());
        label_config_file->setText(QCoreApplication::translate("Option", "Configuration file: ", nullptr));
        label_realization->setText(QCoreApplication::translate("Option", "Model implementation: ", nullptr));
        label_os->setText(QCoreApplication::translate("Option", "Operating system: ", nullptr));
        label_kernel->setText(QCoreApplication::translate("Option", "Kernel type: ", nullptr));
        label_cpu->setText(QCoreApplication::translate("Option", "CPU: ", nullptr));
        label_host->setText(QCoreApplication::translate("Option", "Host name: ", nullptr));
        label_cpu_value->setText(QCoreApplication::translate("Option", "proc", nullptr));
        label_kernel_value->setText(QCoreApplication::translate("Option", "kernel", nullptr));
        label_os_value->setText(QCoreApplication::translate("Option", "macos", nullptr));
        label_host_value->setText(QCoreApplication::translate("Option", "host", nullptr));
        label_layers->setText(QCoreApplication::translate("Option", "Perceptron layers: ", nullptr));
        combo_box_layers->setItemText(0, QCoreApplication::translate("Option", "2 layers", nullptr));
        combo_box_layers->setItemText(1, QCoreApplication::translate("Option", "3 layers", nullptr));
        combo_box_layers->setItemText(2, QCoreApplication::translate("Option", "4 layers", nullptr));
        combo_box_layers->setItemText(3, QCoreApplication::translate("Option", "5 layers", nullptr));

        combo_box_weights_type->setItemText(0, QCoreApplication::translate("Option", "Random", nullptr));
        combo_box_weights_type->setItemText(1, QCoreApplication::translate("Option", "Load file", nullptr));

        label_realization_3->setText(QCoreApplication::translate("Option", "Perceptron weights mode: ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Option: public Ui_Option {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTION_H
