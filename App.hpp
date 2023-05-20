#ifndef APP_HPP
#define APP_HPP

#include <vector>
#include "graphics.hpp"

using namespace std;

class Widget;
class App
{
    protected:
        vector<Widget*> widgets;

    public:
        void game_loop();
};

#endif // APP_HPP
