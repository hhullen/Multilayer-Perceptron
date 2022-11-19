#include "testtablerow.h"

#include "ui_testtablerow.h"

namespace s21 {

TestTableRow::TestTableRow(QWidget *parent)
    : QWidget(parent), ui_(new Ui::TestTableRow) {
  ui_->setupUi(this);
}

TestTableRow::~TestTableRow() { delete ui_; }

void TestTableRow::SetLetter(QChar letter) {
  ui_->label_letter->setText(letter);
}

void TestTableRow::SetPrecision(double value) {
  ui_->label_precision->setText(QString::number(value, 'f', 3));
}

void TestTableRow::SetRecall(double value) {
  ui_->label_recall->setText(QString::number(value, 'f', 3));
}

void TestTableRow::SetFMeasure(double value) {
  ui_->label_f_measure->setText(QString::number(value, 'f', 3));
}

}  // namespace s21
