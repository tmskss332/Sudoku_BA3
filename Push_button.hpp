#ifndef PUSH_BUTTON_HPP
#define PUSH_BUTTON_HPP

#include "base_widget.hpp"

using namespace std;
using namespace genv;
class Push_button : public Base_widget
{
    public:
        Push_button(App* parent, int x, int y, int sx, int sy, string text, function<void()> f);
        void draw();
        void handle(genv::event ev);
        void status(bool m, bool g, bool v);
    protected:
        string _text;
        function<void()> _f;


};

#endif // PUSH_BUTTON_HPP
