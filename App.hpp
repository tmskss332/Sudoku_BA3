#ifndef APP_HPP
#define APP_HPP

#include <vector>


using namespace std;

class Base_widget;

class App
{
    protected:
        vector<Base_widget*> widgets;
        bool menu;
        bool game;
        bool vic;
        bool _exit;

    public:
        App();
        void game_loop();
        void register_widget(Base_widget*);
};

#endif // APP_HPP
