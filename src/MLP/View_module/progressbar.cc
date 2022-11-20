#include "progressbar.h"

#include "ui_progressbar.h"

namespace s21 {

ProgressBar::ProgressBar(QWidget *parent)
    : QWidget(parent), ui_(new Ui::ProgressBar) {
  ui_->setupUi(this);
}

ProgressBar::~ProgressBar() { if (ui_) delete ui_;
                            ui_ = nullptr;
                            }

void ProgressBar::SetProgressValue(size_t value) {
  if (value > 100) {
    value = 100;
  }
  progress_ = value;
  Resize(value);
}

void ProgressBar::SetName(QString name) { ui_->label_progress->setText(name); }

void ProgressBar::SetWidth(size_t w) {
  setFixedWidth(w);
  Resize(ui_->widget_line->width());
}

void ProgressBar::resizeEvent(QResizeEvent *event) {
  Resize(event->size().width());
}

void ProgressBar::Resize(size_t sizer) {
  size_t max = width();
  size_t height = ui_->widget_line_bg->height();
  if (sizer == 0) {
    height = 0;
  }
  double coeff = progress_ / 100.0;
  size_t new_width = (size_t)max * coeff + height;
  if (new_width > max) {
    new_width = max;
  }
  ui_->widget_line->setFixedWidth(new_width);
}

}  // namespace s21
