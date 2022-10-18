#ifndef INPUTAREA_H
#define INPUTAREA_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

namespace s21 {

class InputArea : public QWidget, public QGraphicsScene {
    Q_OBJECT
public:
    explicit InputArea(QColor color, int size, QWidget *parent = nullptr);
    virtual void paintEvent(QPaintEvent *event) override;

signals:
    void line_ended();

private slots:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

private:
    QColor color_;
    int size_;
    bool lmb_;
    QPainter *painter_;
    QPen *pen_;
    QPointF mouse_pos_;
    QRectF circle_;
    QLineF line_;
    QPointF prev_point_;
};

}

#endif // INPUTAREA_H
