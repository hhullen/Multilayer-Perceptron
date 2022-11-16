#ifndef CLASSIFIER_H
#define CLASSIFIER_H

#include <QGraphicsView>
#include <QVBoxLayout>
#include <QWidget>
#include <vector>
#include <QPushButton>
#include <QFileDialog>
#include <QLabel>

#include "inputarea.h"
using std::vector;

const int kIMAGE_SIZE = 28;
const int kBMP_IMAGE_ZISE = 512;

namespace Ui {
class Classifier;
}

namespace s21 {

enum InputMode { DRAW, IMAGE };

class Classifier : public QWidget {
  Q_OBJECT

 public:
  explicit Classifier(QWidget *parent = nullptr);
  ~Classifier();
    vector<double> *GetPixelsVector();
    void SetConfidence(double value);
    void SetAnswerLetter(char sym);

signals:
    void BackSignal();
    void ClassifierAchtungSignal(QString message);
    void ReadySignal();

 private:
  Ui::Classifier *ui_;
  QWidget *main_widget_;
  QVBoxLayout *input_layout_;
  InputArea *input_widget_;
  QGraphicsView *scene_;
  QGraphicsScene *image_scene_;
  vector<double> pixels_;
  QImage input_image_;
  QLabel *image_;
  QLabel *file_name_;
  QPushButton *btn_open_img_;
  QPushButton *btn_close_img_;

  void PrimarySetupInputArea();
  void ProcessPicture();
  void ChangeMode(int index);
  void OpenBMPImage();
  void CloseBMPImage();
  void GetPixels(QImage &img);
};

}  // namespace s21

#endif  // CLASSIFIER_H
