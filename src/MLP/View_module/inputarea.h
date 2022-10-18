#ifndef INPUTAREA_H
#define INPUTAREA_H

#include <QWidget>
#include <QPainter>
#include <QTimer>

namespace s21 {

class InputArea : public QWidget {
    Q_OBJECT
public:
    explicit InputArea(int r, QWidget *parent = nullptr);
    virtual void paintEvent(QPaintEvent *event);

signals:

private:
    int r_ = 0;

};

}

#endif // INPUTAREA_H
