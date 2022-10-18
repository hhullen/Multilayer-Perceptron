#include "mainwindow.h"
#include "./ui_mainwindow.h"

namespace s21 {

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui_(new Ui::MainWindow) {
    ui_->setupUi(this);
    input_layout_= ui_->input_area->layout();
    input_widget_ = new InputArea(QColor::fromRgb(255,255,255), 30);
    scene_ = new QGraphicsView();
    scene_->setScene(input_widget_);
    scene_->setSceneRect(ui_->input_area->rect());
    scene_->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scene_->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    input_layout_->addWidget(scene_);
    connect(ui_->btn_cancel, &QAbstractButton::clicked, input_widget_, &InputArea::Clear);
    connect(input_widget_, &InputArea::line_ended, this, &MainWindow::ProcessPicture);
}

MainWindow::~MainWindow() {
    delete ui_;
    delete input_layout_;
    delete input_widget_;
    delete scene_;
}

void MainWindow::ProcessPicture() {
    QImage img = scene_->grab(ui_->input_area->rect()).toImage();
}


}

