#include "inputarea.h"

namespace s21 {

InputArea::InputArea(QColor color, int size, QWidget *parent)
    : color_(color), size_(size), QWidget{parent} {
    pen_ = new QPen();
    pen_->setColor(color_);
}

void InputArea::paintEvent(QPaintEvent *event) {
//    if (lmb_) {
//        painter_ = new QPainter(this);
//        pen_ = new QPen();
//        pen_->setColor(color_);
//        painter_->setPen(*pen_);
//        painter_->drawEllipse(circle_);
//        painter_->end();
//    }
}

void InputArea::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    lmb_ = event->button() == Qt::LeftButton;
    mouse_pos_ = event->pos();
    circle_.setRect(event->pos().x() - size_ / 2, event->pos().y() - size_ / 2, size_, size_);
    addEllipse(circle_, *pen_);
    prev_point_ = event->scenePos();

}

void InputArea::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
//    lmb_ = !(event->button() == Qt::LeftButton);
//    delete painter_;
//    delete pen_;
//    emit line_ended();
}

void InputArea::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    circle_.setRect(event->pos().x() - size_ / 2, event->pos().y() - size_ / 2, size_, size_);
    line_
    addLine(&prev_point_ )
}

}
