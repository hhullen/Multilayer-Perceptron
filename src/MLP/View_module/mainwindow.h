#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include "inputarea.h"
#include "Controller_module/mlp_controller.h"
#include "Model_module/perceptron.h"
using s21::Perceptron;
using s21::MLPController;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

namespace s21 {

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui_;
    QLayout *input_layout_;
    InputArea *input_widget_;
    QGraphicsView *scene_;

    void ProcessPicture();
};

}

#endif // MAINWINDOW_H
