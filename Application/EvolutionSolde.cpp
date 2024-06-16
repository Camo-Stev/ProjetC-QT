#include "EvolutionSolde.h"
#include <QtCharts>
#include <QPushButton>
#include <QMessageBox>

using namespace QtCharts;

EvolutionSolde::EvolutionSolde(QWidget *parent) : QWidget(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);

    QPushButton *infoButton = new QPushButton("i");
    infoButton->setStyleSheet("font-weight: bold; font-size: 16px; width: 25px; height: 25px; border-radius: 12.5px; border: 1px solid black;");
    connect(infoButton, &QPushButton::clicked, this, &EvolutionSolde::showInfo);

    layout->addWidget(infoButton, 0, Qt::AlignTop | Qt::AlignRight);
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

void EvolutionSolde::showInfo() {
    QMessageBox::information(this, "Information sur le Graphique", "Ce graphique montre l'évolution du solde de votre compte bancaire. Chaque point représente le solde à une date donnée, après les transactions enregistrées.");
}
