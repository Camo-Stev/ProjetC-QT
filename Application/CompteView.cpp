#include "CompteView.h"

CompteView::CompteView(QWidget *parent) : QWidget(parent) {
    model = new TransactionModel(this);
    layout = new QVBoxLayout(this);
    totalLabel = new QLabel("Total: 0 €", this);
    totalLabel->setAlignment(Qt::AlignCenter);

    auto transactions = model->getTransactions();
    for (const auto &transaction : transactions) {
        layout->addWidget(new RowView(transaction.title, transaction.amount));
    }

    layout->addWidget(totalLabel);
    updateTotal(model->getTotalAmount());

    connect(model, &TransactionModel::totalUpdated, this, &CompteView::updateTotal);
}

void CompteView::updateTotal(double total) {
    totalLabel->setText("Total: " + QString::number(total, 'f', 2) + " €");
}
