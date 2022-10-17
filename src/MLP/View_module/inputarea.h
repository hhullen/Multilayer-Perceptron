#ifndef INPUTAREA_H
#define INPUTAREA_H

#include <QWidget>
#include <QPainter>

namespace s21 {

class InputArea : public QWidget {
    Q_OBJECT
public:
    explicit InputArea(QWidget *parent = nullptr);
    virtual void paintEvent(QPaintEvent *event);

signals:

};

}

#endif // INPUTAREA_H
