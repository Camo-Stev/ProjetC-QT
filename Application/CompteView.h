#ifndef COMPTEVIEW_H
#define COMPTEVIEW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QStackedWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QDateEdit>
#include "TransactionModel.h"
#include "RowView.h"

class CompteView : public QWidget {
    Q_OBJECT
public:
    explicit CompteView(QWidget *parent = nullptr);
    void setupUI();

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
    QDateEdit *dateInput;


private slots:
    void showAddTransactionView();
    void showMainView();
    void addTransaction();
    void updateTotal(double total);
};

#endif // COMPTEVIEW_H
