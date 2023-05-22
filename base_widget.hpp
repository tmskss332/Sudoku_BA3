#ifndef BASE_WIDGET_HPP
#define BASE_WIDGET_HPP

#include "graphics.hpp"
#include "App.hpp"
#include <functional>
#include <fstream>
#include <time.h>
#include <vector>
#include <functional>
#include <sstream>

using namespace std;

struct Number
{
    int n;
    bool can_edit;
};
struct Koord
{
    int x,y;
};
class Base_widget
{
    protected:
        int _x, _y, _size_x, _size_y;
        bool _selected;
        App* _parent;
        bool active;
    public:
        Base_widget(App*, int x, int y, int sx, int sy);
        virtual bool is_selected(int mouse_x, int mouse_y);
        virtual void select();
        virtual void unselect();
        virtual void draw() = 0;
        virtual void handle(genv::event ev) = 0;
        virtual void status(bool, bool, bool) = 0;

};

#endif // BASE_WIDGET_HPP
