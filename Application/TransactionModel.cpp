#include "TransactionModel.h"

TransactionModel::TransactionModel(QObject *parent) : QObject(parent) {
    // Initial transactions can be setup here if needed
}

void TransactionModel::addTransaction(const QString &title, double amount, const QDate &date) {
    transactions.append({title, amount, date});
    emit transactionsUpdated();
    emit totalUpdated(getTotalAmount());
}

const QVector<Transaction>& TransactionModel::getTransactions() const {
    return transactions;
}

double TransactionModel::getTotalAmount() const {
    double total = 0;
    for (const auto& transaction : transactions) {
        total += transaction.amount;
    }
    return total;
}
