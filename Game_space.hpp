#ifndef GAME_SPACE_HPP
#define GAME_SPACE_HPP

#include "base_widget.hpp"
#include <vector>
#include <iostream>

using namespace std;

struct Number
{
    int n;
    bool can_edit;
};

class Game_space : public Base_widget
{
    public:
        Game_space(App*, int x, int y, int sx, int sy);
        void read_grid();
        void draw();
        void handle(genv::event ev);
        int get_szam();

    protected:
        vector<vector<Number>> grid;


};

#endif // GAME_SPACE_HPP
