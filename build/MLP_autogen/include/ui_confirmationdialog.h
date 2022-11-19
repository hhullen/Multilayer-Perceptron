/********************************************************************************
** Form generated from reading UI file 'confirmationdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIRMATIONDIALOG_H
#define UI_CONFIRMATIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConfirmationDialog
{
public:
    QPushButton *btn_reject;
    QPushButton *btn_accept;
    QLabel *label_question;

    void setupUi(QWidget *ConfirmationDialog)
    {
        if (ConfirmationDialog->objectName().isEmpty())
            ConfirmationDialog->setObjectName(QString::fromUtf8("ConfirmationDialog"));
        ConfirmationDialog->resize(300, 120);
        ConfirmationDialog->setMinimumSize(QSize(300, 120));
        ConfirmationDialog->setMaximumSize(QSize(300, 120));
        ConfirmationDialog->setStyleSheet(QString::fromUtf8("QWidget {\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: qradialgradient(cx:0.5, cy:0.5, radius: 0.6,\n"
"                fx:0.5, fy:0.5, stop:0 #1D2739, stop:1 #1D2024);\n"
"	alternate-background-color: rgb(30, 40, 50);\n"
"}"));
        btn_reject = new QPushButton(ConfirmationDialog);
        btn_reject->setObjectName(QString::fromUtf8("btn_reject"));
        btn_reject->setGeometry(QRect(30, 75, 100, 30));
        btn_reject->setMinimumSize(QSize(100, 30));
        btn_reject->setMaximumSize(QSize(100, 30));
        QFont font;
        font.setFamilies({QString::fromUtf8("Microsoft Sans Serif")});
        font.setPointSize(18);
        font.setBold(true);
        font.setItalic(false);
        font.setKerning(false);
        btn_reject->setFont(font);
        btn_reject->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        btn_accept = new QPushButton(ConfirmationDialog);
        btn_accept->setObjectName(QString::fromUtf8("btn_accept"));
        btn_accept->setGeometry(QRect(170, 75, 100, 30));
        btn_accept->setMinimumSize(QSize(100, 30));
        btn_accept->setMaximumSize(QSize(100, 30));
        btn_accept->setFont(font);
        btn_accept->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: rgb(230, 230, 230);\n"
"	background-color: qlineargradient(x1: 0, y1: 0.5, x2: 1, y2: 0.5,\n"
"                                      stop: 0 #07BEFF stop: 1 #2B74FF);\n"
"	alternate-background-color: qlineargradient(x1: 0, y1: 0.5, x2: 1, y2: 0.5,\n"
"                                      stop: 0 #07BEFF stop: 1 #2B74FF);\n"
"	border: 1px solid rgba(255, 255, 255, 0);\n"
"	border-radius: 14px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    color: rgb(230, 230, 230);\n"
"	background-color: qlineargradient(x1: 0.3, y1: 0.5, x2: 1, y2: 0.5,\n"
"                                      stop: 0 #02BFFF stop: 1 #2E73FF);\n"
"	alternate-background-color: qlineargradient(x1: 0.3, y1: 0.5, x2: 1, y2: 0.5,\n"
"                                      stop: 0 #02BFFF stop: 1 #2E73FF);\n"
"	border: 1px solid rgba(255, 255, 255, 0);\n"
"	border-radius: 14px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	color: rgb(255, 255, 255);\n"
"    background-color: qlineargradient(x1: 0.3, y1: 0.5, x2: 1, y2: 0.5,\n"
"  "
                        "                                    stop: 0 #02BFFF stop: 1 #2E73FF);\n"
"  alternate-background-color: qlineargradient(x1: 0.3, y1: 0.5, x2: 1, y2: 0.5,\n"
"                                      stop: 0 #02BFFF stop: 1 #2E73FF);\n"
"  border-radius: 14px;\n"
"}"));
        label_question = new QLabel(ConfirmationDialog);
        label_question->setObjectName(QString::fromUtf8("label_question"));
        label_question->setGeometry(QRect(0, 15, 300, 32));
        label_question->setMinimumSize(QSize(300, 32));
        label_question->setMaximumSize(QSize(300, 32));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Microsoft Sans Serif")});
        font1.setPointSize(20);
        font1.setBold(true);
        label_question->setFont(font1);
        label_question->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	alternate-background-color: rgba(0, 0, 0, 0);\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"	color: rgb(227, 226, 228);\n"
"}"));
        label_question->setAlignment(Qt::AlignCenter);

        retranslateUi(ConfirmationDialog);

        QMetaObject::connectSlotsByName(ConfirmationDialog);
    } // setupUi

    void retranslateUi(QWidget *ConfirmationDialog)
    {
        ConfirmationDialog->setWindowTitle(QCoreApplication::translate("ConfirmationDialog", "Form", nullptr));
        btn_reject->setText(QCoreApplication::translate("ConfirmationDialog", "Cancel", nullptr));
#if QT_CONFIG(shortcut)
        btn_reject->setShortcut(QCoreApplication::translate("ConfirmationDialog", "Esc", nullptr));
#endif // QT_CONFIG(shortcut)
        btn_accept->setText(QCoreApplication::translate("ConfirmationDialog", "Terminate", nullptr));
#if QT_CONFIG(shortcut)
        btn_accept->setShortcut(QCoreApplication::translate("ConfirmationDialog", "Return", nullptr));
#endif // QT_CONFIG(shortcut)
        label_question->setText(QCoreApplication::translate("ConfirmationDialog", "Terminate training process?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConfirmationDialog: public Ui_ConfirmationDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIRMATIONDIALOG_H
