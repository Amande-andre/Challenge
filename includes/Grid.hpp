#ifndef GRID_HPP

#define GRID_HPP

#include "Player.hpp"
#include <vector>

class Grid
{
private:
public:
    Grid(/* args */);
    ~Grid();
    void updateGrid();
    void updateEntities();
    vector<string> grid;
    vector<vector<int>> entitiesList;
    
};



#endif
