#include "mainwindow.h"
#include <QApplication>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include<QGraphicsView>
#include "BaseBoardClass.h"
#include "Player.h"
#include "ConnectFour.h"
#include <iostream>
using namespace std;





int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsView *view = new QGraphicsView;
    view->setFixedSize(800, 600);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    QGraphicsScene *scene = new QGraphicsScene;
    scene->setSceneRect(0, 0, 800, 600);



    Player *player = new Player(view,scene,"Kareem", 'X','R', 1);

    player->setRect(0,0,50,50);


    QBrush redBrush(Qt::red);
    player->setBrush(redBrush);


    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    player->setPos(view->width()/2-24,25);

    Player *player2 = new Player(view,scene,"Joe", 'O','B', 2);

    player2->setRect(0,0,50,50);

    QBrush blueBrush(Qt::blue);
    player2->setBrush(blueBrush);


    player2->setPos(view->width()/2-25,25);

    ConnectFour Board(view,scene,"X O",*player,*player2);



    scene->addItem(player);
    view->setScene(scene);
    view->show();

    QObject::connect(player, &Player::enterPressed, &Board, &ConnectFour::makeMovep1);
    QObject::connect(player2, &Player::enterPressed, &Board, &ConnectFour::makeMovep2);



    return a.exec();
}
