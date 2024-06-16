#include "GraphPage.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QtCharts>
#include <QStringList>

GraphPage::GraphPage(TransactionManager* manager, QWidget *parent)
    : QWidget(parent), transactionManager(manager) {
    setupUI();
    connect(monthComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &GraphPage::onMonthYearChanged);
    connect(yearComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &GraphPage::onMonthYearChanged);
}

void GraphPage::setupUI() {
    QVBoxLayout *layout = new QVBoxLayout(this);
    QHBoxLayout *hLayout = new QHBoxLayout();
    monthComboBox = new QComboBox();
    yearComboBox = new QComboBox();
    QStringList months = {"Janvier", "Février", "Mars", "Avril", "Mai", "Juin",
                          "Juillet", "Août", "Septembre", "Octobre", "Novembre", "Décembre"};
    for (int year = 2020; year <= 2030; ++year)
        yearComboBox->addItem(QString::number(year));
    monthComboBox->addItems(months);
    hLayout->addWidget(monthComboBox);
    hLayout->addWidget(yearComboBox);
    layout->addLayout(hLayout);

    chart = createChart();
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    layout->addWidget(chartView);
}

void GraphPage::onMonthYearChanged() {
    int month = monthComboBox->currentIndex() + 1;
    int year = yearComboBox->currentText().toInt();
    //filterData(month, year);
}


QChart* GraphPage::createChart() {
    setIn = new QBarSet("Entrées");
    setOut = new QBarSet("Sorties");

    QBarSeries *series = new QBarSeries();
    series->append(setIn);
    series->append(setOut);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Transactions");
    chart->createDefaultAxes();

    return chart;
}

void GraphPage::updateGraph() {
    setIn->remove(0, setIn->count());
    setOut->remove(0, setOut->count());
    // Supposez de remplir à nouveau les données ici, basées sur les transactions filtrées
}
