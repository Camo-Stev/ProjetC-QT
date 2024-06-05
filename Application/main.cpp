#include <QApplication>
#include "CompteView.h"

int main(int argc, char argv[]) {
    QApplication app(argc, argv);
    CompteViewcompteView = new CompteView;
    compteView->show();
    return app.exec();
}