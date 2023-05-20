#include "Game_space.hpp"
#include <cstdlib>
#include <string>
#include <fstream>
#include <time.h>
#include "graphics.hpp"
#include <string>

using namespace std;
using namespace genv;


Game_space::Game_space(App* parent, int x, int y, int sx, int sy) : Base_widget(parent,x,y,sx,sy)
{
    _selected = false;
    read_grid();
}

void Game_space::read_grid()
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
        cout << endl;
        grid.push_back(v);
        v.clear();
    }
}

void Game_space::draw()
{
    int margin = 2;
    int tile = 100;
    int box_size = tile - 2*margin;
    int font_h = (gout.cdescent() + gout.cascent())/2;



    gout << move_to(_x,_y) << color(209, 186, 181) << box(_size_x, _size_y);
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            gout <<color(249, 246, 238) << move_to(i*tile+margin,j*tile+margin) << box(box_size,box_size)
                 <<font("Karate.ttf",40);
            if(grid[i][j].can_edit == false)
            {
                gout << color(0,0,0);
            }
            else if(grid[i][j].n == 0)
            {
                gout << color(249, 246, 238);
            }
            else
            {
                gout << color(128, 102, 96);
            }
            gout << move_to(i*tile+tile/2-gout.twidth(to_string(grid[i][j].n))/2, j*tile+margin+tile/2-font_h) << text(to_string(grid[i][j].n));
            if(j%3 == 0)
            {

                gout << color(255,255,255) << move_to(j*tile-margin, 0) << box(2*margin, 900);
            }
        }
        if(i%3 == 0)
            {

                gout << color(255,255,255) << move_to(0, i*tile-margin) << box(900, 2*margin);
            }

    }
    gout << refresh;
}

int Game_space::get_szam()
{

}
void Game_space::handle(event ev)
{

}


