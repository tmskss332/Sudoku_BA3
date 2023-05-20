#ifndef GAME_SPACE_HPP
#define GAME_SPACE_HPP

#include <vector>
#include <iostream>

using namespace std;

struct Number
{
    int n;
    bool can_edit;
};

class Game_space
{
    public:
        Game_space();
        void read_grid();
        void draw();
    protected:
        vector<vector<Number>> grid;


};

#endif // GAME_SPACE_HPP
