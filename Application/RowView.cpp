#include "RowView.h"

RowView::RowView(const QString &title, double amount, QWidget *parent) : QWidget(parent) {
    titleLabel = new QLabel(title, this);
    amountLabel = new QLabel(QString::number(amount, 'f', 2) + " €", this);

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(titleLabel,1);
    layout->addWidget(amountLabel,0, Qt::AlignRight);

    titleLabel->setStyleSheet("font-weight: bold;");
    amountLabel->setAlignment(Qt::AlignRight);

    setLayout(layout);
}
