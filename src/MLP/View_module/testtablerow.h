#ifndef TESTTABLEROW_H
#define TESTTABLEROW_H

#include <QWidget>

namespace Ui {
class TestTableRow;
}

namespace s21 {

class TestTableRow : public QWidget
{
    Q_OBJECT

public:
    explicit TestTableRow(QWidget *parent = nullptr);
    ~TestTableRow();
    void SetLetter(QChar letter);
    void SetPrecision(double value);
    void SetRecall(double value);
    void SetFMeasure(double value);

private:
    Ui::TestTableRow *ui_;
};

}

#endif // TESTTABLEROW_H
