#ifndef BOMB_HPP
#define BOMB_HPP

#include <iostream>
#include <string>
#include <vector>
#include "Player.hpp"

using namespace std;

class Player;

class Bomb
{
private:
    int x;
    int y;
    int owner;
    int range;
    int timer;
    int id;
public:
    Bomb(/* args */);
    Bomb(int x, int y, int owner, int range, int timer, int id);
    ~Bomb();
    Bomb(const Bomb &b);
    Bomb &operator=(const Bomb &b);
    int getX() { return x; }
    int getY() { return y; }
    int getOwner() { return owner; }
    int getRange() { return range; }
    int getTimer() { return timer; }
    void setX(int x) { x = x; }
    void setY(int y) { y = y; }
    void decreaseTimer() { this->timer--; }
    void setBlast(vector<string> &grid);
};

#endif
