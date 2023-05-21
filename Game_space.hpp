#ifndef GAME_SPACE_HPP
#define GAME_SPACE_HPP

#include "base_widget.hpp"
#include <vector>
#include <iostream>

using namespace std;

class Game_space : public Base_widget
{
    public:
        Game_space(App*, int x, int y, int sx, int sy, vector<vector<Number>>);

        void draw();
        void handle(genv::event ev);
        int get_szam();
        bool is_selected(int,int);
        void update(vector<vector<Number>>);

    protected:
        vector<vector<Number>> grid;



};

#endif // GAME_SPACE_HPP
