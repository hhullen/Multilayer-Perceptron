#include "inputarea.h"

namespace s21 {

InputArea::InputArea(QColor color, int size, QObject *parent)
    : color_(color), size_(size), QGraphicsScene{parent} {
  pen_ = new QPen(color_, size_, Qt::SolidLine, Qt::RoundCap);
  brush_ = new QBrush(color_, Qt::SolidPattern);
  lmb_ = false;
}

InputArea::~InputArea() {
  if (pen_)delete pen_;
  pen_ = nullptr;
  if (brush_) delete brush_;
  brush_ = nullptr;
}

void InputArea::Clear() { clear(); }

void InputArea::mousePressEvent(QGraphicsSceneMouseEvent *event) {
  if (event->button() == Qt::LeftButton) {
    circle_.setRect(event->scenePos().x() - size_ / 2,
                    event->scenePos().y() - size_ / 2, size_, size_);
    addEllipse(circle_, QPen(Qt::NoPen), *brush_);
    prev_point_ = event->scenePos();
    lmb_ = true;
  } else if (event->button() == Qt::RightButton) {
    Clear();
  }
}

void InputArea::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
  lmb_ = false;
  if (event->button() == Qt::LeftButton) {
    emit line_ended();
  }
}

void InputArea::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
  if (lmb_) {
    line_.setPoints(prev_point_, event->scenePos());
    prev_point_ = event->scenePos();
    addLine(line_, *pen_);
  }
}

}  // namespace s21
