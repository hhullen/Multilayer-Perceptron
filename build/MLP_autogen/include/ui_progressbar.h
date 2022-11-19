/********************************************************************************
** Form generated from reading UI file 'progressbar.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROGRESSBAR_H
#define UI_PROGRESSBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProgressBar
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_progress;
    QWidget *widget_line_bg;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_line;

    void setupUi(QWidget *ProgressBar)
    {
        if (ProgressBar->objectName().isEmpty())
            ProgressBar->setObjectName(QString::fromUtf8("ProgressBar"));
        ProgressBar->resize(200, 30);
        ProgressBar->setMinimumSize(QSize(200, 30));
        ProgressBar->setMaximumSize(QSize(16777215, 30));
        verticalLayout = new QVBoxLayout(ProgressBar);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_progress = new QLabel(ProgressBar);
        label_progress->setObjectName(QString::fromUtf8("label_progress"));
        label_progress->setMinimumSize(QSize(200, 20));
        label_progress->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setFamilies({QString::fromUtf8("Microsoft Sans Serif")});
        font.setPointSize(14);
        font.setBold(false);
        label_progress->setFont(font);
        label_progress->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	alternate-background-color: rgba(0, 0, 0, 0);\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"	color: rgb(127, 126, 128);\n"
"}"));
        label_progress->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        verticalLayout->addWidget(label_progress);

        widget_line_bg = new QWidget(ProgressBar);
        widget_line_bg->setObjectName(QString::fromUtf8("widget_line_bg"));
        widget_line_bg->setMinimumSize(QSize(200, 10));
        widget_line_bg->setMaximumSize(QSize(16777215, 16777215));
        widget_line_bg->setStyleSheet(QString::fromUtf8("QWidget {\n"
"	background-color: rgb(27,40,56);\n"
"	alternate-background-color: rgb(27,40,56);\n"
"	border-radius: 5px;\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(widget_line_bg);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_line = new QWidget(widget_line_bg);
        widget_line->setObjectName(QString::fromUtf8("widget_line"));
        widget_line->setMinimumSize(QSize(10, 10));
        widget_line->setMaximumSize(QSize(16777215, 10));
        widget_line->setStyleSheet(QString::fromUtf8("QWidget {\n"
"	background-color: qlineargradient(x1: 0, y1: 0.5, x2: 1, y2: 0.5,\n"
"                                      stop: 0 #2B74FF stop: 1 #07BEFF);\n"
"	alternate-background-color: qlineargradient(x1: 0, y1: 0.5, x2: 1, y2: 0.5,\n"
"                                      stop: 0 #2B74FF stop: 1 #07BEFF);\n"
"	border-radius: 5px;\n"
"}"));

        verticalLayout_2->addWidget(widget_line);


        verticalLayout->addWidget(widget_line_bg);


        retranslateUi(ProgressBar);

        QMetaObject::connectSlotsByName(ProgressBar);
    } // setupUi

    void retranslateUi(QWidget *ProgressBar)
    {
        ProgressBar->setWindowTitle(QCoreApplication::translate("ProgressBar", "Form", nullptr));
        label_progress->setText(QCoreApplication::translate("ProgressBar", "Progress: ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProgressBar: public Ui_ProgressBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROGRESSBAR_H
