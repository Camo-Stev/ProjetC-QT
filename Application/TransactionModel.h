#ifndef TRANSACTIONMODEL_H
#define TRANSACTIONMODEL_H

#include <QObject>
#include <QVector>
#include <QString>

struct Transaction {
    QString title;
    double amount;
};

class TransactionModel : public QObject {
    Q_OBJECT
public:
    explicit TransactionModel(QObject *parent = nullptr);

    const QVector<Transaction>& getTransactions() const;
    void addTransaction(const QString &title, double amount);
    double getTotalAmount() const;  // Rendu public pour accès direct

signals:
    void transactionsUpdated();
    void totalUpdated(double newTotal);

private:
    QVector<Transaction> transactions;
};

#endif // TRANSACTIONMODEL_H
