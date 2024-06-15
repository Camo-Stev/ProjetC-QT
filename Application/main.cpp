#include <QApplication>
#include <QMainWindow>
#include "CompteView.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QMainWindow *window = new QMainWindow;

    // Créez une instance de CompteView
    CompteView *compteView = new CompteView;

    // Configurez compteView comme le widget central de la fenêtre principale
    window->setCentralWidget(compteView);

    // Fixez la hauteur de la fenêtre principale
    window->setFixedHeight(600);
    window->setFixedWidth(600);

    // Affichez la fenêtre principale
    window->show();

    return app.exec();
}
