#include "MyConnectFour.h"

void MyConnectFour::setUpGame()
{
    introMessage();

    assignPlayers();

    createBoard();
}

void MyConnectFour::playGame()
{
    bool win = false;
		while(!win)
		{
			bool isCounterPlaced = false;
			// keep asking player (or computer) for input until counter is placed
			// counter won't be placed if column selected is already full
			while(!isCounterPlaced)
			{
				view.display("Enter the column you'd like to place your counter in:");
				// obtain input from current player
				int move = players.get(currentPlayer).getInput();
				// place counter for current player with their counter colour
				isCounterPlaced = board.placeCounter(players.get(currentPlayer).getCounter(), move, players.get((currentPlayer + 1) % players.size()).getCounter());
			}
			
			// check for win (4 consecutive counters)
			board.checkHorizontal(players.get(currentPlayer).getCounter());
			board.checkVertical(players.get(currentPlayer).getCounter());
			board.checkLeadingDiagonal(players.get(currentPlayer).getCounter());
			board.checkReverseDiagonal(players.get(currentPlayer).getCounter());
			
			// prints the board to command line console
			view.display(board.boardToString());
			// if current player has won, print message stating the player that has won
			if(board.getHasWon()){
				win = true;
				view.display(players.get(currentPlayer).getClass().getName() + " has Won!!!");	//https://stackoverflow.com/questions/6271417/java-get-the-current-class-name
			}

			board.setHasWon(false);
			// switch current player
			currentPlayer = (currentPlayer + 1) % players.size();
		}
}

void MyConnectFour::introMessage()
{
    CommandLineView view;

    view.display("Welcome to Connect 4");
    view.display("To play the game type in the number of the column you want to drop you counter in");
    view.display("A player wins by connecting 4 counters in a row - vertically, horizontally or diagonally");
    view.display("A player plays against the computer");
    view.display("There are 2 colours, red and yellow");
    view.display("Would you like to be red or yellow? (r/y)");
}

void MyConnectFour::assignPlayers()
{

}

void MyConnectFour::createBoard()
{
    
}

public:
MyConnectFour::MyConnectFour()
{
    // input
}
