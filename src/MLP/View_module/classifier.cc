#include "classifier.h"

#include "ui_classifier.h"

namespace s21 {

Classifier::Classifier(QWidget *parent)
    : QWidget(parent), ui_(new Ui::Classifier) {
  ui_->setupUi(this);

    PrimarySetupInputArea();

  connect(input_widget_, &InputArea::line_ended, this,
          &Classifier::ProcessPicture);
  connect(ui_->btn_back_menu, &QPushButton::clicked, this, &Classifier::BackSignal);
  connect(ui_->combo_box, &QComboBox::currentIndexChanged, this, &Classifier::ChangeMode);
  connect(btn_open_img_, &QPushButton::clicked, this, &Classifier::OpenBMPImage);
  connect(btn_close_img_, &QPushButton::clicked, this, &Classifier::CloseBMPImage);
}

Classifier::~Classifier() {
  delete ui_;
  delete input_widget_;
    delete scene_;
}

vector<double> *Classifier::GetPixelsVector() {
    return &pixels_;
}

void Classifier::SetConfidence(double value) {
    if (value > 100) {
        value = 100;
    } else if (value < 0) {
        value = 0;
    }
    ui_->label_percent_value->setText(QString::number(value, 'f', 3).append("%"));
}

void Classifier::SetAnswerLetter(char sym) {
    if (sym >= 'A' && sym <= 'Z') {
        ui_->label_output_latter->setText(QString(sym));
    }
}

void Classifier::PrimarySetupInputArea() {
    ui_->btn_open_img->setVisible(false);
    ui_->btn_close_img->setVisible(false);
    input_layout_ = new QVBoxLayout();
    input_layout_->setAlignment(Qt::AlignTop);
    input_layout_->setSpacing(0);
    input_layout_->setContentsMargins(0, 0, 0, 0);
    ui_->input_area->setLayout(input_layout_);
    input_widget_ = new InputArea(QColor::fromRgb(255, 255, 255), 30);
    scene_ = new QGraphicsView();
    scene_->setScene(input_widget_);
    scene_->setSceneRect(ui_->input_area->rect());
    scene_->setBackgroundBrush(QBrush(Qt::black));
    scene_->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scene_->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    main_widget_ = scene_;
    input_layout_->addWidget(main_widget_);
    ui_->combo_box->setCurrentIndex(0);
    image_ =  ui_->input_image;
    btn_open_img_ = ui_->btn_open_img;
    btn_close_img_ = ui_->btn_close_img;
    file_name_ = ui_->label_bmp_file_name;
    file_name_->clear();
}

void Classifier::ProcessPicture() {
  QImage input_screen = scene_->grab().toImage();
  input_screen.save("/Users/hhullen/PROJECTS/CPP7_MLP-0/src/screen.bmp",
                    "BMP");
  input_screen =
      input_screen.scaled(kIMAGE_SIZE, kIMAGE_SIZE, Qt::AspectRatioMode::KeepAspectRatio,
                          Qt::TransformationMode::SmoothTransformation);
//  input_screen.save("/Users/hhullen/PROJECTS/CPP7_MLP-0/src/screen.bmp",
//                    "BMP");

  input_screen.invertPixels();
  GetPixels(input_screen);
}

void Classifier::ChangeMode(int index) {
    if (index == InputMode::DRAW) {
        ui_->combo_box->setCurrentIndex(index);
        CloseBMPImage();
        btn_open_img_->setVisible(false);
        btn_close_img_->setVisible(false);
        scene_->setVisible(true);
    } else if (index == InputMode::IMAGE) {
        ui_->combo_box->setCurrentIndex(index);
        scene_->setVisible(false);
        input_layout_->removeWidget(scene_);
        btn_open_img_->setVisible(true);
        btn_close_img_->setVisible(false);
    }
}

void Classifier::OpenBMPImage() {
    QString file_path = QFileDialog::getOpenFileName(this, "Open .bmp file", "/Users",
                                                "bmp (*.bmp);;");
    if (!file_path.isEmpty()) {
        file_name_->setText(file_path);
        input_image_.load(file_path);
        if (input_image_.height() != kBMP_IMAGE_ZISE && input_image_.width() != kBMP_IMAGE_ZISE) {
            CloseBMPImage();
            emit ClassifierAchtungSignal("Can't open the picture with size different from 512x512");
            file_name_->clear();
        } else {
            image_->setPixmap(QPixmap::fromImage(input_image_));
            btn_open_img_->setVisible(false);
            btn_close_img_->setVisible(true);
            input_image_ = input_image_.scaled(kIMAGE_SIZE, kIMAGE_SIZE, Qt::AspectRatioMode::KeepAspectRatio,
                                Qt::TransformationMode::SmoothTransformation);
            input_image_.invertPixels();
            GetPixels(input_image_);
        }
    }
}

void Classifier::CloseBMPImage() {
    image_->clear();
    file_name_->clear();
    btn_close_img_->setVisible(false);
    btn_open_img_->setVisible(true);
}

void Classifier::GetPixels(QImage &img) {
    pixels_.clear();

    for (size_t i = 0; i < img.width(); ++i) {
      for (size_t j = 0; j < img.height(); ++j) {
        pixels_.push_back(img.pixelColor(i, j).black() / 255.0);
      }
    }
    emit ReadySignal();
}

}  // namespace s21
