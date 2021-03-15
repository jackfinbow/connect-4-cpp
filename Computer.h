#include "Player.h"
#include "Board.h"
#include <cstdlib>
#include <array>
#include <cstring>

class Computer: public Player
{
    public:
    Computer(char colour);

    int getInput();
};