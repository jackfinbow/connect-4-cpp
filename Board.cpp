#include "Board.h"

vector <vector <char> > Board::board;

Board::Board(int row, int col)
{
    //Board::board[row][col];
    board = vector <vector <char> >(3, vector <char> (5));
    hasWon = false;
}

// accessor method for board, returned as a string for generality
string Board::boardToString()
{
    string boardString = "";

    // appends board to string
    for(int i = 0; i < board.size(); i++)
    {
        for(int j = 0; j < board[i].size(); j++)
        {
            if(board[i][j] == 'r')
            {
                boardString += ("| r ");
            }
            else if(board[i][j] == 'y')
            {
                boardString += ("| y ");
            }
            else
            {
                boardString += ("|   ");
            }
        }
        boardString += ("|");
        boardString += "\n";
    }
    // appends column numbers to string
    boardString += ("  " + 1);
    for(int k = 1; k < board[0].size(); k++)
    {
        boardString += ("   " + (k + 1));
    }
    return boardString;
}

// method for placing counter
// takes player colour and column as arguments, but also other player's colour for generality when checking if square is occupied
bool Board::placeCounter(char player, int position, char otherPlayer){
    bool placed = false;
    
    for(int i=board.size()-1; i>=0; i--)
    {
        if(!placed)
        {
            if(board[i][position-1] == otherPlayer)
            {
                // skip
            }
            else if(board[i][position-1] != player)
            {
                board[i][position-1] = player;
                placed = true;
            }

            // checks if column selected is full
            if(i == 0 && !placed)
            {
                cout << "Column is full";
            }
        }
    }

    return placed;
}

// method checks board horizontally for win (4 consecutive counters)
void Board::checkHorizontal(char counter)
{
    int count = 0;

    // cycle through rows
    for(int i=0; i<board.size(); i++)
    {
        // cycle through columns
        for(int j=0; j<board[i].size(); j++)
        {
            if(board[i][j] == counter)
            {
                count = count + 1;
                if(count >= 4)
                {
                    hasWon = true;
                }
            }
            else
            {
                count = 0;
            }
        }
        count = 0;
    }
}

// method checks board vertically for win
void Board::checkVertical(char counter)
{
    int count = 0;

    // cycle through columns
    for(int i=0; i<board[0].size(); i++)
    {
        // cycle through rows
        for(int j=0; j<board.size(); j++)
        {
            if(board[j][i] == counter){
                count = count + 1;
                if(count >= 4)
                {
                    hasWon = true;
                }
            }
            else
            {
                count = 0;
            }
        }
        count = 0;
    }
}

// method checks board along leading diagonal for win
void Board::checkLeadingDiagonal(char counter)
{
    int count = 0;

    // start by cycling through columns staring with each row from bottom to top
    int startRow = board.size() - 1;
    do
    {
        int row = startRow;
        int startCol = 0;
        do
        {
            try
            {
                if(board[row][startCol] == counter)
                {
                    count = count + 1;
                    if(count >= 4)
                    {
                        hasWon = true;
                    }
                }
                else
                {
                    count = 0;
                }
            }
            // if index out of bounds, reset startCol so that it exits do loop
            catch(exception e)
            {
                startCol = board[0].size();
            }
            row++;
            startCol++;

        } while(startCol < board[0].size());
        startRow--;
        count = 0;
    } while(startRow > 0);

    count = 0;
    // now cycle through rows staring with each column from beginning to end
    int startCol = 0;
    do
    {
        int col = startCol;
        startRow = 0;
        do
        {
            try
            {
                if(board[startRow][col] == counter)
                {
                    count = count + 1;
                    if(count >= 4)
                    {
                        hasWon = true;
                    }
                }
                else
                {
                    count = 0;
                }
            }
            catch(exception e)
            {
                startRow = board[0].size();
            }
            startRow++;
            col++;

        } while(startRow < board.size());
        startCol++;
        count = 0;
    } while(startCol < board[0].size());
}

// method checks board along reverse diagonal for win
void Board::checkReverseDiagonal(char counter)
{
    int count = 0;

    // start by cycling through columns staring with each row from bottom to top
    int startRow = board.size() - 1;
    do
    {
        int row = startRow;
        int startCol = board[0].size() - 1;
        do
        {
            try
            {
                if(board[row][startCol] == counter)
                {
                    count = count + 1;
                    if(count >= 4)
                    {
                        hasWon = true;
                    }
                }
                else
                {
                    count = 0;
                }
            }
            catch(exception e)
            {
                startCol = 0;
            }
            row++;
            startCol--;

        } while(startCol > 0);
        startRow--;
        count = 0;
    } while(startRow > 0);

    count = 0;
    // now cycle through rows staring with each column from end to beginning
    int startCol = board[0].size() - 1;
    do
    {
        int col = startCol;
        startRow = 0;
        do
        {
            try
            {
                if(board[startRow][col] == counter)
                {
                    count = count + 1;
                    if(count >= 4)
                    {
                        hasWon = true;
                    }
                }
                else
                {
                    count = 0;
                }
            }
            catch(exception e)
            {
                startRow = board[0].size();
            }
            startRow++;
            col--;

        } while(startRow < board.size());
        startCol--;
        count = 0;
    } while(startCol >= 0);
}

// accessor method for returning hasWon boolean
bool Board::getHasWon()
{
    return hasWon;
}

// modifier method for returning hasWon boolean
void Board::setHasWon(bool haveWon)
{
    hasWon = haveWon;
}
