#pragma once
#include <iostream>
#include <string>
using namespace std;

class Player
{
    private:
    //char counter;

    public:
    char counter;

    Player(char colour)
    {
        counter = colour;
    }

    virtual int getInput() = 0;
    
    char getCounter()
    {
        return counter;
    }
};