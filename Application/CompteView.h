#ifndef COMPTEVIEW_H
#define COMPTEVIEW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include "TransactionModel.h"
#include "RowView.h"

class CompteView : public QWidget {
    Q_OBJECT
public:
    explicit CompteView(QWidget parent = nullptr);

private:
    TransactionModelmodel;
    QVBoxLayout layout;
    QLabeltotalLabel;
    QPushButton *addButton;

    void setupUI();
    void addTransaction();

private slots:
    void updateTotal(double total);
    void showAddTransactionDialog();
};

#endif // COMPTEVIEW_H