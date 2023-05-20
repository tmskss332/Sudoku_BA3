#include "App.hpp"
#include "base_widget.hpp"
#include "szam_widget.hpp"
#include <iostream>
#include <fstream>
#include <time.h>
#include <vector>
#include "Game_space.hpp"

using namespace genv;


class Sudoku : public App
{
private:
    Szam_widget* sw;
    Game_space* grid;

public:
    Sudoku()
    {
        sw = new Szam_widget(this,0,0,90,90,1,9);
        grid = new Game_space(this,0,0,900,900);
        register_widget(sw);
        register_widget(grid);
    }
};
int main()
{
    Sudoku game;
    game.game_loop();
    return 0;
}
