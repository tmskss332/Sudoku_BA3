#include "szam_widget.hpp"
#include "graphics.hpp"
#include <sstream>

using namespace genv;
using namespace std;

Szam_widget::Szam_widget(int x, int y, int size_x, int size_y, int _min, int _max)
    :Base_widget(x, y, size_x, size_y), i_min(_min), i_max(_max), szam(0)
{
}

void Szam_widget::rajzol()
{
    if(_size_x < 150)
        _size_x = 150;
    if(_size_x > 200)
        _size_x = 200;

    if(_size_y < 60)
        _size_y = 60;
    if(_size_y > 200)
        _size_y = 200;
    if(_x < 0)
        _x = 0;
    if(_x + _size_x > 800)
        _x = 800 - _size_x;
    if(_y < 0)
        _y = 0;
    if(_y + _size_y > 600)
        _y = 600-_size_y;

    stringstream stream;
    stream << szam;
    string szam_s;
    stream >> szam_s;
    if(_kivalasztva)
    {
        gout << move_to(_x, _y) << color(160, 160, 160) << box(_size_x, _size_y)
         << move_to(_x + 10, _y + 10) << color(96, 96, 96) << box(_size_x-20, _size_y-20);
    }
    else
    {
        gout << move_to(_x, _y) << color(96, 96, 96) << box(_size_x, _size_y)
         << move_to(_x + 10, _y + 10) << color(64, 64, 64) << box(_size_x-20, _size_y-20);
    }


    gout << move_to(_x + _size_x/2 - 60, _y + _size_y/2 - 16) << color(255, 255, 255) << box(80, 32)
         << move_to(_x + _size_x/2 + 20, _y + _size_y/2 - 16) << color(32, 32, 32) << box(40, 16)
         << move_to(_x + _size_x/2 + 21, _y + _size_y/2 - 15) << color(128, 128, 128) << box(38, 14)
         << move_to(_x + _size_x/2 + 20, _y + _size_y/2) << color(32, 32, 32) << box(40, 16)
         << move_to(_x + _size_x/2 + 21, _y + _size_y/2 + 1) << color(128, 128, 128) << box(38, 14)
         << move_to(_x + _size_x/2 + 38, _y + _size_y/2 - 12) << color(0, 0, 0) << box(4, 10)
         << move_to(_x + _size_x/2 + 35, _y + _size_y/2 - 9) << box(10, 4)
         << move_to(_x + _size_x/2 + 35, _y + _size_y/2 + 6) << box(10, 4)
         << move_to(_x + _size_x/2 - 15, _y + _size_y/2 + 5) << text(szam_s);

}

void Szam_widget::valtoztat(genv::event ev)
{
    if(_kivalasztva)
    {
        if(ev.type == ev_key)
        {
            if(ev.keycode == key_up && szam < i_max)
            {
                szam = szam + 1;
            }
            if(ev.keycode == key_f1)
            {
                if(szam <= i_max - 10)
                    szam = szam + 10;
                else if(szam > i_max - 10 && szam < i_max)
                    szam = i_max;
            }

            if(ev.keycode == key_down && szam > i_min)
            {
                szam = szam - 1;
            }
            if(ev.keycode == key_f2)
            {
                if(szam >= i_min + 10)
                    szam = szam - 10;
                else if(szam < i_min + 10 && szam > i_min)
                    szam = i_min;
            }
        }
    }
    if(ev.type == ev_mouse && ev.button == btn_left)
    {
        if((ev.pos_x >_x + _size_x/2 + 21 && ev.pos_x < _x + _size_x/2 + 59) && (ev.pos_y > _y + _size_y/2 - 15 && ev.pos_y < _y + _size_y/2 - 1) && szam < i_max)
        {
            szam = szam + 1;
        }
        else if((ev.pos_x >_x + _size_x/2 + 21 && ev.pos_x < _x + _size_x/2 + 59) && (ev.pos_y > _y + _size_y/2 + 1 && ev.pos_y < _y + _size_y/2 + 15) && szam > i_min)
        {
            szam = szam - 1;
        }
    }
}

int Szam_widget::get_szam()
{
    return szam;
}
string Szam_widget::get_szov()
{
    return "";
}

