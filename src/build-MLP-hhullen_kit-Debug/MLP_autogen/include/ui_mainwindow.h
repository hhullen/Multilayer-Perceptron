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
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionMatrix;
    QAction *actionGraph;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1040, 630);
        MainWindow->setMinimumSize(QSize(1040, 630));
        MainWindow->setMaximumSize(QSize(1040, 630));
        QFont font;
        font.setFamilies({QString::fromUtf8("Microsoft Sans Serif")});
        font.setBold(true);
        MainWindow->setFont(font);
        MainWindow->setWindowOpacity(1.000000000000000);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: qradialgradient(cx:0.5, cy:0.5, radius: 0.6,\n"
"                fx:0.5, fy:0.5, stop:0 #1D2739, stop:1 #1D2024);\n"
"	alternate-background-color: rgb(30, 40, 50);\n"
"}"));
        MainWindow->setTabShape(QTabWidget::Triangular);
        actionMatrix = new QAction(MainWindow);
        actionMatrix->setObjectName(QString::fromUtf8("actionMatrix"));
        actionMatrix->setCheckable(true);
        actionGraph = new QAction(MainWindow);
        actionGraph->setObjectName(QString::fromUtf8("actionGraph"));
        actionGraph->setCheckable(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
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
        actionMatrix->setText(QCoreApplication::translate("MainWindow", "Matrix", nullptr));
#if QT_CONFIG(shortcut)
        actionMatrix->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+1", nullptr));
#endif // QT_CONFIG(shortcut)
        actionGraph->setText(QCoreApplication::translate("MainWindow", "Graph", nullptr));
#if QT_CONFIG(shortcut)
        actionGraph->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+2", nullptr));
#endif // QT_CONFIG(shortcut)
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
