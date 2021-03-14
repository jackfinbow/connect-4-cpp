#include "Player.h"
#include "Board.h"
#include <cstdlib>
#include <array>
#include <cstring>

class Computer: public Player
{
    public:
    Computer();

    int getInput()
    {
        int intInput;

        intInput = (rand() % (strlen(Board::board[0]))) + 1;

        return intInput;
    }
};