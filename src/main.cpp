#include "Player.hpp"
#include "Bomb.hpp"
#include <vector>
#include "Grid.hpp"

void ft_caseFree(vector<string> grid, Player moi){
    
    moi.leftCaseFree = 0;
    moi.rightCaseFree = 0;
    moi.upCaseFree = 0;
    moi.downCaseFree = 0;
    for (size_t i = moi.getX(); i > 0; i--)
    {   
        if (grid[moi.getY()][i] != '.')
        {
            break;
        }
        moi.leftCaseFree++;
    }
    for (size_t i = moi.getX(); i < grid[0].size(); i++)
    {
        if (grid[moi.getY()][i] != '.')
        {
            break;
        }
        moi.rightCaseFree++;
    }
    for (size_t i = moi.getY(); i > 0; i--)
    {
        if (grid[i][moi.getX()] != '.')
        {
            break;
        }
        moi.upCaseFree++;
    }
    for (size_t i = moi.getY(); i < grid.size(); i++)
    {
        if (grid[i][moi.getX()] != '.')
        {
            break;
        }
        moi.downCaseFree++;
    }
}


void ft_updateTurn(int entity_type, int owner, int x, int y, int param_1, int param_2, map<int, Player> &players, vector<string> grid){
    if (entity_type == 0)
    {
        players[owner].setX(x);
        players[owner].setY(y);
        if (param_1 != players[owner].getNbBombsMax())
        {
            players[owner].setNbBombsMax(param_1);
        }
        if (param_2 != players[owner].getRangeBombs())
        {
            players[owner].setRangeBombs(param_2);
        }
    }
    else if (entity_type == 1)
    {
        players[owner].addBomb();
        cerr << "Bomb added" << players[owner].getX() << ", " << players[owner].getY() << endl;

    }
    (void)grid;
    //ici boucle sans fin peut etre
    // for (size_t i = 0; i < players.size(); i++)
    // {
    //     for (int j = 0; j < players[j].getNbBombsMax(); j++)
    //     {
            
    //         players[i].bombs[j].setBlast(grid);
    //         players[i].bombs[j].decreaseTimer();
    //         if (players[i].bombs[j].getTimer() == 0)
    //         {
    //             players[i].bombs.erase(j);
    //         }
    //     }
    // }
}

int main(){
    int width;
    int height;
    int my_id;
    map<int, Player> players;
    cin >> width >> height >> my_id; cin.ignore();
    for (size_t i = 0; i < 4; i++)
    {
        players[i] = Player(i, 1, 3, 0, 0);
    }
    
    // game loop
    while (1) {
        vector<string> grid;
        for (int i = 0; i < height; i++) {
            string row;
            cin >> row; cin.ignore();
            grid.push_back(row);
        }
        int entities;
        vector<vector<int>> entitiesList;
        cin >> entities; cin.ignore();
        for (int i = 0; i < entities; i++) {
            int entity_type;
            int owner;
            int x;
            int y;
            int param_1;
            int param_2;
            cin >> entity_type >> owner >> x >> y >> param_1 >> param_2; cin.ignore();
            entitiesList.push_back({entity_type, owner, x, y, param_1, param_2});
        }
        //cerr << "Entities: " << entities << endl;
         for (size_t i = 0; i < entitiesList.size(); i++)
        {
              ft_updateTurn(entitiesList[i][0], entitiesList[i][1], entitiesList[i][2], entitiesList[i][3], entitiesList[i][4], entitiesList[i][5], players, grid);
        //     cerr << "Entity type: " << entitiesList[i][0] << " Owner: " << entitiesList[i][1] << " X: " << entitiesList[i][2] << " Y: " << entitiesList[i][3] << " Param 1: " << entitiesList[i][4] << " Param 2: " << entitiesList[i][5] << endl;
        }
        //ft_blastCase(grid, players);
        for (size_t i = 0; i < grid.size(); i++)
        {
            cerr << grid[i] << endl;
        }
        
        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

        cout << "BOMB 6 5" << endl;
    }
}
