#include "Player.hpp"

Player::Player(/* args */)
{
}
Player::~Player()
{
}
Player::Player(int id, int nbBombsMax, int rangeBombs, int x, int y) : MyId(id), nbBombsMax(nbBombsMax), rangeBombs(rangeBombs), x(x), y(y)
{
}
void Player::addBomb()
{
    if (nbBombs >= nbBombsMax)
        return;
    nbBombs++;
    Bomb b(x, y, MyId, rangeBombs, 8, nbBombs);
    bombs[nbBombs] = b;
}
