#ifndef COMPTEVIEW_H
#define COMPTEVIEW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QStackedWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include "TransactionModel.h"
#include "RowView.h"

class CompteView : public QWidget {
    Q_OBJECT
public:
    explicit CompteView(QWidget *parent = nullptr);

private:
    TransactionModel *model;
    QStackedWidget *stackedWidget;
    QWidget *mainView;
    QWidget *addTransactionView;
    QLabel *totalLabel;
    QPushButton *addButton;
    QPushButton *backButton;
    QLineEdit *titleInput;
    QLineEdit *amountInput;

    void setupUI();
    void addTransaction();
    void showAddTransactionView();
    void showMainView();

private slots:
    void updateTotal(double total);
};

#endif // COMPTEVIEW_H
