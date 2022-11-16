#ifndef INPUTAREA_H
#define INPUTAREA_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>
#include <QPainter>
#include <QWidget>

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
  bool lmb_;
};

}  // namespace s21

#endif  // INPUTAREA_H
