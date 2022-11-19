#ifndef GRAPH_H
#define GRAPH_H

#include <QChart>
#include <QChartView>
#include <QSplineSeries>
#include <QValueAxis>
#include <QWidget>
#include <QtMath>

namespace Ui {
class Graph;
}

namespace s21 {

class Graph : public QWidget {
  Q_OBJECT

 public:
  explicit Graph(QWidget *parent = nullptr);
  ~Graph();
  void SetRangeX(size_t from, size_t to);
  void SetRangeY(double from, double to);
  void SetXGridInterval(double value);
  void AddPoint(double x, double y);
  void Clear();

 private:
  Ui::Graph *ui_;
  QChart *graph_;
  QChartView *view_;
  QSplineSeries *series_;
  QValueAxis *axis_y_;
  QValueAxis *axis_x_;
  double max_y_;
  double min_y_;
  double interval_;

  void Update();
  void SetupNewGraph();
  void SetupNewView();
  void SetupNewSeries();
  void SetupNewAxisX();
  void SetupNewAxisY();
};

}  // namespace s21

#endif  // GRAPH_H
