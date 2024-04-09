#include "application.h"

#include <QApplication>
#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QPainter>
#include <vector>

const int GRID_SIZE = 20; // Taille de la grille en nombre de carrés

class SnakeGame : public QWidget
{
public:
    SnakeGame(QWidget *parent = nullptr) : QWidget(parent)
    {
        // Créer une grille de jeu
        QGridLayout *gridLayout = new QGridLayout(this);
        gridLayout->setSpacing(0); // Espacement entre les carrés

        // Créer et ajouter les carrés à la grille
        for (int row = 0; row < GRID_SIZE; ++row) {
            for (int col = 0; col < GRID_SIZE; ++col) {
                QLabel *square = new QLabel;
                square->setFixedSize(20, 20);
                square->setFrameStyle(QFrame::Box); // Style du cadre du carré
                square->setStyleSheet("border: 1px solid black"); // Couleur du cadre
                gridLayout->addWidget(square, row, col);
                grid.push_back(square);
            }
        }

        setLayout(gridLayout);

        snakeX = 0;
        snakeY = 0;

        updateSnakePosition();
    }

protected:
    void paintEvent(QPaintEvent *event) override
    {
        QWidget::paintEvent(event);

        QPainter painter(this);
        painter.setPen(Qt::blue); // Couleur du serpent


    }

private:
    std::vector<QLabel*> grid; // Grille de carrés
    int snakeX; // Position X du serpent
    int snakeY; // Position Y du serpent

    // Mettre à jour la position du serpent sur la grille
    void updateSnakePosition()
    {
        grid[snakeY * GRID_SIZE + snakeX]->setStyleSheet("background-color: blue");
    }
};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    SnakeGame game;
    game.show();
    return app.exec();
}
