#include "View.h"

class CommandLineView: public View
{
    void display(string str)
    {
        cout << str;
    }
};