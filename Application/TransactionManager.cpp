#include "TransactionManager.h"

TransactionManager::TransactionManager(QObject *parent) : QObject(parent) {}

void TransactionManager::addTransaction(const Transaction& transaction) {
    transactions.append(transaction);
    emit transactionsUpdated();
}

const QList<Transaction>& TransactionManager::getTransactions() const {
    return transactions;
}

int TransactionManager::getTransactionCount() const {
    return transactions.size();
}
