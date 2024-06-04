#include "RowView.h"

RowView::RowView(const QString &title, double amount, QWidget *parent) : QWidget(parent) {
    titleLabel = new QLabel(title, this);
    amountLabel = new QLabel(QString::number(amount, 'f', 2) + " €", this); // Format the amount with two decimals and append Euro symbol

    // Setup layout
    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(titleLabel);
    layout->addWidget(amountLabel);

    // Optional: add styling or further configuration
    titleLabel->setStyleSheet("font-weight: bold;");
    amountLabel->setAlignment(Qt::AlignRight);
}
