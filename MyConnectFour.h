#include <iostream>
#include <string>
#include "Board.h"
#include "View.h"
#include "CommandLineView.h"
#include "Player.h"
using namespace std;

class MyConnectFour
{
    private:
    // input
    // player
    int currentPlayer;
    Board board;
    View view;

    void setUpGame();

    void playGame();

    void introMessage();

    void assignPlayers();

    void createBoard();

    public:
    MyConnectFour();
}