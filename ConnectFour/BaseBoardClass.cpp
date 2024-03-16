#include "BaseBoardClass.h"
#include "Player.h"
#include <iostream>
using namespace std;


BoardGame::BoardGame(int inrows, int incols, string n):LastPlayedP1(false)
{
    rows = inrows;
    cols = incols;
    name = n;
    arr = new char*[rows];

    for(int i=0; i<rows; i++)
    {
        arr[i] = new char[cols];
    }
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            arr[i][j] = ' ';
        }
    }
}

void BoardGame::printBoard()
{
    cout<<name<<endl;

    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}



