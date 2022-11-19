#ifndef CONFIRMATIONDIALOG_H
#define CONFIRMATIONDIALOG_H

#include <QDialog>
#include <QWidget>

namespace Ui {
class ConfirmationDialog;
}

namespace s21 {

enum DialogState { ACCEPTED, REJECTED };

class ConfirmationDialog : public QDialog {
  Q_OBJECT

 public:
  explicit ConfirmationDialog(QWidget *parent = nullptr,
                              QString question = "wassup!");
  ~ConfirmationDialog();

 private:
  Ui::ConfirmationDialog *ui_;

  void SetAcceted();
  void SetRejected();
};

}  // namespace s21

#endif  // CONFIRMATIONDIALOG_H
