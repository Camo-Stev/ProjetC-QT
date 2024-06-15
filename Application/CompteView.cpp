#include "CompteView.h"
#include <QFrame>

CompteView::CompteView(QWidget *parent) : QWidget(parent), model(new TransactionModel(this)) {
    stackedWidget = new QStackedWidget(this);
    setupUI();

    connect(model, &TransactionModel::totalUpdated, this, &CompteView::updateTotal);
}

void CompteView::setupUI() {
    mainView = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(mainView);

    totalLabel = new QLabel("Total: 0 €", mainView);
    totalLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(totalLabel);

    addButton = new QPushButton("Ajout", mainView);
    mainLayout->addWidget(addButton);
    connect(addButton, &QPushButton::clicked, this, &CompteView::showAddTransactionView);


    for (const auto &transaction : model->getTransactions()) {
        RowView *row = new RowView(transaction.title, transaction.amount, transaction.date.toString("dd/MM/yyyy"));
        mainLayout->addWidget(row);
        separator->setFrameShape(QFrame::HLine);
    }

    addTransactionView = new QWidget(this);
    QVBoxLayout *addLayout = new QVBoxLayout(addTransactionView);
    titleInput = new QLineEdit(addTransactionView);
    titleInput->setPlaceholderText("Enter transaction title");
    addLayout->addWidget(titleInput);

    amountInput = new QLineEdit(addTransactionView);
    amountInput->setPlaceholderText("Enter amount (use negative for expenses)");
    addLayout->addWidget(amountInput);

    dateInput = new QDateEdit(QDate::currentDate(), addTransactionView);
    dateInput->setDisplayFormat("dd/MM/yyyy");
    addLayout->addWidget(dateInput);

    QPushButton *saveButton = new QPushButton("Save", addTransactionView);
    connect(saveButton, &QPushButton::clicked, this, &CompteView::addTransaction);
    addLayout->addWidget(saveButton);

    backButton = new QPushButton("Back", addTransactionView);
    connect(backButton, &QPushButton::clicked, this, &CompteView::showMainView);
    addLayout->addWidget(backButton);

    stackedWidget->addWidget(mainView);
    stackedWidget->addWidget(addTransactionView);
    stackedWidget->setCurrentWidget(mainView);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(stackedWidget);
    setLayout(layout);
}

void CompteView::showAddTransactionView() {
    stackedWidget->setCurrentWidget(addTransactionView);
}

void CompteView::showMainView() {
    stackedWidget->setCurrentWidget(mainView);
}

void CompteView::addTransaction() {
    QString title = titleInput->text();
    double amount = amountInput->text().toDouble();
    QDate date = dateInput->date();
    model->addTransaction(title, amount, date);
    mainView->layout()->addWidget(new RowView(title, amount, date.toString("dd/MM/yyyy")));
    updateTotal(model->getTotalAmount());
    showMainView();

    titleInput->clear();
    amountInput->clear();
    dateInput->setDate(QDate::currentDate());
}

void CompteView::updateTotal(double total) {
    totalLabel->setText("Total: " + QString::number(total, 'f', 2) + " €");
}

