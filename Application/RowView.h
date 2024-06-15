#ifndef ROWVIEW_H
#define ROWVIEW_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>

class RowView : public QWidget {
    Q_OBJECT
public:
    RowView(const QString &title, double amount, const QString &dateText, QWidget *parent = nullptr);

private:
    QLabel *titleLabel;
    QLabel *amountLabel;
};

#endif // ROWVIEW_H
