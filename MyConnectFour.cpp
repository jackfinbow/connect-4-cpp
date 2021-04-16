#include "MyConnectFour.h"

Board board(3,5);
//vector <Player*> MyConnectFour::players;

MyConnectFour::MyConnectFour()
{
    // input
	setUpGame();
	playGame();
}

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
				int move = players.at(currentPlayer)->getInput();
				cout << move << endl;
				cout << players.at(currentPlayer)->getCounter() << endl;
				cout << players.at((currentPlayer + 1) % players.size())->getCounter() << endl;
				// place counter for current player with their counter colour
				isCounterPlaced = board.placeCounter(players.at(currentPlayer)->getCounter(), move, players.at((currentPlayer + 1) % players.size())->getCounter());
			}
			
			// check for win (4 consecutive counters)
			board.checkHorizontal(players.at(currentPlayer)->getCounter());
			board.checkVertical(players.at(currentPlayer)->getCounter());
			board.checkLeadingDiagonal(players.at(currentPlayer)->getCounter());
			board.checkReverseDiagonal(players.at(currentPlayer)->getCounter());
			
			// prints the board to command line console
			view.display(board.boardToString());
			// if current player has won, print message stating the player that has won
			if(board.getHasWon()){
				win = true;
				//view.display(to_string(typeid(players.at(currentPlayer))) + " has Won!!!");	//https://stackoverflow.com/questions/6271417/java-get-the-current-class-name
				view.display("Game over");
				delete players.at(0);
				delete players.at(0);
			}

			board.setHasWon(false);
			// switch current player
			currentPlayer = (currentPlayer + 1) % players.size();
		}
}

void MyConnectFour::introMessage()
{
    //CommandLineView view;

    view.display("Welcome to Connect 4");
    view.display("To play the game type in the number of the column you want to drop you counter in");
    view.display("A player wins by connecting 4 counters in a row - vertically, horizontally or diagonally");
    view.display("A player plays against the computer");
    view.display("There are 2 colours, red and yellow");
    view.display("Would you like to be red or yellow? (r/y)");
}

void MyConnectFour::assignPlayers()
{
	vector <char> colours (2);
	colours.insert(colours.end(), 'r');
	colours.insert(colours.end(), 'y');
	char colour;
	bool isROrY = false;

	try
	{
		while(isROrY == false)
		{
			cin >> colour;

			if(colour == 'r' || colour == 'y')
			{
				isROrY = true;
			}
			else
			{
				view.display("The colour you select must be r or y. Please re-enter:");
			}
		}
	}
	catch(exception e)
	{
		view.display("An input was not detected");
	}
	auto it = find(colours.begin(), colours.end(), colour);
	int colourIndex = distance(colours.begin(), it);

	//Human player1(colour);

	char compColour = colours.at((colourIndex + 1) % colours.size());
	//Computer computer(compColour);
	string playerString = "Player is ";
	playerString += colour;
	string compString = "Player is ";
	compString += compColour;
	view.display(playerString);
	view.display(compString);

	players.push_back(new Human(colour));
	players.push_back(new Computer(compColour));
	currentPlayer = 0;
}

void MyConnectFour::createBoard()
{
    view.display("");
	view.display("Enter the number of rows for the Connect 4 grid:");
	int numRows = players.at(0)->getInput();
	view.display("");
	view.display("Enter the number of columns for the Connect 4 grid:");
	int numCols = players.at(0)->getInput();
	//board(numRows, numCols);
	view.display(board.boardToString());
}
