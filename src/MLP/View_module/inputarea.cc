#include "inputarea.h"

namespace s21 {

InputArea::InputArea(int r, QWidget *parent)
    : QWidget{parent} {
    r_ = r;
}

void InputArea::paintEvent(QPaintEvent *event) {
    QPainter *painter = new QPainter(this);
    QPen pen;
    pen.setColor(QColor::fromRgb(255,255,255));
    painter->setPen(pen);
    painter->drawEllipse(r_,10, 20, 20);
    painter->end();


    QPainter painter1(this);
    QPen pen1;
    pen1.setColor(QColor::fromRgb(255,255,255));
    painter1.setPen(pen1);
    painter1.drawEllipse(r_, 10, 40, 40);
    painter1.end();

//    QTimer t;
//    connect(&t, &QTimer::timeout, &painter, &QPainter::restore);
//    t.start(2000);
}

}
