#include "Computer.h"

Computer::Computer(char colour) : Player(colour)
{

}

int Computer::getInput()
{
    int intInput;

    intInput = (rand() % (Board::board[0].size())) + 1;

    return intInput;
}