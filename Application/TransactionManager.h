#ifndef TRANSACTIONMANAGER_H
#define TRANSACTIONMANAGER_H

#include <QObject>
#include <QList>
#include "TransactionModel.h"

class TransactionManager : public QObject {
    Q_OBJECT

public:
    explicit TransactionManager(QObject *parent = nullptr);
    void addTransaction(const Transaction& transaction);
    const QList<Transaction>& getTransactions() const;
    int getTransactionCount() const;

signals:
    void transactionsUpdated();

private:
    QList<Transaction> transactions;
};

#endif // TRANSACTIONMANAGER_H
