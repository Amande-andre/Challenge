#include "Grid.hpp"

Grid::Grid(/* args */)
{

}
Grid::~Grid()
{
}
void Grid::updateGrid()
{
    for (int i = 0; i < grid.size(); i++)
    {
        cerr << grid[i] << endl;
    }
}