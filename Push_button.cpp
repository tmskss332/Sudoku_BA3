#include "Push_button.hpp"

Push_button::Push_button(App* parent, int x, int y, int sx, int sy, string text, function<void()> f): Base_widget(parent,x,y,sx,sy), _text(text), _f(f)
{
    active = true;
}
void Push_button::draw()
{
    if(active)
    {
        gout << font("Karate.ttf",40) << color(255,255,255) << move_to(_x, _y) << box(_size_x, _size_y)
         << move_to(_x + _size_x/2 - gout.twidth(_text)/2, _y+(_size_y-gout.cascent()-gout.cdescent())/2) << color(255,0,0) << text(_text);
    }
}
void Push_button::handle(event ev)
{
    if(active)
    {
        if(is_selected(ev.pos_x, ev.pos_y))
    {
        if(ev.type == ev_mouse && ev.button == btn_left)
        {
            _f();
        }
    }
    }

}

void Push_button::status(bool m, bool g, bool v)
{
    if(m || v)
    {
        active = true;
    }
    else
    {
        active = false;
    }
}
