#include "inputarea.h"

namespace s21 {

InputArea::InputArea(QWidget *parent)
    : QWidget{parent} {}

void InputArea::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    QPen pen;
    pen.setColor(QColor::fromRgb(255,255,255));
    painter.setPen(pen);
    painter.drawEllipse(0,00, 200, 200);
}

}
