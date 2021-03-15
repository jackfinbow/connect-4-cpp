#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include "Board.h"
//#include "View.h"
#include "CommandLineView.h"
//#include "Player.h"
#include "Human.h"
#include "Computer.h"
using namespace std;

class MyConnectFour
{
    private:
    // input
    vector <Player*> players;
    int currentPlayer;
    //Board board(3,5);
    CommandLineView view;

    void setUpGame();

    void playGame();

    void introMessage();

    void assignPlayers();

    void createBoard();
    
    public:
    MyConnectFour();
};