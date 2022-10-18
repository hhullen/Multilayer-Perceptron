#ifndef INPUTAREA_H
#define INPUTAREA_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>

namespace s21 {

class InputArea : public QWidget {
    Q_OBJECT
public:
    explicit InputArea(QColor color, int size, QWidget *parent = nullptr);
    virtual void paintEvent(QPaintEvent *event) override;

signals:
    void line_ended();

private slots:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private:
    QColor color_;
    int size_;
    bool lmb_;
    QPainter *painter_;
    QPen *pen_;
    QPoint mouse_pos_;
    QRect circle_;
};

}

#endif // INPUTAREA_H
