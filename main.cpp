#include "graphics.hpp"
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

public:
    Sudoku()
    {
        sw = new Szam_widget(0,0,900,900,1,9);
    }
};
int main()
{
    Game_space a;
    return 0;
}
