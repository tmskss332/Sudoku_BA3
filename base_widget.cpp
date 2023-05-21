#include "base_widget.hpp"
#include "graphics.hpp"
#include <iostream>

using namespace genv;
using namespace std;

Base_widget::Base_widget(App* parent, int x, int y, int size_x, int size_y)
    : _parent(parent), _x(x), _y(y), _size_x(size_x), _size_y(size_y),_selected(false)
{
    _parent->register_widget(this);
}

bool Base_widget::is_selected(int xp, int yp)
{
    return((xp >=_x && xp <= _x+_size_x) && (yp >= _y && yp <= _y + _size_y));
}
void Base_widget::select()
{
    _selected = true;
}
void Base_widget::unselect()
{
    _selected = false;
}
