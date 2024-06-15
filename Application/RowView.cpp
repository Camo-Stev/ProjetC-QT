#include "RowView.h"

RowView::RowView(const QString &title, double amount, const QString &dateText, QWidget *parent)
    : QWidget(parent) {
    titleLabel = new QLabel(title, this);
    amountLabel = new QLabel(QString::number(amount, 'f', 2) + " €", this);
    QLabel *dateLabel = new QLabel(dateText, this);

    QVBoxLayout *titleDateLayout = new QVBoxLayout;
    titleDateLayout->addWidget(titleLabel);
    titleDateLayout->addWidget(dateLabel);
    titleDateLayout->setSpacing(4);

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addLayout(titleDateLayout);
    mainLayout->addWidget(amountLabel);
    mainLayout->setSpacing(20);
    setLayout(mainLayout);
}

