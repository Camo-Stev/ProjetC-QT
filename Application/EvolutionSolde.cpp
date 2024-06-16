#include "EvolutionSolde.h"
#include <QtCharts>

using namespace QtCharts;

EvolutionSolde::EvolutionSolde(QWidget *parent) : QWidget(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(createChart());
}

QChartView *EvolutionSolde::createChart() const {
    QLineSeries *series = new QLineSeries();

    series->append(QDate(2024, 1, 1).startOfDay().toMSecsSinceEpoch(), -1200.00);
    series->append(QDate(2024, 1, 5).startOfDay().toMSecsSinceEpoch(), 1300.00);
    series->append(QDate(2024, 1, 10).startOfDay().toMSecsSinceEpoch(), 500.00);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Évolution du Solde du Compte");

    QDateTimeAxis *axisX = new QDateTimeAxis();
    axisX->setFormat("dd MMM yyyy");
    axisX->setTitleText("Date");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setLabelFormat("%.2f €");
    axisY->setTitleText("Solde");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    return chartView;
}
