/********************************************************************************
** Form generated from reading UI file 'main_menu.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_MENU_H
#define UI_MAIN_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainMenu
{
public:
    QPushButton *btn_classifying;
    QPushButton *btn_learning;
    QPushButton *btn_testing;
    QPushButton *btn_setup;
    QLabel *label_name;
    QButtonGroup *group_btns;

    void setupUi(QWidget *MainMenu)
    {
        if (MainMenu->objectName().isEmpty())
            MainMenu->setObjectName(QString::fromUtf8("MainMenu"));
        MainMenu->resize(1039, 600);
        MainMenu->setMinimumSize(QSize(1039, 600));
        MainMenu->setMaximumSize(QSize(1039, 600));
        QFont font;
        font.setFamilies({QString::fromUtf8("Microsoft Sans Serif")});
        MainMenu->setFont(font);
        btn_classifying = new QPushButton(MainMenu);
        group_btns = new QButtonGroup(MainMenu);
        group_btns->setObjectName(QString::fromUtf8("group_btns"));
        group_btns->addButton(btn_classifying);
        btn_classifying->setObjectName(QString::fromUtf8("btn_classifying"));
        btn_classifying->setGeometry(QRect(320, 165, 400, 70));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Microsoft Sans Serif")});
        font1.setPointSize(45);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setKerning(false);
        btn_classifying->setFont(font1);
        btn_classifying->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        btn_learning = new QPushButton(MainMenu);
        group_btns->addButton(btn_learning);
        btn_learning->setObjectName(QString::fromUtf8("btn_learning"));
        btn_learning->setGeometry(QRect(320, 265, 400, 70));
        btn_learning->setFont(font1);
        btn_learning->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        btn_testing = new QPushButton(MainMenu);
        group_btns->addButton(btn_testing);
        btn_testing->setObjectName(QString::fromUtf8("btn_testing"));
        btn_testing->setGeometry(QRect(320, 365, 400, 70));
        btn_testing->setFont(font1);
        btn_testing->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        btn_setup = new QPushButton(MainMenu);
        group_btns->addButton(btn_setup);
        btn_setup->setObjectName(QString::fromUtf8("btn_setup"));
        btn_setup->setGeometry(QRect(10, 10, 32, 32));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Microsoft Sans Serif")});
        font2.setPointSize(40);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setKerning(false);
        btn_setup->setFont(font2);
        btn_setup->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        label_name = new QLabel(MainMenu);
        label_name->setObjectName(QString::fromUtf8("label_name"));
        label_name->setGeometry(QRect(270, 10, 500, 30));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Microsoft Sans Serif")});
        font3.setPointSize(23);
        font3.setBold(true);
        label_name->setFont(font3);
        label_name->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	alternate-background-color: rgba(0, 0, 0, 0);\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"	color: rgb(227, 226, 228);\n"
"}"));
        label_name->setAlignment(Qt::AlignCenter);

        retranslateUi(MainMenu);

        QMetaObject::connectSlotsByName(MainMenu);
    } // setupUi

    void retranslateUi(QWidget *MainMenu)
    {
        MainMenu->setWindowTitle(QCoreApplication::translate("MainMenu", "Form", nullptr));
        btn_classifying->setText(QCoreApplication::translate("MainMenu", "CLASSIFYING", nullptr));
        btn_learning->setText(QCoreApplication::translate("MainMenu", "TRAINING", nullptr));
        btn_testing->setText(QCoreApplication::translate("MainMenu", "TESTING", nullptr));
        btn_setup->setText(QCoreApplication::translate("MainMenu", "=", nullptr));
        label_name->setText(QCoreApplication::translate("MainMenu", "MAIN MENU", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainMenu: public Ui_MainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_MENU_H
