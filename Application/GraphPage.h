#ifndef GRAPHPAGE_H
#define GRAPHPAGE_H

#include <QWidget>
#include <QtCharts>
#include <QComboBox>
#include "TransactionManager.h"

using namespace QtCharts;

class GraphPage : public QWidget {
    Q_OBJECT

public:
    explicit GraphPage(TransactionManager *manager, QWidget *parent = nullptr);
    void updateGraph();

private:
    TransactionManager *transactionManager;
    QChart *chart;
    QBarSet *setIn;
    QBarSet *setOut;
    QComboBox *monthComboBox;
    QComboBox *yearComboBox;

    void setupUI();
    QChart* createChart();  // Modifier pour retourner QChart*

public slots:
    void onMonthYearChanged();
};

#endif // GRAPHPAGE_H
