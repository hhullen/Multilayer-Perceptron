/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_input_area;
    QLabel *label_output_area;
    QWidget *input_area;
    QGridLayout *gridLayout;
    QWidget *output_area;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1600, 700);
        MainWindow->setMinimumSize(QSize(1600, 700));
        MainWindow->setMaximumSize(QSize(1600, 700));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label_input_area = new QLabel(centralwidget);
        label_input_area->setObjectName(QString::fromUtf8("label_input_area"));
        label_input_area->setGeometry(QRect(5, 9, 512, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("PT Sans Caption")});
        font.setPointSize(25);
        label_input_area->setFont(font);
        label_output_area = new QLabel(centralwidget);
        label_output_area->setObjectName(QString::fromUtf8("label_output_area"));
        label_output_area->setGeometry(QRect(520, 9, 512, 31));
        label_output_area->setFont(font);
        input_area = new QWidget(centralwidget);
        input_area->setObjectName(QString::fromUtf8("input_area"));
        input_area->setGeometry(QRect(5, 40, 512, 512));
        input_area->setMinimumSize(QSize(512, 512));
        input_area->setMaximumSize(QSize(512, 512));
        input_area->setStyleSheet(QString::fromUtf8("QWidget {\n"
"	background-color: rgb(0, 0, 0);\n"
"	color: rgb(0, 0, 0);\n"
"	alternate-background-color: rgb(0, 0, 0);\n"
"}"));
        gridLayout = new QGridLayout(input_area);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        output_area = new QWidget(centralwidget);
        output_area->setObjectName(QString::fromUtf8("output_area"));
        output_area->setGeometry(QRect(522, 40, 512, 512));
        output_area->setMinimumSize(QSize(512, 512));
        output_area->setMaximumSize(QSize(512, 512));
        output_area->setStyleSheet(QString::fromUtf8("QWidget {\n"
"	background-color: rgb(0, 0, 0);\n"
"	color: rgb(0, 0, 0);\n"
"	alternate-background-color: rgb(0, 0, 0);\n"
"}"));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_input_area->setText(QCoreApplication::translate("MainWindow", "Input area", nullptr));
        label_output_area->setText(QCoreApplication::translate("MainWindow", "Output area", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
