#include "tictactoe.h"
#include <iostream>
#include <QInputDialog>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include<QPixmap>

using namespace std;




TicTacToe::TicTacToe(QGraphicsView *inview,QGraphicsScene *inscene,string n,Player &pl1,Player &pl2):BoardGame(3,3,n)
{
    draw = false;
    p1 = &pl1;
    p2 = &pl2;
    view = inview;
    scene = inscene;

    drawboard(view,scene);


}

void TicTacToe::drawboard(QGraphicsView *view,QGraphicsScene *scene)
{
    int vlineSpacing = 800/3;
    int hlineSpacing = 600/3;
    for (int i = 1; i < 3; ++i) {

        QGraphicsRectItem *vLine = scene->addRect(i * vlineSpacing, 0, 1, 600);

        QGraphicsRectItem *hLine = scene->addRect(0, i * hlineSpacing, 800, 1);
    }
    view->setScene(scene);
    view->show();
}



bool TicTacToe::isGameOver()

{

    char check;
    for(int i=0; i<rows; i++)
    {
        int horizontal = 0;
        check = arr[i][0];
        for(int j=1; j<cols; j++)
        {
            if(arr[i][j]==check)
                horizontal++;

        }
        if((horizontal==2)&&(check!=' '))
        {
            cout<<"GAME OVER!"<<endl;
            return true;
                // Horizontal Check Complete
        }

    }
    for(int i=0; i<cols; i++)
    {
        int vertical = 0;
        check = arr[0][i];
        for(int j=1; j<rows; j++)
        {
            if(arr[j][i]==check)
                vertical++;

        }
        if((vertical==2)&&(check!=' '))
            return true;       // Vertical Check Complete


    }
    char diagonal = arr[1][1];
    if(diagonal==arr[0][0])
    {
        if(diagonal==arr[2][2])
        {
            if(diagonal!=' ')
                return true;    // diagonal check 1
        }
    }
    if(diagonal==arr[0][2])
    {
        if(diagonal==arr[2][0])
        {
            if(diagonal!=' ')       // diagonal check 2
                return true;
        }
    }
    int completedcells = 0;
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            if(arr[i][j]!=' ')
                completedcells++;
        }
    }
    if(completedcells==9)
    {
        draw = true;
    }


    return false;


}



void TicTacToe::makeMovep1()
{


    if((p1->getOrder()==1)&&(LastPlayedP1))
    {
        cout<<"Cannot play twice, not your turn, "<<p1->getName()<<endl;
        return;
    }


    {


        int r;
        int c;




                if(p1->getx()<200)
                {
                    c = 1;
                }
                else if((p1->getx()>200)&&(p1->getx()<400))
                {
                    c = 2;
                }
                else if(p1->getx()>400)
                {
                    c = 3;
                }

            if(p1->gety()<266)
            {
                r = 1;
            }
            else if((p1->gety()>266)&&(p1->gety()<400))
            {
                r = 2;
            }
            else if(p1->gety()>400)
            {
                r = 3;
            }
            cout<<r<<' '<<c<<endl;

        arr[r-1][c-1] = p1->getTicSymbol();

        printBoard();


        QPixmap xpic("/Users/kareem/Desktop/X.png");
        xpic = xpic.scaledToWidth(50);
        xpic = xpic.scaledToHeight(50);
        QGraphicsPixmapItem *image1 = new QGraphicsPixmapItem;
        image1->setPixmap(xpic);
        image1->setPos(p1->getx(),p1->gety());
        scene->addItem(image1);
        view->setScene(scene);
        view->show();

        LastPlayedP1 =  true;
        p1->setenter(false);
        scene->removeItem(p1);
        scene->addItem(p2);
        p2->setFlag(QGraphicsItem::ItemIsFocusable);
        p2->setFocus();
        view->setScene(scene);
        view->show();






        isGameOver();

        if(draw==true)
        {
            cout<<"GAME DRAWN!"<<endl;
            exit(0);
        }
        if(isGameOver())
        {
            p1->addTicTacToeWin();
            cout<<"GAME OVER!, "<<p1->getName()<<" wins!"<<endl;
            exit(0);
        }


    }
}




void TicTacToe::makeMovep2()
{


    if((p2->getOrder()==1)&&(LastPlayedP1))
    {
        cout<<"Cannot play twice, not your turn, "<<p2->getName()<<endl;
        return;
    }

    cout<<p2->getName()<<", Choose";






        cout<<"test2";
        int r;
        int c;



        {
            if(p2->getx()<200)
            {
                c = 1;
            }
            else if((p2->getx()>200)&&(p2->getx()<400))
            {
                c = 2;
            }
            else if(p2->getx()>400)
            {
                c = 3;
            }
        }
        if(p2->gety()<266)
        {
            r = 1;
        }
        else if((p2->gety()>266)&&(p2->gety()<400))
        {
            r = 2;
        }
        else if(p2->gety()>400)
        {
            r = 3;
        }
        cout<<r<<' '<<c<<endl;

        arr[r-1][c-1] = p2->getTicSymbol();
        cout<<"Its fine up until here";

        {
            QPixmap xpic("/Users/kareem/Desktop/O.png");
            xpic = xpic.scaledToWidth(50);
            xpic = xpic.scaledToHeight(50);
            QGraphicsPixmapItem *image2 = new QGraphicsPixmapItem;
            image2->setPixmap(xpic);
            image2->setPos(p2->getx(),p2->gety());
            scene->addItem(image2);
            view->setScene(scene);
            view->show();

            LastPlayedP1 =  false;
            p2->setenter(false);
            scene->removeItem(p2);
            scene->addItem(p1);
            p1->setFlag(QGraphicsItem::ItemIsFocusable);
            p1->setFocus();
            view->setScene(scene);
            view->show();
            cout<<"here too";

        }
        printBoard();


        isGameOver();

        if(draw==true)
        {
            cout<<"GAME DRAWN!"<<endl;
            exit(0);
        }
        if(isGameOver())
        {
            p2->addTicTacToeWin();
            cout<<"GAME OVER!, "<<p2->getName()<<" wins!"<<endl;
            exit(0);
        }

    }


void TicTacToe::printBoard() const
{
    cout<<name<<endl;

    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            cout<<'|'<<""<<arr[i][j]<<""<<'|';
        }
        cout<<endl;
    }
}
