#include "confirmationdialog.h"

#include "ui_confirmationdialog.h"

namespace s21 {

ConfirmationDialog::ConfirmationDialog(QWidget *parent, QString question)
    : QDialog(parent), ui_(new Ui::ConfirmationDialog) {
  ui_->setupUi(this);
  ui_->label_question->setText(question);
  setWindowTitle("");

  connect(ui_->btn_accept, &QPushButton::clicked, this,
          &ConfirmationDialog::SetAcceted);
  connect(ui_->btn_reject, &QPushButton::clicked, this,
          &ConfirmationDialog::SetRejected);
}

ConfirmationDialog::~ConfirmationDialog() {
  if (ui_) delete ui_;
  ui_ = nullptr;
}

void ConfirmationDialog::SetAcceted() {
  accept();
  close();
}

void ConfirmationDialog::SetRejected() {
  reject();
  close();
}

}  // namespace s21
