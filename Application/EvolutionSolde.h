#ifndef EVOLUTIONSOLDE_H
#define EVOLUTIONSOLDE_H

#include <QWidget>
#include <QtCharts>

class EvolutionSolde : public QWidget {
    Q_OBJECT
public:
    explicit EvolutionSolde(QWidget *parent = nullptr);
    void showInfo();

private:
    QChartView *createChart() const;
};

#endif // EVOLUTIONSOLDE_H
