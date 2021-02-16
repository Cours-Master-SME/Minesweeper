#ifndef CELL_H_
#define CELL_H_
#include <vector>

class Cell
{
public:
    
private:
    bool _isAMine;
    bool _isDiscovered;
    int _neighbours;
public:
    Cell(bool mine);
    ~Cell();
    int getNeighbours();
    void getNeighbours(std::vector<std::vector<Cell>> &grid, int x, int y);
    bool hasNeighbours();
    bool discover(std::vector<std::vector<Cell>> &grid, int x, int y);
    bool isDiscovered();
    bool isAMine();
};


#endif // CELL_H_