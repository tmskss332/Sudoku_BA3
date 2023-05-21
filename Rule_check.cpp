#include "Rule_check.hpp"
#include <iostream>
#include <vector>

using namespace std;

Rule_check::Rule_check(vector<vector<Number>> _grid_v) : grid_v(_grid_v)
{
}

void Rule_check::update(vector<vector<Number>> v)
{
    grid_v = v;
}


bool Rule_check::row_check()
{
    bool correct=true;
    vector<int> e;
    e.push_back(0);
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            for(size_t k=0;k<e.size();k++)
            {
                if(e[k] == grid_v[i][j].n)
                {
                    return false;
                }
            }
            e.push_back(grid_v[i][j].n);
        }
        e.clear();
        e.push_back(0);
    }
    return correct;
}
bool Rule_check::column_check()
{

    bool correct = true;
    vector<int> e;
    e.push_back(0);
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            for(size_t k=0;k<e.size();k++)
            {
                if(e[k] == grid_v[j][i].n)
                {
                    return false;
                }
            }
            e.push_back(grid_v[j][i].n);
        }
        e.clear();
        e.push_back(0);
    }
    return correct;
}


bool Rule_check::square_check()
{
    bool correct=true;
    vector<int> e;
    e.push_back(0);
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            for(int _i=0;_i+3*i<3+3*i;_i++)
            {
                for(int _j=0;_j+3*j<3+3*j;_j++)
                {
                    for(size_t k=0;k<e.size();k++)
                    {
                        if(e[k] == grid_v[j][i].n)
                        {
                            return false;
                        }
                    }
                }
            }
            e.clear();
            e.push_back(0);
        }
    }

}

bool Rule_check::completion_check()
{
    return row_check() && column_check() && square_check();
}
