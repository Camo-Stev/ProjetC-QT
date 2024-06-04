#include "CompteView.h"
#include <QInputDialog>

CompteView::CompteView(QWidget *parent) : QWidget(parent) {
    model = new TransactionModel(this);
    layout = new QVBoxLayout(this);
    setupUI();
    updateTotal(model->getTotalAmount());

    connect(model, &TransactionModel::totalUpdated, this, &CompteView::updateTotal);
    connect(addButton, &QPushButton::clicked, this, &CompteView::showAddTransactionDialog);
}

void CompteView::setupUI() {
    totalLabel = new QLabel("Total: 0 €", this);
    totalLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(totalLabel);

    addButton = new QPushButton("+", this);
    addButton->setFixedSize(24, 24); // Small button size for the '+' symbol
    layout->addWidget(addButton);

    auto transactions = model->getTransactions();
    for (const auto &transaction : transactions) {
        layout->addWidget(new RowView(transaction.title, transaction.amount));
    }
}

void CompteView::updateTotal(double total) {
    totalLabel->setText("Total: " + QString::number(total, 'f', 2) + " €");
}

void CompteView::showAddTransactionDialog() {
    bool ok;
    QString title = QInputDialog::getText(this, "New Transaction", "Enter transaction title:", QLineEdit::Normal, "", &ok);
    if (!ok) return; // The user canceled the dialog

    double amount = QInputDialog::getDouble(this, "New Transaction", "Enter amount (use negative for expenses):", 0, -1e6, 1e6, 2, &ok);
    if (!ok) return; // The user canceled the dialog

    model->addTransaction(title, amount);
    layout->addWidget(new RowView(title, amount));
}