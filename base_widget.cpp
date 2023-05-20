#include "base_widget.hpp"
#include "graphics.hpp"
using namespace genv;
using namespace std;

Base_widget::Base_widget(int x, int y, int size_x, int size_y)
    : _x(x), _y(y), _size_x(size_x), _size_y(size_y),_kivalasztva(false)
{}

bool Base_widget::felette(int xp, int yp)
{
    return((xp >=_x && xp <= _x+_size_x) && (yp >= _y && yp <= _y + _size_y));
}
bool Base_widget::kivalasztva()
{
    return _kivalasztva;
}
void Base_widget::kivalaszt(genv::event ev)
{
    _kivalasztva = true;
}
void Base_widget::elfelejt()
{
    _kivalasztva = false;
}
