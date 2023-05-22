#ifndef SZAM_WIDGET_HPP
#define SZAM_WIDGET_HPP


#include "base_widget.hpp"


class Szam_widget : public Base_widget
{
    protected:
        int i_min, i_max, szam;
        function<void()> _f;
        Koord grid_koord;
    public:
        Szam_widget(App* parent, int x, int y, int size_x, int size_y, int _min, int _max, function<void()> f);
        void draw();
        void handle(genv::event ev);
        int get_szam();
        string get_szov();
        Koord get_koord();
        void status(bool, bool, bool);
};

#endif // SZAM_WIDGET_HPP
