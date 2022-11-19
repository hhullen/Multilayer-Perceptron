/********************************************************************************
** Form generated from reading UI file 'classifier.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLASSIFIER_H
#define UI_CLASSIFIER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Classifier
{
public:
    QWidget *input_area;
    QLabel *input_image;
    QWidget *output_area;
    QLabel *label_output_latter;
    QLabel *label_outpu_area;
    QComboBox *combo_box;
    QLabel *label_confidence;
    QLabel *label_percent_value;
    QPushButton *btn_back_menu;
    QLabel *label_bmp_file_name;
    QLabel *label_input_area;
    QPushButton *btn_open_img;
    QPushButton *btn_close_img;
    QLabel *label_name;

    void setupUi(QWidget *Classifier)
    {
        if (Classifier->objectName().isEmpty())
            Classifier->setObjectName(QString::fromUtf8("Classifier"));
        Classifier->resize(1039, 600);
        Classifier->setMinimumSize(QSize(1039, 600));
        Classifier->setMaximumSize(QSize(1039, 600));
        input_area = new QWidget(Classifier);
        input_area->setObjectName(QString::fromUtf8("input_area"));
        input_area->setGeometry(QRect(5, 50, 512, 512));
        input_area->setStyleSheet(QString::fromUtf8("QWidget {\n"
"	color: rgb(0, 0, 0);\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"	alternate-background-color: rgba(0, 0, 0, 0);\n"
"	border-color: rgb(0, 0, 0);\n"
"	selection-background-color: rgb(0, 0, 0);\n"
"	selection-color: rgb(0, 0, 0);\n"
"}"));
        input_image = new QLabel(input_area);
        input_image->setObjectName(QString::fromUtf8("input_image"));
        input_image->setGeometry(QRect(0, 0, 512, 512));
        output_area = new QWidget(Classifier);
        output_area->setObjectName(QString::fromUtf8("output_area"));
        output_area->setGeometry(QRect(522, 50, 512, 512));
        output_area->setStyleSheet(QString::fromUtf8("QWidget {\n"
"	color: rgb(0, 0, 0);\n"
"	background-color: rgb(0, 0, 0);\n"
"	alternate-background-color: rgb(0, 0, 0);\n"
"	border-color: rgb(0, 0, 0);\n"
"	selection-background-color: rgb(0, 0, 0);\n"
"	selection-color: rgb(0, 0, 0);\n"
"}"));
        label_output_latter = new QLabel(output_area);
        label_output_latter->setObjectName(QString::fromUtf8("label_output_latter"));
        label_output_latter->setGeometry(QRect(0, 0, 511, 511));
        QFont font;
        font.setFamilies({QString::fromUtf8("Microsoft Sans Serif")});
        font.setPointSize(550);
        label_output_latter->setFont(font);
        label_output_latter->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	alternate-background-color: rgba(0, 0, 0, 0);\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"	color: rgb(255, 255, 255);\n"
"}"));
        label_output_latter->setAlignment(Qt::AlignCenter);
        label_outpu_area = new QLabel(output_area);
        label_outpu_area->setObjectName(QString::fromUtf8("label_outpu_area"));
        label_outpu_area->setGeometry(QRect(5, 5, 100, 30));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Microsoft Sans Serif")});
        font1.setPointSize(23);
        font1.setBold(true);
        label_outpu_area->setFont(font1);
        label_outpu_area->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	alternate-background-color: rgba(0, 0, 0, 0);\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"	color: rgb(127, 126, 128);\n"
"}"));
        label_outpu_area->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        combo_box = new QComboBox(Classifier);
        combo_box->addItem(QString());
        combo_box->addItem(QString());
        combo_box->setObjectName(QString::fromUtf8("combo_box"));
        combo_box->setGeometry(QRect(5, 563, 190, 30));
        combo_box->setMinimumSize(QSize(190, 30));
        combo_box->setMaximumSize(QSize(190, 30));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Microsoft Sans Serif")});
        font2.setPointSize(18);
        font2.setBold(true);
        combo_box->setFont(font2);
        combo_box->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"	selection-color: rgb(255, 255, 255);\n"
"	background-color: rgba(0, 0, 0, 0.0);\n"
"	alternate-background-color: rgba(0, 0, 0, 0);\n"
"	color: rgba(255, 255, 255, 0.4);\n"
"	border: 1px solid rgba(255, 255, 255, 0);\n"
"	selection-background-color: rgba(0,0,0, 0);\n"
"}"));
        combo_box->setMaxVisibleItems(2);
        label_confidence = new QLabel(Classifier);
        label_confidence->setObjectName(QString::fromUtf8("label_confidence"));
        label_confidence->setGeometry(QRect(680, 565, 105, 30));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Microsoft Sans Serif")});
        font3.setPointSize(20);
        font3.setBold(true);
        label_confidence->setFont(font3);
        label_confidence->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	alternate-background-color: rgba(0, 0, 0, 0);\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"	color: rgb(127, 126, 128);\n"
"}"));
        label_percent_value = new QLabel(Classifier);
        label_percent_value->setObjectName(QString::fromUtf8("label_percent_value"));
        label_percent_value->setGeometry(QRect(790, 565, 211, 30));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Microsoft Sans Serif")});
        font4.setPointSize(20);
        label_percent_value->setFont(font4);
        label_percent_value->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	alternate-background-color: rgba(0, 0, 0, 0);\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"	color: rgb(255, 255, 255);\n"
"}"));
        btn_back_menu = new QPushButton(Classifier);
        btn_back_menu->setObjectName(QString::fromUtf8("btn_back_menu"));
        btn_back_menu->setGeometry(QRect(10, 10, 32, 32));
        btn_back_menu->setMinimumSize(QSize(32, 32));
        btn_back_menu->setMaximumSize(QSize(32, 32));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Microsoft Sans Serif")});
        font5.setPointSize(20);
        font5.setBold(true);
        font5.setItalic(false);
        font5.setKerning(false);
        btn_back_menu->setFont(font5);
        btn_back_menu->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
"	background-color: qlineargradient(x1: 0.4, y1: 0.5, x2: 1, y2: 0.5,\n"
"                                      stop: 0 #02BFFF stop: 1 #2E73FF);\n"
"	alternate-background-color: qlineargradient(x1: 0.4, y1: 0.5, x2: 1, y2: 0.5,\n"
"                                      stop: 0 #02BFFF stop: 1 #2E73FF);\n"
"	border: 1px solid rgba(255, 255, 255, 0);\n"
"	border-radius: 16px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	color: rgb(254, 253, 255);\n"
"    background-color: qlineargradient(x1: 0.3, y1: 0.5, x2: 1, y2: 0.5,\n"
"  "
                        "                                    stop: 0 #02BFFF stop: 1 #2E73FF);\n"
"  alternate-background-color: qlineargradient(x1: 0.3, y1: 0.5, x2: 1, y2: 0.5,\n"
"                                      stop: 0 #02BFFF stop: 1 #2E73FF);\n"
"  border-radius: 16px;\n"
"}"));
        label_bmp_file_name = new QLabel(Classifier);
        label_bmp_file_name->setObjectName(QString::fromUtf8("label_bmp_file_name"));
        label_bmp_file_name->setGeometry(QRect(210, 568, 301, 20));
        label_bmp_file_name->setFont(font3);
        label_bmp_file_name->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	alternate-background-color: rgba(0, 0, 0, 0);\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"	color: rgb(127, 126, 128);\n"
"}"));
        label_bmp_file_name->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_input_area = new QLabel(Classifier);
        label_input_area->setObjectName(QString::fromUtf8("label_input_area"));
        label_input_area->setGeometry(QRect(10, 55, 100, 30));
        label_input_area->setFont(font1);
        label_input_area->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	alternate-background-color: rgba(0, 0, 0, 0);\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"	color: rgb(127, 126, 128);\n"
"}"));
        label_input_area->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        btn_open_img = new QPushButton(Classifier);
        btn_open_img->setObjectName(QString::fromUtf8("btn_open_img"));
        btn_open_img->setGeometry(QRect(166, 300, 180, 60));
        btn_open_img->setMinimumSize(QSize(180, 60));
        btn_open_img->setMaximumSize(QSize(180, 60));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Microsoft Sans Serif")});
        font6.setPointSize(23);
        font6.setBold(true);
        font6.setItalic(false);
        font6.setKerning(false);
        btn_open_img->setFont(font6);
        btn_open_img->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        btn_close_img = new QPushButton(Classifier);
        btn_close_img->setObjectName(QString::fromUtf8("btn_close_img"));
        btn_close_img->setGeometry(QRect(480, 55, 32, 32));
        btn_close_img->setMinimumSize(QSize(32, 32));
        btn_close_img->setMaximumSize(QSize(32, 32));
        btn_close_img->setFont(font5);
        btn_close_img->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: rgb(230, 230, 230);\n"
"	background-color: qlineargradient(x1: 0, y1: 0.5, x2: 1, y2: 0.5,\n"
"                                      stop: 0 #73AF21 stop: 1 #598A1B);\n"
"	alternate-background-color: qlineargradient(x1: 0, y1: 0.5, x2: 1, y2: 0.5,\n"
"                                      stop: 0 #73AF21 stop: 1 #598A1B);\n"
"	border: 1px solid rgba(255, 255, 255, 0);\n"
"	border-radius: 16px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    color: rgb(230, 230, 230);\n"
"	background-color: qlineargradient(x1: 0.3, y1: 0.5, x2: 1, y2: 0.5,\n"
"                                      stop: 0 #8ED627 stop: 1 #6CA521);\n"
"	alternate-background-color: qlineargradient(x1: 0.3, y1: 0.5, x2: 1, y2: 0.5,\n"
"                                      stop: 0 #8ED627 stop: 1 #6CA521);\n"
"	border-radius: 16px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	color: rgb(255, 255, 255);\n"
"    background-color: qlineargradient(x1: 0.3, y1: 0.5, x2: 1, y2: 0.5,\n"
"                                      stop: 0 #8E"
                        "D627 stop: 1 #6CA521);\n"
"  alternate-background-color: qlineargradient(x1: 0.3, y1: 0.5, x2: 1, y2: 0.5,\n"
"                                      stop: 0 #8ED627 stop: 1 #6CA521);\n"
"  border-radius: 16px;\n"
"}"));
        label_name = new QLabel(Classifier);
        label_name->setObjectName(QString::fromUtf8("label_name"));
        label_name->setGeometry(QRect(270, 10, 500, 30));
        label_name->setFont(font1);
        label_name->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	alternate-background-color: rgba(0, 0, 0, 0);\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"	color: rgb(227, 226, 228);\n"
"}"));
        label_name->setAlignment(Qt::AlignCenter);

        retranslateUi(Classifier);

        QMetaObject::connectSlotsByName(Classifier);
    } // setupUi

    void retranslateUi(QWidget *Classifier)
    {
        Classifier->setWindowTitle(QCoreApplication::translate("Classifier", "Form", nullptr));
        input_image->setText(QString());
        label_output_latter->setText(QCoreApplication::translate("Classifier", "A", nullptr));
        label_outpu_area->setText(QCoreApplication::translate("Classifier", "OUTPUT", nullptr));
        combo_box->setItemText(0, QCoreApplication::translate("Classifier", "Mouse drawing", nullptr));
        combo_box->setItemText(1, QCoreApplication::translate("Classifier", "Image *.BPM", nullptr));

        label_confidence->setText(QCoreApplication::translate("Classifier", "Confidence:", nullptr));
        label_percent_value->setText(QCoreApplication::translate("Classifier", "100", nullptr));
        btn_back_menu->setText(QCoreApplication::translate("Classifier", "\342\235\260", nullptr));
        label_bmp_file_name->setText(QCoreApplication::translate("Classifier", "file:", nullptr));
        label_input_area->setText(QCoreApplication::translate("Classifier", "INPUT", nullptr));
        btn_open_img->setText(QCoreApplication::translate("Classifier", "OPEN IMAGE", nullptr));
        btn_close_img->setText(QCoreApplication::translate("Classifier", "\303\227", nullptr));
        label_name->setText(QCoreApplication::translate("Classifier", "LETTERS CLASSIFIER", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Classifier: public Ui_Classifier {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLASSIFIER_H
