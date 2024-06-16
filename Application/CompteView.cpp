#include "CompteView.h"
#include <QFrame>
#include <QMessageBox>

CompteView::CompteView(QWidget *parent) : QWidget(parent), model(new TransactionModel(this)) {
    stackedWidget = new QStackedWidget(this);

    setupUI();
    initializeDefaultTransactions();
    connect(model, &TransactionModel::totalUpdated, this, &CompteView::updateTotal);
}
void CompteView::setupUI() {
    mainView = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(mainView);

    // Bouton d'information placé en haut à droite
    QHBoxLayout *infoLayout = new QHBoxLayout();
    QPushButton *infoButton = new QPushButton("i");
    infoButton->setStyleSheet("font-weight: bold; font-size: 16px; width: 25px; height: 25px; border-radius: 12.5px; border: 1px solid black;");
    connect(infoButton, &QPushButton::clicked, this, &CompteView::showInfo);
    infoLayout->addWidget(infoButton);
    infoLayout->addStretch();
    mainLayout->addLayout(infoLayout);

    totalLabel = new QLabel("Total: 0 €", mainView);
    totalLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(totalLabel);

    addButton = new QPushButton("Ajout", mainView);
    mainLayout->addWidget(addButton);
    connect(addButton, &QPushButton::clicked, this, &CompteView::showAddTransactionView);

    for (const auto &transaction : model->getTransactions()) {
        RowView *row = new RowView(transaction.title, transaction.amount, transaction.date.toString("dd/MM/yyyy"));
        mainLayout->addWidget(row);
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


void CompteView::initializeDefaultTransactions() {
    model->addTransaction("Loyer", -1200.00, QDate(2024, 1, 1));
    model->addTransaction("Salaire", 2500.00, QDate(2024, 1, 5));
    model->addTransaction("Achat ordinateur", -800.00, QDate(2024, 1, 10));

    updateTotal(model->getTotalAmount());

    for (const auto &transaction : model->getTransactions()) {
        RowView *row = new RowView(transaction.title, transaction.amount, transaction.date.toString("dd/MM/yyyy"));
        QVBoxLayout *layout = qobject_cast<QVBoxLayout *>(mainView->layout());
        if (layout) {
            layout->addWidget(row);
        }
    }
}


void CompteView::showInfo() {
    QMessageBox::information(this, "Informations sur la page de compte", "Cette page vous permet de gérer vos transactions. Vous pouvez ajouter et visualiser les transactions. Utilisez le bouton 'Ajout' pour ajouter une nouvelle transaction et naviguez entre les différentes transactions affichées.");
}
