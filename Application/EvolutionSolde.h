#ifndef EVOLUTIONSOLDE_H
#define EVOLUTIONSOLDE_H

#include <QWidget>
#include <QtCharts>

class EvolutionSolde : public QWidget {
    Q_OBJECT
public:
    explicit EvolutionSolde(QWidget *parent = nullptr);

private:
    QChartView *createChart() const;
};

#endif // EVOLUTIONSOLDE_H
