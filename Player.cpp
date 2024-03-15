#include "Player.h"
#include <iostream>
#include<QGraphicsItem>
#include<QKeyEvent>


using namespace std;



Player::Player(QGraphicsView *inview,QGraphicsScene *inscene,string n, char ts, char cs, int o)
{



    name = n;
    Ticsymbol = ts;
    ConnectSymbol = cs;
    order = o;
    Ticwins = 0;
    ConnectWins = 0;
    view=inview;
    enter = false;

    scene = inscene;




}



void Player::keyPressEvent(QKeyEvent *event)
{
    int vlineSpacing = 800/3;
    int hlineSpacing = 600/3;

    // *******  Event Handling for the Player ********
    if(event->key() == Qt::Key_Left)
    {
        if(x() > vlineSpacing) // Ensure not to move outside the left boundary
        {
            setPos(x() - vlineSpacing, y());
        }
    }
    else if(event->key() == Qt::Key_Right)
    {
        if(x() + vlineSpacing < 800) // Ensure not to move outside the right boundary
        {
            setPos(x() + vlineSpacing, y());
        }
    }
    else if(event->key() == Qt::Key_Up)
    {
        if(y()-vlineSpacing >0)
        {
            setPos(x(), y() - hlineSpacing);
        }
    }
    else if(event->key() == Qt::Key_Down)
    {
        if(y()+vlineSpacing <600)
        {
            setPos(x(), y() + hlineSpacing);
        }
    }
    else if(event->key() == Qt::Key_Return)
    {

        emit enterPressed();
        enter = true;

    }
}

int Player::getx()
{
    return x();
}
int Player::gety()
{
    return y();
}

void Player::setenter(bool val)
{
    enter = val;
}

char Player::getTicSymbol() const
{
    return Ticsymbol;
}
char Player::getConnectSymbol() const
{
    return ConnectSymbol;
}

string Player::getName() const
{
    return name;
}

int Player::getOrder() const
{
    return order;
}
void Player::addTicTacToeWin()
{
    Ticwins++;
}
void Player::addConnectWin()
{
    ConnectWins++;
}

