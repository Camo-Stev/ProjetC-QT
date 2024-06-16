#include "GraphPage.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QStringList>


GraphPage::GraphPage(TransactionManager* manager, QWidget *parent)
    : QWidget(parent), transactionManager(manager) {
    setupUI();
    connect(monthComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &GraphPage::onMonthYearChanged);
    connect(yearComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &GraphPage::onMonthYearChanged);
    connect(transactionManager, &TransactionManager::transactionsUpdated, this, &GraphPage::updateTransactionCount);
    updateTransactionCount();
}

void GraphPage::setupUI() {
    QVBoxLayout *layout = new QVBoxLayout(this);
    QHBoxLayout *hLayout = new QHBoxLayout();

    QPushButton *infoButton = new QPushButton("i");
    infoButton->setStyleSheet("font-weight: bold; font-size: 16px; width: 25px; height: 25px; border-radius: 12.5px; border: 1px solid black;");
    connect(infoButton, &QPushButton::clicked, this, &GraphPage::showInfo);

    hLayout->addWidget(infoButton, 0, Qt::AlignLeft);

    transactionCountLabel = new QLabel(this);
    hLayout->addWidget(transactionCountLabel);

    monthComboBox = new QComboBox();
    yearComboBox = new QComboBox();
    QStringList months = {"Janvier", "Février", "Mars", "Avril", "Mai", "Juin",
                          "Juillet", "Août", "Septembre", "Octobre", "Novembre", "Décembre"};
    for (int year = 2024; year <= 2030; ++year)
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
    // filterData(month, year);
}

QChart* GraphPage::createChart() {
    setIn = new QBarSet("Entrées");
    setOut = new QBarSet("Sorties");


    setIn->append(2500);
    setOut->append(2000);

    QBarSeries *series = new QBarSeries();
    series->append(setIn);
    series->append(setOut);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Transactions");
    chart->createDefaultAxes();

    return chart;
}

void GraphPage::showInfo() {
    QMessageBox::information(this, "Information sur le Graphique", "Ce graphique montre les transactions mensuelles. Les barres 'Entrées' et 'Sorties' représentent respectivement les revenus et les dépenses pour le mois sélectionné. Accompagné du nombre de transactions réalisées le mois en cours");
}

void GraphPage::updateGraph() {
    setIn->remove(0, setIn->count());
    setOut->remove(0, setOut->count());
    // Non fonctionnelle
}

void GraphPage::updateTransactionCount() {
    transactionCountLabel->setText("Nombre de transactions : 3");
}
