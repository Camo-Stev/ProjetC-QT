#include <QApplication>
#include <QMainWindow>
#include "CompteView.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QMainWindow *window = new QMainWindow;

    CompteView *compteView = new CompteView;

    window->setCentralWidget(compteView);

    //window->setFixedHeight(600);
    window->setFixedWidth(500);

    window->show();

    return app.exec();
}
