#include "Human.h"

Human::Human(char colour) : Player(colour)
{
    
}

int Human::getInput()
{
    string userInput;
    int intInput = 0;

    try
    {
        cin >> userInput;
        intInput = stoi(userInput);
    }
    catch(exception e)
    {
        cout << "An input was not detected or input wasn't an integer";
    }
    
    return intInput;
}