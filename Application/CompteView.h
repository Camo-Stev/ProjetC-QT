#ifndef COMPTEVIEW_H
#define COMPTEVIEW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include "TransactionModel.h"
#include "RowView.h"

class CompteView : public QWidget {
    Q_OBJECT
public:
    explicit CompteView(QWidget *parent = nullptr);

private:
    TransactionModel *model;
    QVBoxLayout *layout;
    QLabel *totalLabel;

private slots:
    void updateTotal(double total);
};

#endif // COMPTEVIEW_H
