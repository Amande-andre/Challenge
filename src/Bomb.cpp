#include "Bomb.hpp"

Bomb::Bomb(/* args */)
{
}

Bomb::Bomb(int x, int y, int owner, int range, int timer, int id) : x(x), y(y), owner(owner), range(range), timer(timer), id(id)
{
}
Bomb::~Bomb()
{
}

Bomb::Bomb(const Bomb &b)
{
    *this = b;
}

Bomb &Bomb::operator=(const Bomb &b)
{
    x = b.x;
    y = b.y;
    owner = b.owner;
    range = b.range;
    timer = b.timer;
    id = b.id;
    return *this;
}

void Bomb::setBlast(vector<string> &grid){
    
    for (int i = 0; i < range; i++)
    {
        if (grid[x][y + i] == '.' && y + i < 13)
        {
            grid[x][y + i] = 'B';
        }
        else
            break;
    }
    for (int i = range; i >= 0 ; i--)
    {
        if (grid[x][y - i] == '.' && y - i >= 0)
        {
            grid[x][y - i] = 'B';
        }
        else
            break;
    }
    for (int i = 0; i < range; i++)
    {
        if (grid[x + i][y] == '.' && x + i < 11)
        {
            grid[x + i][y] = 'B';
        }
        else
            break;
    }
    for (int i = range; i >= 0; i--)
    {
        if (grid[x - i][y] == '.' && x - i >= 0)
        {
            grid[x - i][y] = 'B';
        }
        else
            break;
    }
}
