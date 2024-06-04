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
    explicit TransactionModel(QObject *parent = nullptr) : QObject(parent) {
        // Exemple d'initialisation avec des données de test
        addTransaction("Achat de café", -3.50);
        addTransaction("Paiement reçu", 250.00);
        addTransaction("Location de voiture", -100.00);
    }

    const QVector<Transaction>& getTransactions() const { return transactions; }
    double getTotalAmount() const {
        double total = 0;
        for (const auto &transaction : transactions) {
            total += transaction.amount;
        }
        return total;
    }

    void addTransaction(const QString &title, double amount) {
        transactions.append({title, amount});
        emit transactionsUpdated();
        emit totalUpdated(getTotalAmount());
    }

signals:
    void transactionsUpdated();
    void totalUpdated(double newTotal);

private:
    QVector<Transaction> transactions;
};

#endif // TRANSACTIONMODEL_H
