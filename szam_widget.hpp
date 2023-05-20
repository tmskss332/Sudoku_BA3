#ifndef SZAM_WIDGET_HPP
#define SZAM_WIDGET_HPP

#include "graphics.hpp"
#include "base_widget.hpp"

class Szam_widget : public Base_widget
{
    protected:
        int i_min, i_max, szam;
    public:
        Szam_widget(int x, int y, int size_x, int size_y, int _min, int _max);
        void rajzol();
        void valtoztat(genv::event ev);
        int get_szam();
        string get_szov();

};

#endif // SZAM_WIDGET_HPP
