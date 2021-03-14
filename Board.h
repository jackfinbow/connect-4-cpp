#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Board
{
    private:
    bool hasWon;

    public:
    static char board[3][5];

    Board(int row, int col);

    // accessor method for board, returned as a string for generality
    string boardToString();
    
    // method for placing counter
    // takes player colour and column as arguments, but also other player's colour for generality when checking if square is occupied
    bool placeCounter(char player, int position, char otherPlayer);
    
    // method checks board horizontally for win (4 consecutive counters)
    void checkHorizontal(char counter);

    // method checks board vertically for win
    void checkVertical(char counter);

    // method checks board along leading diagonal for win
    void checkLeadingDiagonal(char counter);

    // method checks board along reverse diagonal for win
    void checkReverseDiagonal(char counter);

    // accessor method for returning hasWon boolean
    bool getHasWon();

    // modifier method for returning hasWon boolean
    void setHasWon(bool haveWon);
};