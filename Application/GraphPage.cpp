#include "GraphPage.h"
#include <QVBoxLayout>
#include <QChartView>

GraphPage::GraphPage(TransactionManager* manager, QWidget *parent)
    : QWidget(parent), transactionManager(manager) {

    QVBoxLayout *layout = new QVBoxLayout(this);

    chart = createChart();
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    layout->addWidget(chartView);

    connect(manager, &TransactionManager::transactionsUpdated, this, &GraphPage::updateGraph);
}

void GraphPage::updateGraph() {
    setIn->remove(0, setIn->count());
    setOut->remove(0, setOut->count());

    for (const Transaction& transaction : transactionManager->transactions) {
        if (transaction.amount > 0) {
            *setIn << transaction.amount;
        } else {
            *setOut << -transaction.amount;
        }
    }
    chart->update();
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
