#ifndef BASEBOARDCLASS_H
#define BASEBOARDCLASS_H

#include <stdio.h>
#include "Player.h"
#include <iostream>
using namespace std;



class BoardGame
{
protected:
    char **arr;
    int rows, cols;
    string name;
    bool LastPlayedP1;
public:
    BoardGame(int = 3, int = 3, string = "Board");
    void printBoard();
    virtual bool isGameOver() = 0;




};

#endif // BASEBOARDCLASS_H
