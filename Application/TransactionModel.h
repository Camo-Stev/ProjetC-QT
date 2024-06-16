#ifndef TRANSACTIONMODEL_H
#define TRANSACTIONMODEL_H

#include <QObject>
#include <QVector>
#include <QString>
#include <QDate>
#include <QList>

struct Transaction {
    QString title;
    double amount;
    QDate date;
};

class TransactionModel : public QObject {
    Q_OBJECT

public:
    explicit TransactionModel(QObject *parent = nullptr);
    void addTransaction(const QString &title, double amount, const QDate &date);
    const QVector<Transaction>& getTransactions() const;
    double getTotalAmount() const;
    QList<Transaction> getTransactionsByMonthYear(int month, int year) const;

signals:
    void transactionsUpdated();
    void totalUpdated(double newTotal);

private:
    QVector<Transaction> transactions;
};

#endif // TRANSACTIONMODEL_H
