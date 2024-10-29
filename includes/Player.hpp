#ifndef PLAYER_HPP

#define PLAYER_HPP

#include "Bomb.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Bomb;

class Player
{
private:
    int MyId;
    int nbBombsMax;
    int rangeBombs;
    int x;
    int y;
public:
    int nbBombs = 0;
    int leftCaseFree = 0;
    int rightCaseFree = 0;
    int upCaseFree = 0;
    int downCaseFree = 0;
    Player(/*ll*/);
    ~Player();
    Player(int id, int nbBombsMax, int rangeBombs, int x, int y);
    map<int, Bomb> bombs;
    int getMyId() { return MyId; }
    int getNbBombsMax() { return nbBombsMax; }
    int getRangeBombs() { return rangeBombs; }
    int getX() { return x; }
    int getY() { return y; }
    void setMyId(int id) { MyId = id; }
    void setNbBombsMax(int nb) { nbBombsMax = nb; }
    void setRangeBombs(int range) { rangeBombs = range; }
    void setX(int x) { x = x; }
    void setY(int y) { y = y; } 
    void addBomb();
};

#endif
