#include "Computer.h"

int Computer::getInput()
{
    int intInput;

    intInput = (rand() % (strlen(Board::board[0]))) + 1;

    return intInput;
}