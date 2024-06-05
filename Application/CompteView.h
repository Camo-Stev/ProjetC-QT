#ifndef COMPTEVIEW_H
#define COMPTEVIEW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QStackedWidget>
#include <QLabel>
#include <QPushButton>
<<<<<<< HEAD
#include <QLineEdit>
=======
>>>>>>> 5360e20306600242a04a2da1b56525fc8767a6e1
#include "TransactionModel.h"
#include "RowView.h"

class CompteView : public QWidget {
    Q_OBJECT
public:
    explicit CompteView(QWidget parent = nullptr);

private:
<<<<<<< HEAD
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
=======
    TransactionModelmodel;
    QVBoxLayout layout;
    QLabeltotalLabel;
    QPushButton *addButton;

    void setupUI();
    void addTransaction();
>>>>>>> 5360e20306600242a04a2da1b56525fc8767a6e1

private slots:
    void updateTotal(double total);
    void showAddTransactionDialog();
};

#endif // COMPTEVIEW_H