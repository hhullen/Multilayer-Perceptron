#include "inputarea.h"

namespace s21 {

InputArea::InputArea(QColor color, int size, QWidget *parent)
    : color_(color), size_(size), QWidget{parent} {
}

void InputArea::paintEvent(QPaintEvent *event) {
    if (lmb_) {
        painter_ = new QPainter(this);
        pen_ = new QPen();
        pen_->setColor(color_);
        painter_->setPen(*pen_);
        painter_->drawEllipse(circle_);
        painter_->end();
    }
}

void InputArea::mousePressEvent(QMouseEvent *event) {
    lmb_ = event->button() == Qt::LeftButton;
    mouse_pos_ = event->pos();
    circle_.setRect(event->pos().x() - size_ / 2, event->pos().y() - size_ / 2, event->pos().x() + size_, event->pos().y() + size_);
}

void InputArea::mouseReleaseEvent(QMouseEvent *event) {
    lmb_ = !(event->button() == Qt::LeftButton);
    delete painter_;
    delete pen_;
    emit line_ended();
}

void InputArea::mouseMoveEvent(QMouseEvent *event) {
    circle_.setRect(event->pos().x() - size_ / 2, event->pos().y() - size_ / 2, event->pos().x() + size_, event->pos().y() + size_);
}

}
