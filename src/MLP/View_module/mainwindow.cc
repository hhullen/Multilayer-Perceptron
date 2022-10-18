#include "mainwindow.h"
#include "./ui_mainwindow.h"

namespace s21 {

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui_(new Ui::MainWindow) {
    ui_->setupUi(this);
    input_widget_ = new InputArea(10);
    input_layout_= ui_->input_area->layout();
    input_layout_->addWidget(input_widget_);
    QLayout *n = new QGridLayout();
    input_widget_->setLayout(n);

    InputArea *input_widget = new InputArea(10);
    n->addWidget(input_widget);
    input_widget->move(0,0);


//    QImage img = input_widget_->grab(input_widget_->rect()).toImage();
//    img.save("/Users/hhullen/PROJECTS/github/Multilayer-Perceptron/src/img.jpeg", "JPEG");
}

MainWindow::~MainWindow() {
    delete ui_;
}

void MainWindow::paintEvent(QPaintEvent *event) {
//    QPainter painter(input_widget_);
//    QPen pen;
//    pen.setColor(QColor::fromRgb(255,255,255));
//    painter.setPen(pen);
//    painter.drawEllipse(10,10, 20, 20);
}

}

