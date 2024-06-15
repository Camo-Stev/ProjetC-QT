#ifndef ROWVIEW_H
#define ROWVIEW_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>

class RowView : public QWidget {
    Q_OBJECT
public:
    explicit RowView(const QString &title, double amount, QWidget *parent = nullptr);

private:
    QLabel *titleLabel;
    QLabel *amountLabel;
    QHBoxLayout *layout;
};

#endif // ROWVIEW_H
