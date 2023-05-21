#include "App.hpp"
#include "base_widget.hpp"
#include "szam_widget.hpp"
#include <iostream>
#include <fstream>
#include <time.h>
#include <vector>
#include "Game_space.hpp"
#include <functional>


using namespace genv;


class Sudoku : public App
{
private:
    Szam_widget* sw;
    Game_space* grid;
    vector<vector<Number>> grid_v;

public:
    Sudoku()
    {
        read_grid();
        sw = new Szam_widget(this,0,0,900,900,1,9, [=](){edit();});
        grid = new Game_space(this,0,0,900,900, grid_v);

    }
    void read_grid()
    {
        vector<Number> v;
        Number _n;
        srand(time(0));
        int g = 10 * (rand() % 50);
        string junk;
        char n;
        ifstream g_file("sudoku.txt");
        for(int i=0;i<=g;i++)
        {
            getline(g_file, junk);
        }
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                g_file >> n;
                _n.n = int(n - '0');

                if(_n.n == 0)
                {
                    _n.can_edit = true;
                }
                else
                {
                    _n.can_edit = false;
                }
                v.push_back(_n);
            }
            grid_v.push_back(v);
            v.clear();
        }
    }
    void edit()
    {
        int a = sw->get_szam();
        Koord k = sw->get_koord();



        if(grid_v[k.x][k.y].can_edit == 1)
        {
            grid_v[k.x][k.y].n = a;
        }
        grid->update(grid_v);
    }
};
int main()
{
    Sudoku game;
    game.game_loop();
    return 0;
}
