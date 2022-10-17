#include "mainwindow.h"
#include "./ui_mainwindow.h"

namespace s21 {

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui_(new Ui::MainWindow) {
    ui_->setupUi(this);
    input_widget_ = new InputArea();
    input_layout_= ui_->input_area->layout();
    input_layout_->addWidget(input_widget_);
}

MainWindow::~MainWindow() {
    delete ui_;
}

void MainWindow::paintEvent(QPaintEvent *event) {
//    QPainter painter(input_widget_);
//    QPen pen;
//    pen.setColor(QColor::fromRgb(255,255,255));
//    painter.setPen(pen);
//    painter.drawEllipse(0,00, 200, 200);
}

}

