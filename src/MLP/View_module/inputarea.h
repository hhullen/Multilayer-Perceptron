#ifndef INPUTAREA_H
#define INPUTAREA_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

namespace s21 {

class InputArea : public QGraphicsScene {
    Q_OBJECT
public:
    explicit InputArea(QColor color, int size, QObject *parent = nullptr);
    ~InputArea();

    void Clear();

signals:
    void line_ended();

private slots:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

private:
    QColor color_;
    int size_;
    QPen *pen_;
    QBrush *brush_;
    QRectF circle_;
    QLineF line_;
    QPointF prev_point_;
};

}

#endif // INPUTAREA_H
