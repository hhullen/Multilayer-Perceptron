/********************************************************************************
** Form generated from reading UI file 'testtablerow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTTABLEROW_H
#define UI_TESTTABLEROW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestTableRow
{
public:
    QLabel *label_f_measure;
    QLabel *label_recall;
    QLabel *label_precision;
    QLabel *label_letter;

    void setupUi(QWidget *TestTableRow)
    {
        if (TestTableRow->objectName().isEmpty())
            TestTableRow->setObjectName(QString::fromUtf8("TestTableRow"));
        TestTableRow->resize(422, 32);
        TestTableRow->setMinimumSize(QSize(422, 32));
        TestTableRow->setMaximumSize(QSize(422, 32));
        label_f_measure = new QLabel(TestTableRow);
        label_f_measure->setObjectName(QString::fromUtf8("label_f_measure"));
        label_f_measure->setGeometry(QRect(292, 0, 130, 32));
        label_f_measure->setMinimumSize(QSize(0, 0));
        label_f_measure->setMaximumSize(QSize(300, 32));
        QFont font;
        font.setFamilies({QString::fromUtf8("Microsoft Sans Serif")});
        font.setPointSize(23);
        font.setBold(true);
        label_f_measure->setFont(font);
        label_f_measure->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	alternate-background-color: rgba(0, 0, 0, 0);\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"	color: rgb(227, 226, 228);\n"
"}"));
        label_f_measure->setAlignment(Qt::AlignCenter);
        label_recall = new QLabel(TestTableRow);
        label_recall->setObjectName(QString::fromUtf8("label_recall"));
        label_recall->setGeometry(QRect(162, 0, 130, 32));
        label_recall->setMinimumSize(QSize(0, 0));
        label_recall->setMaximumSize(QSize(300, 32));
        label_recall->setFont(font);
        label_recall->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	alternate-background-color: rgba(0, 0, 0, 0);\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"	color: rgb(227, 226, 228);\n"
"}"));
        label_recall->setAlignment(Qt::AlignCenter);
        label_precision = new QLabel(TestTableRow);
        label_precision->setObjectName(QString::fromUtf8("label_precision"));
        label_precision->setGeometry(QRect(32, 0, 130, 32));
        label_precision->setMinimumSize(QSize(0, 0));
        label_precision->setMaximumSize(QSize(300, 32));
        label_precision->setFont(font);
        label_precision->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	alternate-background-color: rgba(0, 0, 0, 0);\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"	color: rgb(227, 226, 228);\n"
"}"));
        label_precision->setAlignment(Qt::AlignCenter);
        label_letter = new QLabel(TestTableRow);
        label_letter->setObjectName(QString::fromUtf8("label_letter"));
        label_letter->setGeometry(QRect(0, 0, 32, 32));
        label_letter->setMinimumSize(QSize(0, 0));
        label_letter->setMaximumSize(QSize(422, 32));
        label_letter->setFont(font);
        label_letter->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	alternate-background-color: rgba(0, 0, 0, 0);\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"	color: rgb(227, 226, 228);\n"
"}"));
        label_letter->setAlignment(Qt::AlignCenter);

        retranslateUi(TestTableRow);

        QMetaObject::connectSlotsByName(TestTableRow);
    } // setupUi

    void retranslateUi(QWidget *TestTableRow)
    {
        TestTableRow->setWindowTitle(QCoreApplication::translate("TestTableRow", "Form", nullptr));
        label_f_measure->setText(QCoreApplication::translate("TestTableRow", "F-Measure", nullptr));
        label_recall->setText(QCoreApplication::translate("TestTableRow", "Recall", nullptr));
        label_precision->setText(QCoreApplication::translate("TestTableRow", "Precision", nullptr));
        label_letter->setText(QCoreApplication::translate("TestTableRow", "A", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TestTableRow: public Ui_TestTableRow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTTABLEROW_H
