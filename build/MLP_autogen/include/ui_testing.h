/********************************************************************************
** Form generated from reading UI file 'testing.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTING_H
#define UI_TESTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Testing
{
public:
    QPushButton *btn_back;
    QLabel *label_name;
    QPushButton *btn_open_testing_file;
    QLabel *label_testing_file_path;
    QLabel *label_testing_file;
    QLabel *label_sample_part;
    QPushButton *btn_info;
    QLabel *label_sample_part_range;
    QPushButton *btn_test_run;
    QPushButton *btn_test_terminate;
    QScrollArea *scrollArea;
    QWidget *output_table_content;
    QWidget *widget_progress;
    QWidget *widget_table_head;
    QLabel *label_column_letter;
    QLabel *label_column_precision;
    QLabel *label_column_recall;
    QLabel *label_column_f_measure;
    QLabel *label_time;
    QLabel *label_avg_accuracy;
    QLabel *label_rightclassified;
    QLabel *label_time_value;
    QLabel *label_correctly_value;
    QLabel *label_avg_accuracy_value;
    QWidget *widget_separator_1;
    QWidget *widget_separator_2;
    QWidget *widget_separator_3;
    QDoubleSpinBox *line_edit_sample_part;
    QTextBrowser *format_info;

    void setupUi(QWidget *Testing)
    {
        if (Testing->objectName().isEmpty())
            Testing->setObjectName(QString::fromUtf8("Testing"));
        Testing->resize(1039, 600);
        Testing->setMinimumSize(QSize(1039, 600));
        Testing->setMaximumSize(QSize(1039, 600));
        QFont font;
        font.setFamilies({QString::fromUtf8("Microsoft Sans Serif")});
        Testing->setFont(font);
        btn_back = new QPushButton(Testing);
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
        label_name = new QLabel(Testing);
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
        btn_open_testing_file = new QPushButton(Testing);
        btn_open_testing_file->setObjectName(QString::fromUtf8("btn_open_testing_file"));
        btn_open_testing_file->setGeometry(QRect(350, 70, 150, 30));
        btn_open_testing_file->setMinimumSize(QSize(150, 30));
        btn_open_testing_file->setMaximumSize(QSize(150, 30));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Microsoft Sans Serif")});
        font3.setPointSize(18);
        font3.setBold(true);
        font3.setItalic(false);
        font3.setKerning(false);
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
        label_testing_file_path = new QLabel(Testing);
        label_testing_file_path->setObjectName(QString::fromUtf8("label_testing_file_path"));
        label_testing_file_path->setGeometry(QRect(139, 100, 410, 32));
        label_testing_file_path->setMinimumSize(QSize(410, 32));
        label_testing_file_path->setMaximumSize(QSize(410, 32));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Microsoft Sans Serif")});
        font4.setPointSize(18);
        font4.setBold(true);
        label_testing_file_path->setFont(font4);
        label_testing_file_path->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	alternate-background-color: rgba(0, 0, 0, 0);\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"	color: rgb(127, 126, 128);\n"
"}"));
        label_testing_file_path->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_testing_file = new QLabel(Testing);
        label_testing_file->setObjectName(QString::fromUtf8("label_testing_file"));
        label_testing_file->setGeometry(QRect(50, 70, 300, 32));
        label_testing_file->setMinimumSize(QSize(300, 32));
        label_testing_file->setMaximumSize(QSize(300, 32));
        label_testing_file->setFont(font2);
        label_testing_file->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	alternate-background-color: rgba(0, 0, 0, 0);\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"	color: rgb(227, 226, 228);\n"
"}"));
        label_testing_file->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_sample_part = new QLabel(Testing);
        label_sample_part->setObjectName(QString::fromUtf8("label_sample_part"));
        label_sample_part->setGeometry(QRect(50, 140, 300, 32));
        label_sample_part->setMinimumSize(QSize(300, 32));
        label_sample_part->setMaximumSize(QSize(300, 32));
        label_sample_part->setFont(font2);
        label_sample_part->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	alternate-background-color: rgba(0, 0, 0, 0);\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"	color: rgb(227, 226, 228);\n"
"}"));
        label_sample_part->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        btn_info = new QPushButton(Testing);
        btn_info->setObjectName(QString::fromUtf8("btn_info"));
        btn_info->setGeometry(QRect(509, 70, 32, 32));
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
        label_sample_part_range = new QLabel(Testing);
        label_sample_part_range->setObjectName(QString::fromUtf8("label_sample_part_range"));
        label_sample_part_range->setGeometry(QRect(500, 140, 101, 32));
        label_sample_part_range->setMinimumSize(QSize(0, 32));
        label_sample_part_range->setMaximumSize(QSize(700, 32));
        label_sample_part_range->setFont(font4);
        label_sample_part_range->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	alternate-background-color: rgba(0, 0, 0, 0);\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"	color: rgb(127, 126, 128);\n"
"}"));
        label_sample_part_range->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        btn_test_run = new QPushButton(Testing);
        btn_test_run->setObjectName(QString::fromUtf8("btn_test_run"));
        btn_test_run->setGeometry(QRect(660, 80, 211, 51));
        btn_test_run->setMinimumSize(QSize(150, 30));
        btn_test_run->setMaximumSize(QSize(1500, 999));
        btn_test_run->setFont(font3);
        btn_test_run->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        btn_test_terminate = new QPushButton(Testing);
        btn_test_terminate->setObjectName(QString::fromUtf8("btn_test_terminate"));
        btn_test_terminate->setGeometry(QRect(660, 80, 211, 51));
        btn_test_terminate->setMinimumSize(QSize(150, 30));
        btn_test_terminate->setMaximumSize(QSize(1500, 999));
        btn_test_terminate->setFont(font3);
        btn_test_terminate->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        scrollArea = new QScrollArea(Testing);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(160, 242, 436, 300));
        scrollArea->setMinimumSize(QSize(436, 300));
        scrollArea->setMaximumSize(QSize(436, 300));
        scrollArea->setStyleSheet(QString::fromUtf8("QScrollArea {\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"	alternate-background-color: rgba(0, 0, 0, 0);\n"
"	border: 1px solid rgba(35, 119, 255, 0.3);\n"
"	border-radius: 7px;\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"	border: none;\n"
"	background-color: rgb(27, 40, 56);\n"
"	alternate-background-color: gb(27, 40, 56);\n"
"	width: 14px;\n"
"	margin: 0px 0 0px 0;\n"
"	border-radius: 7px;\n"
"}\n"
"\n"
"QScrollBar:handle:hover:vertical {\n"
"	border: none;\n"
"	background-color: rgb(27, 131, 255);\n"
"	alternate-background-color: rgb(27, 131, 255);\n"
"	width: 14px;\n"
"	margin: 0px 0 0px 0;\n"
"	border-radius: 7px;\n"
"}\n"
"\n"
"QScrollBar:handle:vertical {\n"
"	background-color: rgba(35, 121, 255, 0.7);\n"
"	alternate-background-color: rgba(35, 121, 255, 0.7);\n"
"	width: 14px;\n"
"	border-radius: 7px;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical {\n"
"	border: 0px solid black;\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"    height: 1px;\n"
"	subcontrol-position: bottom;\n"
"	subcontrol-origin: margin;\n"
""
                        "}\n"
"\n"
"QScrollBar::sub-line:vertical {\n"
"	border: 0px solid black;\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"    height: 1px;\n"
"	subcontrol-position: bottom;\n"
"	subcontrol-origin: margin;\n"
"}\n"
""));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setFrameShadow(QFrame::Raised);
        scrollArea->setLineWidth(1);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setWidgetResizable(true);
        scrollArea->setAlignment(Qt::AlignCenter);
        output_table_content = new QWidget();
        output_table_content->setObjectName(QString::fromUtf8("output_table_content"));
        output_table_content->setGeometry(QRect(0, 0, 420, 298));
        output_table_content->setStyleSheet(QString::fromUtf8("QWidget {\n"
"	background-color: rgba(0, 0, 0, 0.15);\n"
"	alternate-background-color: rgba(0, 0, 0, 0.15);\n"
"	border: 0px solid rgba(0,0,0, 0);\n"
"	border-radius: 7px;\n"
"}"));
        scrollArea->setWidget(output_table_content);
        widget_progress = new QWidget(Testing);
        widget_progress->setObjectName(QString::fromUtf8("widget_progress"));
        widget_progress->setGeometry(QRect(40, 550, 960, 32));
        widget_progress->setMinimumSize(QSize(960, 32));
        widget_progress->setMaximumSize(QSize(960, 32));
        widget_table_head = new QWidget(Testing);
        widget_table_head->setObjectName(QString::fromUtf8("widget_table_head"));
        widget_table_head->setGeometry(QRect(160, 210, 422, 32));
        label_column_letter = new QLabel(widget_table_head);
        label_column_letter->setObjectName(QString::fromUtf8("label_column_letter"));
        label_column_letter->setGeometry(QRect(0, 0, 32, 32));
        label_column_letter->setMinimumSize(QSize(0, 0));
        label_column_letter->setMaximumSize(QSize(422, 32));
        label_column_letter->setFont(font2);
        label_column_letter->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	alternate-background-color: rgba(0, 0, 0, 0);\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"	color: rgb(127, 126, 128);\n"
"}"));
        label_column_letter->setAlignment(Qt::AlignCenter);
        label_column_precision = new QLabel(widget_table_head);
        label_column_precision->setObjectName(QString::fromUtf8("label_column_precision"));
        label_column_precision->setGeometry(QRect(32, 0, 130, 32));
        label_column_precision->setMinimumSize(QSize(0, 0));
        label_column_precision->setMaximumSize(QSize(300, 32));
        label_column_precision->setFont(font2);
        label_column_precision->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	alternate-background-color: rgba(0, 0, 0, 0);\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"	color: rgb(127, 126, 128);\n"
"}"));
        label_column_precision->setAlignment(Qt::AlignCenter);
        label_column_recall = new QLabel(widget_table_head);
        label_column_recall->setObjectName(QString::fromUtf8("label_column_recall"));
        label_column_recall->setGeometry(QRect(162, 0, 130, 32));
        label_column_recall->setMinimumSize(QSize(0, 0));
        label_column_recall->setMaximumSize(QSize(300, 32));
        label_column_recall->setFont(font2);
        label_column_recall->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	alternate-background-color: rgba(0, 0, 0, 0);\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"	color: rgb(127, 126, 128);\n"
"}"));
        label_column_recall->setAlignment(Qt::AlignCenter);
        label_column_f_measure = new QLabel(widget_table_head);
        label_column_f_measure->setObjectName(QString::fromUtf8("label_column_f_measure"));
        label_column_f_measure->setGeometry(QRect(290, 0, 130, 32));
        label_column_f_measure->setMinimumSize(QSize(0, 0));
        label_column_f_measure->setMaximumSize(QSize(300, 32));
        label_column_f_measure->setFont(font2);
        label_column_f_measure->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	alternate-background-color: rgba(0, 0, 0, 0);\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"	color: rgb(127, 126, 128);\n"
"}"));
        label_column_f_measure->setAlignment(Qt::AlignCenter);
        label_time = new QLabel(Testing);
        label_time->setObjectName(QString::fromUtf8("label_time"));
        label_time->setGeometry(QRect(610, 240, 200, 32));
        label_time->setMinimumSize(QSize(200, 32));
        label_time->setMaximumSize(QSize(200, 32));
        label_time->setFont(font2);
        label_time->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	alternate-background-color: rgba(0, 0, 0, 0);\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"	color: rgb(127, 126, 128);\n"
"}"));
        label_time->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_avg_accuracy = new QLabel(Testing);
        label_avg_accuracy->setObjectName(QString::fromUtf8("label_avg_accuracy"));
        label_avg_accuracy->setGeometry(QRect(610, 440, 200, 32));
        label_avg_accuracy->setMinimumSize(QSize(200, 32));
        label_avg_accuracy->setMaximumSize(QSize(200, 32));
        label_avg_accuracy->setFont(font2);
        label_avg_accuracy->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	alternate-background-color: rgba(0, 0, 0, 0);\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"	color: rgb(127, 126, 128);\n"
"}"));
        label_avg_accuracy->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_rightclassified = new QLabel(Testing);
        label_rightclassified->setObjectName(QString::fromUtf8("label_rightclassified"));
        label_rightclassified->setGeometry(QRect(610, 340, 200, 32));
        label_rightclassified->setMinimumSize(QSize(200, 32));
        label_rightclassified->setMaximumSize(QSize(200, 32));
        label_rightclassified->setFont(font2);
        label_rightclassified->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	alternate-background-color: rgba(0, 0, 0, 0);\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"	color: rgb(127, 126, 128);\n"
"}"));
        label_rightclassified->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_time_value = new QLabel(Testing);
        label_time_value->setObjectName(QString::fromUtf8("label_time_value"));
        label_time_value->setGeometry(QRect(610, 280, 300, 40));
        label_time_value->setMinimumSize(QSize(300, 40));
        label_time_value->setMaximumSize(QSize(300, 40));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Microsoft Sans Serif")});
        font5.setPointSize(30);
        font5.setBold(true);
        label_time_value->setFont(font5);
        label_time_value->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	alternate-background-color: rgba(0, 0, 0, 0);\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"	color: rgb(227, 226, 228);\n"
"}"));
        label_time_value->setAlignment(Qt::AlignCenter);
        label_correctly_value = new QLabel(Testing);
        label_correctly_value->setObjectName(QString::fromUtf8("label_correctly_value"));
        label_correctly_value->setGeometry(QRect(610, 380, 300, 40));
        label_correctly_value->setMinimumSize(QSize(300, 40));
        label_correctly_value->setMaximumSize(QSize(300, 40));
        label_correctly_value->setFont(font5);
        label_correctly_value->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	alternate-background-color: rgba(0, 0, 0, 0);\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"	color: rgb(227, 226, 228);\n"
"}"));
        label_correctly_value->setAlignment(Qt::AlignCenter);
        label_avg_accuracy_value = new QLabel(Testing);
        label_avg_accuracy_value->setObjectName(QString::fromUtf8("label_avg_accuracy_value"));
        label_avg_accuracy_value->setGeometry(QRect(610, 480, 300, 40));
        label_avg_accuracy_value->setMinimumSize(QSize(300, 40));
        label_avg_accuracy_value->setMaximumSize(QSize(300, 40));
        label_avg_accuracy_value->setFont(font5);
        label_avg_accuracy_value->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	alternate-background-color: rgba(0, 0, 0, 0);\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"	color: rgb(227, 226, 228);\n"
"}"));
        label_avg_accuracy_value->setAlignment(Qt::AlignCenter);
        widget_separator_1 = new QWidget(Testing);
        widget_separator_1->setObjectName(QString::fromUtf8("widget_separator_1"));
        widget_separator_1->setGeometry(QRect(610, 325, 300, 2));
        widget_separator_1->setStyleSheet(QString::fromUtf8("QWidget {\n"
"	background-color: rgba(84,99,113, 0.3);\n"
"	border-radius: 2px;\n"
"	color: rgba(255, 255, 255, 0);\n"
"border: 1px solid rgba(0, 0, 0, 0);\n"
"}"));
        widget_separator_2 = new QWidget(Testing);
        widget_separator_2->setObjectName(QString::fromUtf8("widget_separator_2"));
        widget_separator_2->setGeometry(QRect(610, 425, 300, 2));
        widget_separator_2->setStyleSheet(QString::fromUtf8("QWidget {\n"
"	background-color: rgba(84,99,113, 0.3);\n"
"	border-radius: 2px;\n"
"	color: rgba(255, 255, 255, 0);\n"
"border: 1px solid rgba(0, 0, 0, 0);\n"
"}"));
        widget_separator_3 = new QWidget(Testing);
        widget_separator_3->setObjectName(QString::fromUtf8("widget_separator_3"));
        widget_separator_3->setGeometry(QRect(610, 525, 300, 2));
        widget_separator_3->setStyleSheet(QString::fromUtf8("QWidget {\n"
"	background-color: rgba(84,99,113, 0.3);\n"
"	border-radius: 2px;\n"
"	color: rgba(255, 255, 255, 0);\n"
"border: 1px solid rgba(0, 0, 0, 0);\n"
"}"));
        line_edit_sample_part = new QDoubleSpinBox(Testing);
        line_edit_sample_part->setObjectName(QString::fromUtf8("line_edit_sample_part"));
        line_edit_sample_part->setGeometry(QRect(350, 140, 150, 32));
        line_edit_sample_part->setMinimumSize(QSize(150, 32));
        line_edit_sample_part->setMaximumSize(QSize(150, 32));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Microsoft Sans Serif")});
        font6.setPointSize(20);
        line_edit_sample_part->setFont(font6);
        line_edit_sample_part->setStyleSheet(QString::fromUtf8("QDoubleSpinBox {\n"
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
        line_edit_sample_part->setAlignment(Qt::AlignCenter);
        line_edit_sample_part->setReadOnly(false);
        line_edit_sample_part->setButtonSymbols(QAbstractSpinBox::NoButtons);
        line_edit_sample_part->setMinimum(0.100000000000000);
        line_edit_sample_part->setMaximum(1.000000000000000);
        line_edit_sample_part->setSingleStep(0.100000000000000);
        line_edit_sample_part->setValue(1.000000000000000);
        format_info = new QTextBrowser(Testing);
        format_info->setObjectName(QString::fromUtf8("format_info"));
        format_info->setGeometry(QRect(550, 70, 381, 141));
        format_info->setStyleSheet(QString::fromUtf8("QTextBrowser {\n"
"	background-color: rgb(15,21,30);\n"
"	alternate-background-color: rgb(15,21,30);\n"
"	color: rgb(255, 255, 255);\n"
"\n"
"}"));
        btn_test_terminate->raise();
        btn_test_run->raise();
        btn_back->raise();
        label_name->raise();
        btn_open_testing_file->raise();
        label_testing_file_path->raise();
        label_testing_file->raise();
        label_sample_part->raise();
        btn_info->raise();
        label_sample_part_range->raise();
        scrollArea->raise();
        widget_progress->raise();
        widget_table_head->raise();
        label_time->raise();
        label_avg_accuracy->raise();
        label_rightclassified->raise();
        label_time_value->raise();
        label_correctly_value->raise();
        label_avg_accuracy_value->raise();
        widget_separator_1->raise();
        widget_separator_2->raise();
        widget_separator_3->raise();
        line_edit_sample_part->raise();
        format_info->raise();

        retranslateUi(Testing);

        QMetaObject::connectSlotsByName(Testing);
    } // setupUi

    void retranslateUi(QWidget *Testing)
    {
        Testing->setWindowTitle(QCoreApplication::translate("Testing", "Form", nullptr));
        btn_back->setText(QCoreApplication::translate("Testing", "\342\235\260", nullptr));
        label_name->setText(QCoreApplication::translate("Testing", "TESTING", nullptr));
        btn_open_testing_file->setText(QCoreApplication::translate("Testing", "OPEN", nullptr));
        label_testing_file_path->setText(QString());
        label_testing_file->setText(QCoreApplication::translate("Testing", "Testing dataset file: ", nullptr));
        label_sample_part->setText(QCoreApplication::translate("Testing", "Test sample part: ", nullptr));
        btn_info->setText(QCoreApplication::translate("Testing", "i", nullptr));
        label_sample_part_range->setText(QCoreApplication::translate("Testing", "  0.1..1", nullptr));
        btn_test_run->setText(QCoreApplication::translate("Testing", "RUN", nullptr));
        btn_test_terminate->setText(QCoreApplication::translate("Testing", "TERMINATE", nullptr));
        label_column_letter->setText(QCoreApplication::translate("Testing", "A", nullptr));
        label_column_precision->setText(QCoreApplication::translate("Testing", "Precision", nullptr));
        label_column_recall->setText(QCoreApplication::translate("Testing", "Recall", nullptr));
        label_column_f_measure->setText(QCoreApplication::translate("Testing", "F-Measure", nullptr));
        label_time->setText(QCoreApplication::translate("Testing", "Time:", nullptr));
        label_avg_accuracy->setText(QCoreApplication::translate("Testing", "Average accuracy:", nullptr));
        label_rightclassified->setText(QCoreApplication::translate("Testing", "Correctly:", nullptr));
        label_time_value->setText(QCoreApplication::translate("Testing", "00:00:00", nullptr));
        label_correctly_value->setText(QCoreApplication::translate("Testing", "0 / 0", nullptr));
        label_avg_accuracy_value->setText(QCoreApplication::translate("Testing", "0.000 %", nullptr));
        format_info->setHtml(QCoreApplication::translate("Testing", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Microsoft Sans Serif'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:18pt;\">Testing file format should have specific format containing letter number (from 1 - 26) at first and 784 pixels values separated by commas.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:18pt;\">For instance pixels values for letter &quot;C&quot;:</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">"
                        "<span style=\" font-size:18pt;\">3,0,0,255,255, ... 170,0,0</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Testing: public Ui_Testing {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTING_H
