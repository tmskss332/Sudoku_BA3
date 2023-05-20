#ifndef BASE_WIDGET_HPP
#define BASE_WIDGET_HPP

#include "graphics.hpp"

using namespace std;

class Base_widget
{
    protected:
        int _x, _y, _size_x, _size_y;
        bool _kivalasztva;
    public:
        Base_widget(int x, int y, int size_x, int size_y);
        bool felette(int px, int py);
        bool kivalasztva();
        void kivalaszt(genv::event ev);
        void elfelejt();
        virtual int get_szam() = 0;
        virtual string get_szov() = 0;
        virtual void rajzol() = 0;
        virtual void valtoztat(genv::event ev) = 0;
};

#endif // BASE_WIDGET_HPP
