#include "Game_space.hpp"


using namespace std;
using namespace genv;


Game_space::Game_space(App* parent, int x, int y, int sx, int sy, vector<vector<Number>> _grid) : Base_widget(parent,x,y,sx,sy), grid(_grid)
{
    active = true;
    _selected = false;
    completed = false;
    menu = true;
}


void Game_space::draw()
{
    int margin = 2;
        int tile = 100;
        int box_size = tile - 2*margin;
        int font_h = (gout.cdescent() + gout.cascent())/2;

    if(menu && !completed)
    {
        //hatter innentol
        vector<RGB> pics;
        ifstream file("bg.csv");

        if (!file)
        {
            cout << "Nem sikerult megnyitni a fajlt" << endl;
        }

        string line;
        while (getline(file, line))
        {
            istringstream iss(line);
            string value;

            RGB pic;
            getline(iss, value, ';');
            pic.r = stoi(value);

            getline(iss, value, ';');
            pic.g = stoi(value);

            getline(iss, value, ';');
            pic.b = stoi(value);

            pics.push_back(pic);
        }

        file.close();
        canvas c;
        c.open(900,900);
        int x = 0;
        for(int i = 0; i < 900;i++)
        {
            for(int j = 0; j < 900;j++)
            {
                c << move_to(i,j) << color(pics[x].r,pics[x].g,pics[x].b) << box(1,1);
                x += 1;
            }
        }
        gout << stamp(c,_x,_y);

        //idaig

        gout << font("Karate.ttf",90)
             << move_to(_x + _size_x/2 - gout.twidth("Sudoku")/2, _y+(_size_y-gout.cascent()-gout.cdescent())/2)
             << color(0,0,0) << text("Sudoku");
        gout << font("Karate.ttf",85)
             << move_to(_x + _size_x/2 - gout.twidth("Sudoku")/2, _y+(_size_y-gout.cascent()-gout.cdescent())/2)
             << color(255,0,0) << text("Sudoku");
        gout << font("Karate.ttf",80)
             << move_to(_x + _size_x/2 - gout.twidth("Sudoku")/2, _y+(_size_y-gout.cascent()-gout.cdescent())/2)
             << color(255,255,255)<< text("Sudoku");
    }



    else if(!menu && !completed)
    {
        gout << move_to(_x,_y) << color(209, 186, 181) << box(_size_x, _size_y);
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {

                gout <<color(249, 246, 238) << move_to(i*tile+margin,j*tile+margin) << box(box_size,box_size)
                     <<font("Karate.ttf",40);
                if(grid[j][i].can_edit == false)
                {
                    gout << color(0,0,0);
                }
                else if(grid[j][i].n == 0)
                {
                    gout << color(249, 246, 238);
                }
                else
                {
                    gout << color(128, 102, 96);
                }
                gout << move_to(i*tile+tile/2-gout.twidth(to_string(grid[j][i].n))/2, j*tile+margin+tile/2-font_h) << text(to_string(grid[j][i].n));
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
    }
    else if(!menu && completed)
    {
        gout << move_to(_x,_y) << color(209, 186, 181) << box(_size_x, _size_y);
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {

                gout <<color(249, 246, 238) << move_to(i*tile+margin,j*tile+margin) << box(box_size,box_size)
                     <<font("Karate.ttf",40)<< move_to(i*tile+tile/2-gout.twidth(to_string(grid[j][i].n))/2, j*tile+margin+tile/2-font_h) << color(0,0,0) << text(to_string(grid[j][i].n));
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
        for(int i=0;i<=450;i++)
        {
            for(int j=0;j<=450;j++)
            {
                gout << move_to(i*2,j*2) << color(255,255,255) << dot;
            }
        }
        gout << font("Karate.ttf",130)
             << move_to(_x + _size_x/2 - gout.twidth("Puzzle Solved")/2, 300)
             << color(255,255,255) << text("Puzzle Solved");
        gout << font("Karate.ttf",129)
             << move_to(_x + _size_x/2 - gout.twidth("Puzzle Solved")/2, 300)
             << color(255,0,0) << text("Puzzle Solved");
        gout << font("Karate.ttf",128)
             << move_to(_x + _size_x/2 - gout.twidth("Puzzle Solved")/2, 300)
             << color(0,0,0)<< text("Puzzle Solved");
    }
}


void Game_space::handle(event ev)
{

}
void Game_space::update(vector<vector<Number>> v)
{
    grid = v;
}
bool Game_space::is_selected(int xp, int yp)
{
    return false;
}

void Game_space::status(bool m, bool g, bool v)
{
    if(g)
    {
        menu = false;
        completed = false;
    }
    if(v)
    {
        completed = true;
    }
}
