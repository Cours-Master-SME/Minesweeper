#include "Cell.h"
Cell::Cell(bool mine)
{
    _isAMine = mine;
    _isDiscovered = false;
    _neighbours = 0;
}
Cell::~Cell()
{

}
void Cell::setNeighbours(int neighbours)
{
    _neighbours = neighbours;
}
int Cell::getNeighbours()
{
    return _neighbours;
}
bool Cell::isDiscovered()
{
    return _isDiscovered;
}
bool Cell::isAMine()
{
    return _isAMine;
}