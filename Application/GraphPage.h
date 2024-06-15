#ifndef GRAPHPAGE_H
#define GRAPHPAGE_H

#include <QWidget>
#include <QtCharts>
#include "TransactionManager.h"

using namespace QtCharts;

class GraphPage : public QWidget {
    Q_OBJECT
public:
    explicit GraphPage(TransactionManager* manager, QWidget *parent = nullptr);

private slots:
    void updateGraph();

private:
    QChart* createChart();

    TransactionManager* transactionManager;
    QChart* chart;
    QBarSet* setIn;
    QBarSet* setOut;
};

#endif // GRAPHPAGE_H
