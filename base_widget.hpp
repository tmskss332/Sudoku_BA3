#ifndef BASE_WIDGET_HPP
#define BASE_WIDGET_HPP

#include "graphics.hpp"
#include "App.hpp"

using namespace std;

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
    public:
        Base_widget(App*, int x, int y, int sx, int sy);
        virtual bool is_selected(int mouse_x, int mouse_y);
        virtual void select();
        virtual void unselect();
        virtual void draw() = 0;
        virtual void handle(genv::event ev) = 0;
        virtual int get_szam() = 0;

};

#endif // BASE_WIDGET_HPP
