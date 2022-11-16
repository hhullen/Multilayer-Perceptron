/********************************************************************************
** Form generated from reading UI file 'training.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAINING_H
#define UI_TRAINING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Training
{
public:
    QPushButton *btn_back;
    QLabel *label_name;
    QPushButton *btn_open_training_file;
    QLabel *label_training_file_path;
    QLabel *label_training_file;
    QLabel *label_groups_or_epochs;
    QPushButton *btn_info;
    QPushButton *btn_training_run;
    QPushButton *btn_training_terminate;
    QWidget *widget_progress;
    QTextBrowser *format_info;
    QPushButton *btn_open_testing_file;
    QLabel *label_testing_file;
    QComboBox *combo_training_mode;
    QLabel *label_training_mode;
    QPushButton *btn_save_weights;
    QLabel *label_testing_file_path;
    QSpinBox *spin_box_groups_or_epochs;
    QLabel *label_learning_rate;
    QWidget *widget;
    QDoubleSpinBox *spin_box_learning_rate;
    QWidget *widget_separator_1;
    QLabel *label_current_epoch_or_group_value;
    QLabel *label_rightclassified;
    QWidget *widget_separator_2;
    QLabel *label_time;
    QLabel *label_time_value;
    QWidget *widget_error_graph;
    QLabel *label_epochs_range;
    QLabel *label_learning_rate_range;

    void setupUi(QWidget *Training)
    {
        if (Training->objectName().isEmpty())
            Training->setObjectName(QString::fromUtf8("Training"));
        Training->resize(1039, 600);
        Training->setMinimumSize(QSize(1039, 600));
        Training->setMaximumSize(QSize(1039, 600));
        QFont font;
        font.setFamilies({QString::fromUtf8("Microsoft Sans Serif")});
        Training->setFont(font);
        btn_back = new QPushButton(Training);
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
        label_name = new QLabel(Training);
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
        btn_open_training_file = new QPushButton(Training);
        btn_open_training_file->setObjectName(QString::fromUtf8("btn_open_training_file"));
        btn_open_training_file->setGeometry(QRect(281, 60, 150, 30));
        btn_open_training_file->setMinimumSize(QSize(150, 30));
        btn_open_training_file->setMaximumSize(QSize(150, 30));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Microsoft Sans Serif")});
        font3.setPointSize(18);
        font3.setBold(true);
        font3.setItalic(false);
        font3.setKerning(false);
        btn_open_training_file->setFont(font3);
        btn_open_training_file->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        label_training_file_path = new QLabel(Training);
        label_training_file_path->setObjectName(QString::fromUtf8("label_training_file_path"));
        label_training_file_path->setGeometry(QRect(70, 90, 360, 32));
        label_training_file_path->setMinimumSize(QSize(360, 32));
        label_training_file_path->setMaximumSize(QSize(360, 32));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Microsoft Sans Serif")});
        font4.setPointSize(18);
        font4.setBold(true);
        label_training_file_path->setFont(font4);
        label_training_file_path->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	alternate-background-color: rgba(0, 0, 0, 0);\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"	color: rgb(127, 126, 128);\n"
"}"));
        label_training_file_path->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_training_file = new QLabel(Training);
        label_training_file->setObjectName(QString::fromUtf8("label_training_file"));
        label_training_file->setGeometry(QRect(-19, 60, 300, 32));
        label_training_file->setMinimumSize(QSize(300, 32));
        label_training_file->setMaximumSize(QSize(300, 32));
        label_training_file->setFont(font2);
        label_training_file->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	alternate-background-color: rgba(0, 0, 0, 0);\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"	color: rgb(227, 226, 228);\n"
"}"));
        label_training_file->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_groups_or_epochs = new QLabel(Training);
        label_groups_or_epochs->setObjectName(QString::fromUtf8("label_groups_or_epochs"));
        label_groups_or_epochs->setGeometry(QRect(-20, 230, 300, 32));
        label_groups_or_epochs->setMinimumSize(QSize(300, 32));
        label_groups_or_epochs->setMaximumSize(QSize(300, 32));
        label_groups_or_epochs->setFont(font2);
        label_groups_or_epochs->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	alternate-background-color: rgba(0, 0, 0, 0);\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"	color: rgb(227, 226, 228);\n"
"}"));
        label_groups_or_epochs->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        btn_info = new QPushButton(Training);
        btn_info->setObjectName(QString::fromUtf8("btn_info"));
        btn_info->setGeometry(QRect(440, 95, 32, 32));
        btn_info->setFont(font1);
        btn_info->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        btn_training_run = new QPushButton(Training);
        btn_training_run->setObjectName(QString::fromUtf8("btn_training_run"));
        btn_training_run->setGeometry(QRect(550, 60, 211, 51));
        btn_training_run->setMinimumSize(QSize(150, 30));
        btn_training_run->setMaximumSize(QSize(1500, 999));
        btn_training_run->setFont(font3);
        btn_training_run->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
"}"));
        btn_training_terminate = new QPushButton(Training);
        btn_training_terminate->setObjectName(QString::fromUtf8("btn_training_terminate"));
        btn_training_terminate->setGeometry(QRect(550, 60, 211, 51));
        btn_training_terminate->setMinimumSize(QSize(150, 30));
        btn_training_terminate->setMaximumSize(QSize(1500, 999));
        btn_training_terminate->setFont(font3);
        btn_training_terminate->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        widget_progress = new QWidget(Training);
        widget_progress->setObjectName(QString::fromUtf8("widget_progress"));
        widget_progress->setGeometry(QRect(40, 535, 960, 62));
        widget_progress->setMinimumSize(QSize(960, 62));
        widget_progress->setMaximumSize(QSize(960, 62));
        format_info = new QTextBrowser(Training);
        format_info->setObjectName(QString::fromUtf8("format_info"));
        format_info->setGeometry(QRect(500, 95, 381, 141));
        format_info->setStyleSheet(QString::fromUtf8("QTextBrowser {\n"
"	background-color: rgb(15,21,30);\n"
"	alternate-background-color: rgb(15,21,30);\n"
"	color: rgb(255, 255, 255);\n"
"\n"
"}"));
        btn_open_testing_file = new QPushButton(Training);
        btn_open_testing_file->setObjectName(QString::fromUtf8("btn_open_testing_file"));
        btn_open_testing_file->setGeometry(QRect(280, 130, 150, 30));
        btn_open_testing_file->setMinimumSize(QSize(150, 30));
        btn_open_testing_file->setMaximumSize(QSize(150, 30));
        btn_open_testing_file->setFont(font3);
        btn_open_testing_file->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        label_testing_file = new QLabel(Training);
        label_testing_file->setObjectName(QString::fromUtf8("label_testing_file"));
        label_testing_file->setGeometry(QRect(-20, 130, 300, 32));
        label_testing_file->setMinimumSize(QSize(300, 32));
        label_testing_file->setMaximumSize(QSize(300, 32));
        label_testing_file->setFont(font2);
        label_testing_file->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	alternate-background-color: rgba(0, 0, 0, 0);\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"	color: rgb(227, 226, 228);\n"
"}"));
        label_testing_file->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        combo_training_mode = new QComboBox(Training);
        combo_training_mode->addItem(QString());
        combo_training_mode->addItem(QString());
        combo_training_mode->setObjectName(QString::fromUtf8("combo_training_mode"));
        combo_training_mode->setGeometry(QRect(280, 190, 190, 32));
        combo_training_mode->setMinimumSize(QSize(150, 32));
        combo_training_mode->setMaximumSize(QSize(190, 32));
        combo_training_mode->setFont(font4);
        combo_training_mode->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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
        combo_training_mode->setMaxVisibleItems(2);
        label_training_mode = new QLabel(Training);
        label_training_mode->setObjectName(QString::fromUtf8("label_training_mode"));
        label_training_mode->setGeometry(QRect(-20, 190, 300, 32));
        label_training_mode->setMinimumSize(QSize(300, 32));
        label_training_mode->setMaximumSize(QSize(300, 32));
        label_training_mode->setFont(font2);
        label_training_mode->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	alternate-background-color: rgba(0, 0, 0, 0);\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"	color: rgb(227, 226, 228);\n"
"}"));
        label_training_mode->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        btn_save_weights = new QPushButton(Training);
        btn_save_weights->setObjectName(QString::fromUtf8("btn_save_weights"));
        btn_save_weights->setGeometry(QRect(780, 60, 211, 51));
        btn_save_weights->setMinimumSize(QSize(150, 30));
        btn_save_weights->setMaximumSize(QSize(1500, 999));
        btn_save_weights->setFont(font3);
        btn_save_weights->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        label_testing_file_path = new QLabel(Training);
        label_testing_file_path->setObjectName(QString::fromUtf8("label_testing_file_path"));
        label_testing_file_path->setGeometry(QRect(70, 160, 360, 32));
        label_testing_file_path->setMinimumSize(QSize(360, 32));
        label_testing_file_path->setMaximumSize(QSize(360, 32));
        label_testing_file_path->setFont(font4);
        label_testing_file_path->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	alternate-background-color: rgba(0, 0, 0, 0);\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"	color: rgb(127, 126, 128);\n"
"}"));
        label_testing_file_path->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spin_box_groups_or_epochs = new QSpinBox(Training);
        spin_box_groups_or_epochs->setObjectName(QString::fromUtf8("spin_box_groups_or_epochs"));
        spin_box_groups_or_epochs->setGeometry(QRect(280, 230, 150, 32));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Microsoft Sans Serif")});
        font5.setPointSize(20);
        spin_box_groups_or_epochs->setFont(font5);
        spin_box_groups_or_epochs->setStyleSheet(QString::fromUtf8("QSpinBox {\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"	alternate-background-color: rgba(0, 0, 0, 0);\n"
"	color: rgb(255, 255, 255);\n"
"	border-radius: 16px;\n"
"	border: 1px solid rgb(34, 122, 255);\n"
"}\n"
"\n"
"QSpinBox:disabled {\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"	alternate-background-color: rgba(0, 0, 0, 0);\n"
"	color: rgb(143,152,160);\n"
"	border-radius: 16px;\n"
"	border: 1px solid #53616F;\n"
"}"));
        spin_box_groups_or_epochs->setAlignment(Qt::AlignCenter);
        spin_box_groups_or_epochs->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spin_box_groups_or_epochs->setMinimum(1);
        spin_box_groups_or_epochs->setMaximum(1000);
        spin_box_groups_or_epochs->setValue(10);
        label_learning_rate = new QLabel(Training);
        label_learning_rate->setObjectName(QString::fromUtf8("label_learning_rate"));
        label_learning_rate->setGeometry(QRect(-20, 280, 300, 32));
        label_learning_rate->setMinimumSize(QSize(300, 32));
        label_learning_rate->setMaximumSize(QSize(300, 32));
        label_learning_rate->setFont(font2);
        label_learning_rate->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	alternate-background-color: rgba(0, 0, 0, 0);\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"	color: rgb(227, 226, 228);\n"
"}"));
        label_learning_rate->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        widget = new QWidget(Training);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(400, 349, 120, 181));
        spin_box_learning_rate = new QDoubleSpinBox(Training);
        spin_box_learning_rate->setObjectName(QString::fromUtf8("spin_box_learning_rate"));
        spin_box_learning_rate->setGeometry(QRect(280, 280, 150, 32));
        spin_box_learning_rate->setMinimumSize(QSize(150, 32));
        spin_box_learning_rate->setMaximumSize(QSize(150, 32));
        spin_box_learning_rate->setFont(font5);
        spin_box_learning_rate->setStyleSheet(QString::fromUtf8("QDoubleSpinBox {\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"	alternate-background-color: rgba(0, 0, 0, 0);\n"
"	color: rgb(255, 255, 255);\n"
"	border-radius: 16px;\n"
"	border: 1px solid rgb(34, 122, 255);\n"
"}\n"
"\n"
"QDoubleSpinBox:disabled {\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"	alternate-background-color: rgba(0, 0, 0, 0);\n"
"	color: rgb(143,152,160);\n"
"	border-radius: 16px;\n"
"	border: 1px solid #53616F;\n"
"}"));
        spin_box_learning_rate->setAlignment(Qt::AlignCenter);
        spin_box_learning_rate->setReadOnly(false);
        spin_box_learning_rate->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spin_box_learning_rate->setDecimals(3);
        spin_box_learning_rate->setMinimum(0.001000000000000);
        spin_box_learning_rate->setMaximum(1.000000000000000);
        spin_box_learning_rate->setSingleStep(0.010000000000000);
        spin_box_learning_rate->setValue(0.001000000000000);
        widget_separator_1 = new QWidget(Training);
        widget_separator_1->setObjectName(QString::fromUtf8("widget_separator_1"));
        widget_separator_1->setGeometry(QRect(550, 205, 300, 2));
        widget_separator_1->setStyleSheet(QString::fromUtf8("QWidget {\n"
"	background-color: rgba(84,99,113, 0.3);\n"
"	border-radius: 2px;\n"
"	color: rgba(255, 255, 255, 0);\n"
"border: 1px solid rgba(0, 0, 0, 0);\n"
"}"));
        label_current_epoch_or_group_value = new QLabel(Training);
        label_current_epoch_or_group_value->setObjectName(QString::fromUtf8("label_current_epoch_or_group_value"));
        label_current_epoch_or_group_value->setGeometry(QRect(550, 260, 300, 40));
        label_current_epoch_or_group_value->setMinimumSize(QSize(300, 40));
        label_current_epoch_or_group_value->setMaximumSize(QSize(300, 40));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Microsoft Sans Serif")});
        font6.setPointSize(30);
        font6.setBold(true);
        label_current_epoch_or_group_value->setFont(font6);
        label_current_epoch_or_group_value->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	alternate-background-color: rgba(0, 0, 0, 0);\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"	color: rgb(227, 226, 228);\n"
"}"));
        label_current_epoch_or_group_value->setAlignment(Qt::AlignCenter);
        label_rightclassified = new QLabel(Training);
        label_rightclassified->setObjectName(QString::fromUtf8("label_rightclassified"));
        label_rightclassified->setGeometry(QRect(550, 220, 200, 32));
        label_rightclassified->setMinimumSize(QSize(200, 32));
        label_rightclassified->setMaximumSize(QSize(200, 32));
        label_rightclassified->setFont(font2);
        label_rightclassified->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	alternate-background-color: rgba(0, 0, 0, 0);\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"	color: rgb(127, 126, 128);\n"
"}"));
        label_rightclassified->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        widget_separator_2 = new QWidget(Training);
        widget_separator_2->setObjectName(QString::fromUtf8("widget_separator_2"));
        widget_separator_2->setGeometry(QRect(550, 305, 300, 2));
        widget_separator_2->setStyleSheet(QString::fromUtf8("QWidget {\n"
"	background-color: rgba(84,99,113, 0.3);\n"
"	border-radius: 2px;\n"
"	color: rgba(255, 255, 255, 0);\n"
"border: 1px solid rgba(0, 0, 0, 0);\n"
"}"));
        label_time = new QLabel(Training);
        label_time->setObjectName(QString::fromUtf8("label_time"));
        label_time->setGeometry(QRect(550, 120, 200, 32));
        label_time->setMinimumSize(QSize(200, 32));
        label_time->setMaximumSize(QSize(200, 32));
        label_time->setFont(font2);
        label_time->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	alternate-background-color: rgba(0, 0, 0, 0);\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"	color: rgb(127, 126, 128);\n"
"}"));
        label_time->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_time_value = new QLabel(Training);
        label_time_value->setObjectName(QString::fromUtf8("label_time_value"));
        label_time_value->setGeometry(QRect(550, 160, 300, 40));
        label_time_value->setMinimumSize(QSize(300, 40));
        label_time_value->setMaximumSize(QSize(300, 40));
        label_time_value->setFont(font6);
        label_time_value->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	alternate-background-color: rgba(0, 0, 0, 0);\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"	color: rgb(227, 226, 228);\n"
"}"));
        label_time_value->setAlignment(Qt::AlignCenter);
        widget_error_graph = new QWidget(Training);
        widget_error_graph->setObjectName(QString::fromUtf8("widget_error_graph"));
        widget_error_graph->setGeometry(QRect(40, 335, 960, 200));
        widget_error_graph->setMinimumSize(QSize(960, 60));
        widget_error_graph->setMaximumSize(QSize(960, 9999));
        label_epochs_range = new QLabel(Training);
        label_epochs_range->setObjectName(QString::fromUtf8("label_epochs_range"));
        label_epochs_range->setGeometry(QRect(430, 230, 71, 32));
        label_epochs_range->setMinimumSize(QSize(0, 32));
        label_epochs_range->setMaximumSize(QSize(700, 32));
        label_epochs_range->setFont(font4);
        label_epochs_range->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	alternate-background-color: rgba(0, 0, 0, 0);\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"	color: rgb(127, 126, 128);\n"
"}"));
        label_epochs_range->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_learning_rate_range = new QLabel(Training);
        label_learning_rate_range->setObjectName(QString::fromUtf8("label_learning_rate_range"));
        label_learning_rate_range->setGeometry(QRect(430, 280, 71, 32));
        label_learning_rate_range->setMinimumSize(QSize(0, 32));
        label_learning_rate_range->setMaximumSize(QSize(700, 32));
        label_learning_rate_range->setFont(font4);
        label_learning_rate_range->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	alternate-background-color: rgba(0, 0, 0, 0);\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"	color: rgb(127, 126, 128);\n"
"}"));
        label_learning_rate_range->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        btn_training_terminate->raise();
        btn_training_run->raise();
        btn_back->raise();
        label_name->raise();
        btn_open_training_file->raise();
        label_training_file_path->raise();
        label_training_file->raise();
        label_groups_or_epochs->raise();
        btn_info->raise();
        widget_progress->raise();
        btn_open_testing_file->raise();
        label_testing_file->raise();
        combo_training_mode->raise();
        label_training_mode->raise();
        btn_save_weights->raise();
        label_testing_file_path->raise();
        spin_box_groups_or_epochs->raise();
        label_learning_rate->raise();
        widget->raise();
        spin_box_learning_rate->raise();
        widget_separator_1->raise();
        label_current_epoch_or_group_value->raise();
        label_rightclassified->raise();
        widget_separator_2->raise();
        label_time->raise();
        label_time_value->raise();
        format_info->raise();
        widget_error_graph->raise();
        label_epochs_range->raise();
        label_learning_rate_range->raise();

        retranslateUi(Training);

        QMetaObject::connectSlotsByName(Training);
    } // setupUi

    void retranslateUi(QWidget *Training)
    {
        Training->setWindowTitle(QCoreApplication::translate("Training", "Form", nullptr));
        btn_back->setText(QCoreApplication::translate("Training", "\342\235\260", nullptr));
        label_name->setText(QCoreApplication::translate("Training", "TRAINING", nullptr));
        btn_open_training_file->setText(QCoreApplication::translate("Training", "OPEN", nullptr));
        label_training_file_path->setText(QString());
        label_training_file->setText(QCoreApplication::translate("Training", "Training dataset file: ", nullptr));
        label_groups_or_epochs->setText(QCoreApplication::translate("Training", "Epochs: ", nullptr));
        btn_info->setText(QCoreApplication::translate("Training", "i", nullptr));
        btn_training_run->setText(QCoreApplication::translate("Training", "RUN", nullptr));
        btn_training_terminate->setText(QCoreApplication::translate("Training", "TERMINATE", nullptr));
        format_info->setHtml(QCoreApplication::translate("Training", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Microsoft Sans Serif'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:18pt;\">Training and testing file format should have specific format containing letter number (from 1 - 26) at first and 784 pixels values separated by commas.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:18pt;\">For instance pixels values for letter &quot;C&quot;:</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-i"
                        "ndent:0px;\"><span style=\" font-size:18pt;\">3,0,0,255,255, ... 170,0,0</span></p></body></html>", nullptr));
        btn_open_testing_file->setText(QCoreApplication::translate("Training", "OPEN", nullptr));
        label_testing_file->setText(QCoreApplication::translate("Training", "Testing dataset file: ", nullptr));
        combo_training_mode->setItemText(0, QCoreApplication::translate("Training", "Standart", nullptr));
        combo_training_mode->setItemText(1, QCoreApplication::translate("Training", "Cross validation", nullptr));

        label_training_mode->setText(QCoreApplication::translate("Training", "Training mode: ", nullptr));
        btn_save_weights->setText(QCoreApplication::translate("Training", "SAVE WEIGHTS", nullptr));
        label_testing_file_path->setText(QString());
        label_learning_rate->setText(QCoreApplication::translate("Training", "Learning rate: ", nullptr));
        label_current_epoch_or_group_value->setText(QCoreApplication::translate("Training", "0", nullptr));
        label_rightclassified->setText(QCoreApplication::translate("Training", "Current epoch:", nullptr));
        label_time->setText(QCoreApplication::translate("Training", "Time:", nullptr));
        label_time_value->setText(QCoreApplication::translate("Training", "00:00:00", nullptr));
        label_epochs_range->setText(QCoreApplication::translate("Training", "  1..1000", nullptr));
        label_learning_rate_range->setText(QCoreApplication::translate("Training", "  0.001..1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Training: public Ui_Training {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAINING_H
