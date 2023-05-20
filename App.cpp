#include "App.hpp"
#include "base_widget.hpp"



#include <iostream>

using namespace std;
using namespace genv;

App::App()
{
    gout.open(900,900);
    gout << refresh;
}

void App::game_loop()
{
    genv::event ev;
    int focus = -1;
    while(gin>>ev && ev.keycode != key_escape)
    {


        for (Base_widget * w : widgets)
        {
            w->draw();
        }
        gout << refresh;
        //sw->select();
        //sw->handle(ev);


        /*if (ev.type == ev_mouse && ev.button==btn_left)
        {
            for (size_t i=0;i<widgets.size();i++)
            {
                if (widgets[i]->is_selected(ev.pos_x, ev.pos_y))
                {
                    focus = i;
                    widgets[i]->select();
                }
                else
                {
                    widgets[i]->unselect();
                }
            }
        }


        if (focus!=-1) {
            widgets[focus]->handle(ev);
        }

        for (Base_widget * w : widgets) {
            w->draw();

        }
        gout << refresh;*/
    }
}
void App::register_widget(Base_widget* w)
{
    widgets.push_back(w);
}




