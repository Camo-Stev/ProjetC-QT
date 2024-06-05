#include "CompteView.h"
#include <QInputDialog>

<<<<<<< HEAD
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
=======
CompteView::CompteView(QWidget *parent) : QWidget(parent) {
    model = new TransactionModel(this);
    layout = new QVBoxLayout(this);
    setupUI();
    updateTotal(model->getTotalAmount());

    connect(model, &TransactionModel::totalUpdated, this, &CompteView::updateTotal);
    connect(addButton, &QPushButton::clicked, this, &CompteView::showAddTransactionDialog);
}

void CompteView::setupUI() {
    totalLabel = new QLabel("Total: 0 €", this);
    totalLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(totalLabel);

    addButton = new QPushButton("+", this);
    addButton->setFixedSize(24, 24); // Small button size for the '+' symbol
    layout->addWidget(addButton);
>>>>>>> 5360e20306600242a04a2da1b56525fc8767a6e1

    auto transactions = model->getTransactions();
    for (const auto &transaction : transactions) {
        mainLayout->addWidget(new RowView(transaction.title, transaction.amount));
    }
<<<<<<< HEAD

    addTransactionView = new QWidget(this);
    QVBoxLayout *addLayout = new QVBoxLayout(addTransactionView);
    titleInput = new QLineEdit(addTransactionView);
    titleInput->setPlaceholderText("Enter transaction title");
    addLayout->addWidget(titleInput);

    amountInput = new QLineEdit(addTransactionView);
    amountInput->setPlaceholderText("Enter amount (use negative for expenses)");
    addLayout->addWidget(amountInput);

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
    model->addTransaction(title, amount);
    mainView->layout()->addWidget(new RowView(title, amount));
    updateTotal(model->getTotalAmount());
    showMainView();
=======
>>>>>>> 5360e20306600242a04a2da1b56525fc8767a6e1
}

void CompteView::updateTotal(double total) {
    totalLabel->setText("Total: " + QString::number(total, 'f', 2) + " €");
}

void CompteView::showAddTransactionDialog() {
    bool ok;
    QString title = QInputDialog::getText(this, "New Transaction", "Enter transaction title:", QLineEdit::Normal, "", &ok);
    if (!ok) return; // The user canceled the dialog

    double amount = QInputDialog::getDouble(this, "New Transaction", "Enter amount (use negative for expenses):", 0, -1e6, 1e6, 2, &ok);
    if (!ok) return; // The user canceled the dialog

    model->addTransaction(title, amount);
    layout->addWidget(new RowView(title, amount));
}