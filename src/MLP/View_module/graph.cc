#include "graph.h"
#include "ui_graph.h"

namespace s21 {

Graph::Graph(QWidget *parent) :
    QWidget(parent),
    ui_(new Ui::Graph), min_y_(0), max_y_(12),graph_(nullptr), view_(nullptr), series_(nullptr),
    axis_y_(nullptr), axis_x_(nullptr), interval_(10) {
    ui_->setupUi(this);

    SetupNewGraph();
    SetupNewView();
    SetupNewSeries();
    SetupNewAxisX();
    SetupNewAxisY();

    graph_->addSeries(series_);
    graph_->setAxisX(axis_x_);
    graph_->setAxisY(axis_y_);
    series_->attachAxis(axis_x_);
    series_->attachAxis(axis_y_);
    view_->setChart(graph_);
    ui_->gridLayout->addWidget(view_);
}

Graph::~Graph() {
    delete ui_;
}

void Graph::SetRangeX(size_t from, size_t to) {
    SetupNewAxisX();
    axis_x_->setRange(from, to);
    axis_x_->setTickType(QValueAxis::TicksDynamic);
    axis_x_->setTickInterval((qAbs(to) - qAbs(from)) / interval_);
    graph_->setAxisX(axis_x_, series_);
    Update();
}

void Graph::SetRangeY(double from, double to) {
    SetupNewAxisY();
    max_y_ = to;
    min_y_ = from;
    axis_y_->setRange(min_y_, max_y_);
    graph_->setAxisY(axis_y_, series_);
    Update();
}

void Graph::SetXGridInterval(double value) {
    interval_ = value;
    Update();
}

void Graph::AddPoint(double x, double y) {
    if (y > max_y_) {
        max_y_ = y + 1;
        SetRangeY(min_y_, max_y_);
    } else if (y < min_y_) {
        min_y_ = y - 1;
        SetRangeY(min_y_, max_y_);
    }
    series_->append(QPointF(x, y));
}

void Graph::Clear() {
    series_->clear();
    Update();
}

void Graph::Update() {
    graph_->update();
    view_->update();
    view_->repaint();
}

void Graph::SetupNewGraph() {
    graph_ = new QChart();
    graph_->setMargins(QMargins(0,0,0,0));
    graph_->setBackgroundBrush(Qt::transparent);
    graph_->legend()->hide();
    graph_->createDefaultAxes();
    graph_->setAnimationOptions(QChart::AllAnimations);
}

void Graph::SetupNewView() {
    view_ = new QChartView();
    view_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QLinearGradient color_bg(0, 0.5, 1, 0.5);
    color_bg.setColorAt(1, QColor(9,40,83));
    color_bg.setColorAt(0, QColor(14,20,27));
    color_bg.setCoordinateMode(QGradient::ObjectBoundingMode);
    view_->setBackgroundBrush(color_bg);
    view_->setRenderHint(QPainter::Antialiasing);
}

void Graph::SetupNewSeries() {
    if (series_) {
        series_->clear();
        delete series_;
    }
    series_ = new QSplineSeries();
    series_->setPen(QPen(QColor(89,191,64), 1, Qt::SolidLine, Qt::RoundCap));
}

void Graph::SetupNewAxisX() {
        if (axis_x_) {
            delete axis_x_;
        }
    axis_x_= new QValueAxis();
    axis_x_->setGridLineColor(QColor(21,68,102));
    axis_x_->setLinePenColor(QColor(21,68,102));
    axis_x_->setLabelsColor(QColor(200, 200, 200));
}

void Graph::SetupNewAxisY() {
    if (axis_y_) {
        delete axis_y_;
    }
    axis_y_ = new QValueAxis();
    axis_y_->setGridLineColor(QColor(21,68,102));
    axis_y_->setLinePenColor(QColor(21,68,102));
    axis_y_->setLabelsColor(QColor(255, 255, 255));
}

}
