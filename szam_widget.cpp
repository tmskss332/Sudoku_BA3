#include "szam_widget.hpp"
#include "graphics.hpp"
#include <sstream>
#include <iostream>

using namespace genv;
using namespace std;

Szam_widget::Szam_widget(App* parent, int x, int y, int size_x, int size_y, int _min, int _max, function<void()> f)
    :Base_widget(parent,x, y, size_x, size_y), i_min(_min), i_max(_max), szam(0), _f(f)
{
    grid_koord.x = -1;
    grid_koord.y = -1;
}

void Szam_widget::draw()
{
    /*
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
    if(_selected)
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
    */
}

void Szam_widget::handle(genv::event ev)
{
    if(_selected)
    {
        if(ev.type == ev_mouse && ev.button == btn_left)
        {
            for(int i=0;i<9;i++)
                {

                    if(ev.pos_x > i*100+2 && ev.pos_x <(i+1)*100-2)
                    {
                        grid_koord.x = i;
                    }
                }

                for(int i=0;i<9;i++)
                {
                    if(ev.pos_y > i*100+2 && ev.pos_y <(i+1)*100-2)
                    {
                        grid_koord.y = i;
                    }
                }
        }
        if(ev.type == ev_key)
        {

            if(ev.keycode == 49)
            {
                szam = 1;
            }

            if(ev.keycode == 50)
            {
                szam = 2;
            }
            if(ev.keycode == 51)
            {
                szam = 3;
            }if(ev.keycode == 52)
            {
                szam = 4;
            }if(ev.keycode == 53)
            {
                szam = 5;
            }if(ev.keycode == 54)
            {
                szam = 6;
            }if(ev.keycode == 55)
            {
                szam = 7;
            }if(ev.keycode == 56)
            {
                szam = 8;
            }
            if(ev.keycode == 57)
            {
                szam = 9;
            }
            if(ev.keycode == key_backspace)
            {
                szam = 0;
            }
            _f();
        }
    }

    /*if(ev.type == ev_mouse && ev.button == btn_left)
    {
        if((ev.pos_x >_x + _size_x/2 + 21 && ev.pos_x < _x + _size_x/2 + 59) && (ev.pos_y > _y + _size_y/2 - 15 && ev.pos_y < _y + _size_y/2 - 1) && szam < i_max)
        {
            szam = szam + 1;
        }
        else if((ev.pos_x >_x + _size_x/2 + 21 && ev.pos_x < _x + _size_x/2 + 59) && (ev.pos_y > _y + _size_y/2 + 1 && ev.pos_y < _y + _size_y/2 + 15) && szam > i_min)
        {
            szam = szam - 1;
        }
    }*/
}

int Szam_widget::get_szam()
{
    return szam;
}
string Szam_widget::get_szov()
{
    return "";
}

Koord Szam_widget::get_koord()
{
    return grid_koord;
}
