#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H

#include <QWidget>
#include <QResizeEvent>

namespace Ui {
class ProgressBar;
}

namespace s21 {

class ProgressBar : public QWidget {
    Q_OBJECT

public:
    explicit ProgressBar(QWidget *parent = nullptr);
    ~ProgressBar();
    void SetProgressValue(size_t value);
    void SetName(QString name);
    void SetWidth(size_t w);

private:
    Ui::ProgressBar *ui_;
    void resizeEvent(QResizeEvent *event);
    void Resize(size_t sizer);
    size_t progress_;
};

}

#endif // PROGRESSBAR_H
