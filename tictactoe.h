#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <stdio.h>
#include "BaseBoardClass.h"
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include<QGraphicsView>
#include "Player.h"
#include <QPixmap>
using namespace std;


class TicTacToe:public BoardGame, public QObject, public QGraphicsRectItem, public QPixmap
{

private:
    bool draw;
    Player *p1;
    Player *p2;
    QGraphicsView *view;
    QGraphicsScene *scene;

public:

    TicTacToe(QGraphicsView *view,QGraphicsScene *scene,string n, Player &pl1,Player &pl2);
    void drawboard(QGraphicsView *view,QGraphicsScene *scene);
    void makeMovep1();
    void makeMovep2();
    void operator+(Player &p);
    void printBoard() const;
    bool isGameOver();
    void runGameLoop();

};

#endif // TICTACTOE_H
