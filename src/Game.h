#ifndef GAME_H_
#define GAME_H_
#include <vector>
#include "Cell.h"

class Game
{
private:
    std::vector<std::vector<Cell>> _Grid;
    int _NumberOfMines;
    int _UndiscoveredCells;
    int _ResX;
    int _ResY;
public:
    Game(int x, int y);
    ~Game();
    void begin();
    void discover(int x, int y);
    void printGrid();
    int getX();
    int getY();
};

#endif // GAME_H_
