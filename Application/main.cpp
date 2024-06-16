#include <QApplication>
#include <QMainWindow>
#include <QMenuBar>
#include <QStackedWidget>
#include <QListWidget>
#include <QWidget>
#include "CompteView.h"
#include "GraphPage.h"
#include "TransactionManager.h"
#include "EvolutionSolde.h"

class MainWindow : public QMainWindow {
public:
    MainWindow(QWidget *parent = nullptr) : QMainWindow(parent) {


        QStackedWidget* stackedWidget = new QStackedWidget;
        QListWidget* navList = new QListWidget;

        CompteView* comptePage = new CompteView;
        EvolutionSolde* evolutionSold = new EvolutionSolde();
        TransactionManager* manager = new TransactionManager();
        GraphPage* graphPage = new GraphPage(manager);

        stackedWidget->addWidget(comptePage);
        stackedWidget->addWidget(evolutionSold);
        stackedWidget->addWidget(graphPage);

        navList->addItem("Compte");
        navList->addItem("Évolution Solde");
        navList->addItem("Graphiques");

        connect(navList, &QListWidget::currentRowChanged, stackedWidget, &QStackedWidget::setCurrentIndex);

        QHBoxLayout* layout = new QHBoxLayout;
        layout->addWidget(navList, 1);
        layout->addWidget(stackedWidget, 4);

        QWidget* centralWidget = new QWidget;
        centralWidget->setLayout(layout);
        setCentralWidget(centralWidget);

        navList->setFixedWidth(150);
        setWindowTitle("Application de gestion");
        resize(800, 600);
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWindow mainWindow;
    mainWindow.show();
    return app.exec();
}
