#ifndef TRANSACTIONMANAGER_H
#define TRANSACTIONMANAGER_H

#include <QObject>
#include <QList>
#include "TransactionModel.h"

class TransactionManager : public QObject {
    Q_OBJECT

public:
    QList<Transaction> transactions;

    void addTransaction(const Transaction& transaction) {
        transactions.append(transaction);
        emit transactionsUpdated();
    }

signals:
    void transactionsUpdated();
};

#endif // TRANSACTIONMANAGER_H
