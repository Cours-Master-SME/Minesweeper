#ifndef GAME_H_
#define GAME_H_
#include <vector>
#include "Cell.h"
class Game
{
private:
    std::vector<std::vector<Cell>> _Grid;
public:
    Game(int x, int y);
    ~Game();
    void begin();
    void discover(int x, int y);
    void printGrid();
};

#endif // GAME_H_
