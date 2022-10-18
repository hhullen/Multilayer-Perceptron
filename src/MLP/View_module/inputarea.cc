#include "inputarea.h"

namespace s21 {

InputArea::InputArea(QColor color, int size, QObject *parent)
    : color_(color), size_(size), QGraphicsScene{parent} {
    pen_ = new QPen(color_, size_, Qt::SolidLine, Qt::RoundCap);
    brush_ = new QBrush(color_, Qt::SolidPattern);
}

InputArea::~InputArea() {
    delete pen_;
    delete brush_;
}

void InputArea::Clear() {
    clear();
}



void InputArea::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
    circle_.setRect(event->scenePos().x() - size_ / 2, event->scenePos().y() - size_ / 2, size_ , size_);
    addEllipse(circle_, QPen(Qt::NoPen), *brush_);
    prev_point_ = event->scenePos();
    }
}

void InputArea::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    emit line_ended();
}

void InputArea::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    line_.setPoints(prev_point_, event->scenePos());
    prev_point_ = event->scenePos();
    addLine(line_, *pen_);
}

}
