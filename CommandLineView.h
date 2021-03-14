#include "View.h"

class CommandLineView: public View
{
    void View::display(string str)
    {
        cout << str;
    }
}