#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <stdio.h>
#include <QGraphicsEllipseItem>
#include <QGraphicsScene>
#include<QGraphicsView>
#include<QKeyEvent>



using namespace std;


class Player: public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT
private:
    string name;
    char Ticsymbol, ConnectSymbol;
    int order, Ticwins, ConnectWins;
    QGraphicsView *view;
    QGraphicsScene *scene;




public:
    bool enter;
    Player(QGraphicsView *view,QGraphicsScene *scene,string, char,char, int);
    char getTicSymbol() const;
    char getConnectSymbol() const;
    string getName() const;
    int getOrder() const;
    void addTicTacToeWin();
    void addConnectWin();
    int getx();
    int gety();
    void setenter(bool val);


public slots:
    void keyPressEvent(QKeyEvent * event);

signals:
    void enterPressed();

};



#endif // PLAYER_H
