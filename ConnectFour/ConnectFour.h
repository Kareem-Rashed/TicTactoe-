#ifndef ConnectFour_hpp
#define ConnectFour_hpp

#include <stdio.h>
#include "BaseBoardClass.h"
#include <iostream>
#include <QInputDialog>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include"Player.h"
#include<QPixmap>
using namespace std;



class ConnectFour:public BoardGame, public QObject, public QGraphicsRectItem, public QPixmap, public QGraphicsEllipseItem
{

private:
    bool draw;
    Player *p1;
    Player *p2;
    QGraphicsView *view;
    QGraphicsScene *scene;
public:
    ConnectFour(QGraphicsView *inview,QGraphicsScene *inscene,string n,Player &pl1,Player &pl2);
    void printBoard();
    void makeMovep1();
    void makeMovep2();
    void drawboard(QGraphicsView *view,QGraphicsScene *scene);
    bool isGameOver();
    void Celebration();
    void Draw();
    bool isValid(int n);





};




#endif /* ConnectFour_hpp */
