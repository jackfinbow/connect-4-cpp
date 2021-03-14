#include <iostream>
#include <string>
using namespace std;

class Player
{
    private:
    char counter;

    public:
    Player(char colour)
    {
        counter = colour;
    }

    int getInput();
    
    char getCounter()
    {
        return counter;
    }
}