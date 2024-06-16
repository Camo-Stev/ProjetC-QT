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
    void displayTransactionCount() const;
    void showInfo();



private:
    TransactionManager *transactionManager;
    QChart *chart;
    QBarSet *setIn;
    QBarSet *setOut;
    QComboBox *monthComboBox;
    QComboBox *yearComboBox;
    QLabel* transactionCountLabel;

    void setupUI();
    QChart* createChart();

public slots:
    void onMonthYearChanged();
    void updateTransactionCount();

};

#endif // GRAPHPAGE_H
