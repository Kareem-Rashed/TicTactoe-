#include "ConnectFour.h"
#include <iostream>
using namespace std;


ConnectFour::ConnectFour(QGraphicsView *inview,QGraphicsScene *inscene,string n,Player &pl1,Player &pl2):BoardGame(6,7,n){
    draw=false;
    p1 = &pl1;
    p2 = &pl2;
    view = inview;
    scene = inscene;

    drawboard(view,scene);

}
void ConnectFour::drawboard(QGraphicsView *view,QGraphicsScene *scene)
{
    int vlineSpacing = 800/7;
    int hlineSpacing = 600/6;
    for (int i = 1; i < 7; ++i) {

        QGraphicsRectItem *vLine = scene->addRect(i * vlineSpacing, 0, 1, 600);
    }
    for (int i = 1; i < 6; ++i) {
        QGraphicsRectItem *hLine = scene->addRect(0, i * hlineSpacing, 800, 1);
    }
    view->setScene(scene);
    view->show();
}


void ConnectFour::printBoard()
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
    for(int j=0; j<cols; j++)
    {
        cout<<'|'<<""<<j+1<<""<<'|';
    }
    cout<<endl;
}


void ConnectFour::makeMovep1()
{




    int n;
    int vlineSpacing = 800/7;
    int hlineSpacing = 600/6;
    cout<<p2->getx()<<endl;
    if(p1->getx()<vlineSpacing)
    {
        n=1;
    }
    else if(p1->getx()<vlineSpacing*2)
    {
        n=2;
    }
    else if(p1->getx()<vlineSpacing*3)
    {
        n=3;
    }
    else if(p1->getx()<vlineSpacing*4)
    {
        n=4;
    }
    else if(p1->getx()<vlineSpacing*5)
    {
        n=5;
    }
    else if(p1->getx()<vlineSpacing*6)
    {
        n=6;
    }
    else if(p1->getx()<vlineSpacing*7)
    {
        n=7;
    }
    cout<<""<<n<<endl;

    int r=0;
    int position;
    for(int i=5; i>-1; i--)
    {
        if(arr[i][n-1]==' ')
        {
            arr[i][n-1]=p1->getConnectSymbol();
            r = i+1;
            break;
        }
    }



    this->printBoard();

    LastPlayedP1 =  true;

    isGameOver();

    if(draw==true)
    {
        cout<<"GAME DRAWN!"<<endl;
        Draw();
    }
    if(isGameOver())
    {
        p1->addConnectWin();
        cout<<"GAME OVER!, "<<p1->getName()<<" wins!"<<endl;
        p2->addConnectWin();
        cout<<"GAME OVER!, "<<p1->getName()<<" wins!"<<endl;
        QGraphicsTextItem *Win = new QGraphicsTextItem;
        Win->setFont(QFont("times", 40));
        Win->setDefaultTextColor(Qt::red);
        Win->setPlainText(QString::fromStdString(p1->getName())+" WINS!");
        Win->setPos(300,300);
        scene->addItem(Win);
        view->setScene(scene);
        view->show();

    }






    position = (hlineSpacing*r)-60;




    QGraphicsEllipseItem *q = new QGraphicsEllipseItem;
    q->setRect(0,0,50,50);
    QBrush redBrush(Qt::red);
    q->setBrush(redBrush);
    q->setPos(p1->getx(),position);
    scene->addItem(q);
    view->setScene(scene);
    view->show();



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
        Draw();
    }
    if(isGameOver())
    {
        p1->addTicTacToeWin();
        p2->addConnectWin();
        cout<<"GAME OVER!, "<<p1->getName()<<" wins!"<<endl;
        QGraphicsTextItem *Win = new QGraphicsTextItem;
        Win->setFont(QFont("times", 40));
        Win->setDefaultTextColor(Qt::red);
        Win->setPlainText(QString::fromStdString(p1->getName())+" WINS!");
        Win->setPos(300,300);
        scene->addItem(Win);
        view->setScene(scene);
        view->show();

    }
}






void ConnectFour::makeMovep2()
{




    int n;
    int vlineSpacing = 800/7;
    int hlineSpacing = 600/6;
    cout<<p2->getx()<<endl;
    if(p2->getx()<vlineSpacing)
    {
        n=1;
    }
    else if(p2->getx()<vlineSpacing*2)
    {
        n=2;
    }
    else if(p2->getx()<vlineSpacing*3)
    {
        n=3;
    }
    else if(p2->getx()<vlineSpacing*4)
    {
        n=4;
    }
    else if(p2->getx()<vlineSpacing*5)
    {
        n=5;
    }
    else if(p2->getx()<vlineSpacing*6)
    {
        n=6;
    }
    else if(p2->getx()<vlineSpacing*7)
    {
        n=7;
    }
    cout<<""<<n<<endl;

    int r=0;
    int position;
    for(int i=5; i>-1; i--)
    {
        if(arr[i][n-1]==' ')
        {
            arr[i][n-1]=p2->getConnectSymbol();
            r = i+1;
            break;
        }
    }



    this->printBoard();

    LastPlayedP1 =  false;

    isGameOver();

    if(draw==true)
    {
        cout<<"GAME DRAWN!"<<endl;
        Draw();

    }
    if(isGameOver())
    {
        p2->addConnectWin();
        cout<<"GAME OVER!, "<<p2->getName()<<" wins!"<<endl;
        QGraphicsTextItem *Win = new QGraphicsTextItem;
        Win->setFont(QFont("times", 40));
        Win->setDefaultTextColor(Qt::red);
        Win->setPlainText(QString::fromStdString(p2->getName())+" WINS!");
        Win->setPos(300,300);
        scene->addItem(Win);
        view->setScene(scene);
        view->show();

    }






    position = (hlineSpacing*r)-60;




    QGraphicsEllipseItem *m = new QGraphicsEllipseItem;
    m->setRect(0,0,50,50);
    QBrush blueBrush(Qt::blue);
    m->setBrush(blueBrush);
    m->setPos(p2->getx(),position);
    scene->addItem(m);
    view->setScene(scene);
    view->show();



    p2->setenter(false);
    scene->removeItem(p2);
    scene->addItem(p1);
    p1->setFlag(QGraphicsItem::ItemIsFocusable);
    p1->setFocus();
    view->setScene(scene);
    view->show();






    isGameOver();

    if(draw==true)
    {
        cout<<"GAME DRAWN!"<<endl;
        Draw();
    }
    if(isGameOver())
    {
        p2->addTicTacToeWin();
        cout<<"GAME OVER!, "<<p2->getName()<<" wins!"<<endl;
        p2->addConnectWin();
        cout<<"GAME OVER!, "<<p2->getName()<<" wins!"<<endl;
        QGraphicsTextItem *Win = new QGraphicsTextItem;
        Win->setFont(QFont("times", 40));
        Win->setDefaultTextColor(Qt::red);
        Win->setPlainText(QString::fromStdString(p2->getName())+" WINS!");
        Win->setPos(300,300);
        scene->addItem(Win);
        view->setScene(scene);
        view->show();
    }



}



void ConnectFour::Draw()
{
    QGraphicsTextItem *Win = new QGraphicsTextItem;
    Win->setFont(QFont("times", 40));
    Win->setDefaultTextColor(Qt::red);
    Win->setPlainText("GAME OVER DRAW!");
    Win->setPos(300,400);
    scene->addItem(Win);
    view->setScene(scene);
    view->show();

}

bool ConnectFour::isGameOver()
{
    for(int i =0; i<6; i++)
    {
        for(int j =0; j<4; j++)
        {
            if(arr[i][j] == arr[i][j+1] && arr[i][j+1] == arr[i][j+2] && arr[i][j+2] == arr[i][j+3])
            {
                if(arr[i][j]!=' ')
                {
                    return true;
                }                    // Horizontal Check
            }
        }

    }
    for(int j =0; j<7; j++)
    {
        for(int i =0; i<3; i++)
        {
            if(arr[i][j] == arr[i+1][j] && arr[i+1][j] == arr[i+2][j] && arr[i+2][j] == arr[i+3][j])
            {
                if(arr[i][j]!=' ')
                    return true;

                //Vertical Check
            }
        }

    }
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<4;j++)
        {
            char check;
            if(arr[i][j]!=' ')
            {
                check = arr[i][j];
                if(arr[i+1][j+1]==check)
                {
                    if(arr[i+2][j+2]==check)
                    {
                        if(arr[i+3][j+3]==check)
                            return true;
                    }
                }

            }
        }
    }
    for(int i=0; i<3; i++)
    {
        for(int j=3; j<7;j++)
        {
            char check;
            if(arr[i][j]!=' ')
            {
                check = arr[i][j];
                if(arr[i+1][j-1]==check)
                {
                    if(arr[i+2][j-2]==check)
                    {
                        if(arr[i+3][j-3]==check)
                            return true;
                    }
                }

            }
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
    if(completedcells==42)
    {
        cout<<"GAME OVER, DRAWN!"<<endl;
        exit(0);
    }


    return false;
}



