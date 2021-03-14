#include "Player.h"
#include <cstdlib>
#include <array>

class Computer: public Player
{
    public:
    Computer();

    int Player::getInput()
    {
        int intInput;

        intInput = (rand() % Board::board[0].size()) + 1;

        return intInput;
    }
}