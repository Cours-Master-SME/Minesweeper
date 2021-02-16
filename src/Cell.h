#ifndef CELL_H_
#define CELL_H_
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
    void setNeighbours(int neighbours);
    int getNeighbours();
    bool isDiscovered();
    bool isAMine();
};


#endif // CELL_H_