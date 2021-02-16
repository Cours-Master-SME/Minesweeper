#include "Cell.h"
#include <iostream>

Cell::Cell(bool mine)
{
    _isAMine = mine;
    _isDiscovered = false;
    _neighbours = 0;
}
Cell::~Cell()
{

}
int Cell::getNeighbours()
{
    return _neighbours;
}
void Cell::getNeighbours(std::vector<std::vector<Cell>> &grid, int x, int y)
{
    _neighbours = 0;
    if (_isAMine)
        return;
    for (int i = -1; i < 2; i++)
    {
        for (int j = -1; j < 2; j++)
        {
            if (x + i >= 0 && y + j >= 0 && x + i < grid.size() && y + j < grid[x + i].size())
            {
                if (grid[x + i][y + j].isAMine())
                    _neighbours++;
            }
        }
    }
}
bool Cell::isDiscovered()
{
    return _isDiscovered;
}
bool Cell::isAMine()
{
    return _isAMine;
}
bool Cell::discover(std::vector<std::vector<Cell>> &grid, int x, int y)
{
    _isDiscovered = true;
    if (isAMine())
        return true;
    if (hasNeighbours())
        return false;
    for (int i = -1; i < 2; i++)
    {
        for (int j = -1; j < 2; j++)
        {
            if ((x + i >= 0) && (y + j >= 0) && (x + i < grid.size()) && (y + j < grid[x + i].size()))
            {
                if (!grid[x + i][y + j].isAMine() && !grid[x + i][y + j].isDiscovered())
                    grid[x + i][y + j].discover(grid, x + i, y + j);
            }
        }
    }
    return false;
}
bool Cell::hasNeighbours()
{
    return _neighbours > 0 ? true : false;
}