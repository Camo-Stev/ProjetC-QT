#ifndef ROWVIEW_H
#define ROWVIEW_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMouseEvent>

class RowView : public QWidget {
    Q_OBJECT
public:
    explicit RowView(const QString &title, double amount, const QString &dateText, QWidget *parent = nullptr);


private:
    QLabel *titleLabel;
    QLabel *amountLabel;
    QString titleText, dateText;
    double amountValue;
};

#endif // ROWVIEW_H
