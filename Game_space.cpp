#include "Game_space.hpp"
#include <cstdlib>
#include <string>
#include <fstream>
#include <time.h>

using namespace std;


Game_space::Game_space()
{
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
            cout << _n.n << "||" << _n.can_edit << "    ";
            v.push_back(_n);
        }
        cout << endl;
        grid.push_back(v);
        v.clear();
    }
}

void Game_space::draw()
{

}


