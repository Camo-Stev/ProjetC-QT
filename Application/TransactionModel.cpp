#include "TransactionModel.h"

TransactionModel::TransactionModel(QObject *parent) : QObject(parent) {

}

const QVector<Transaction>& TransactionModel::getTransactions() const {
    return transactions;
}

void TransactionModel::addTransaction(const QString &title, double amount) {
    transactions.append({title, amount});
    emit transactionsUpdated();
    emit totalUpdated(getTotalAmount());
}

double TransactionModel::getTotalAmount() const {
    double total = 0;
    for (const auto &transaction : transactions) {
        total += transaction.amount;
    }
    return total;
}
