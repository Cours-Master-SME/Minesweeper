#include "Game.h"
#include <iostream>
#include <time.h>
#include <ncurses.h>
Game::Game(int x, int y)
{
    _NumberOfMines = 0;
    _UndiscoveredCells = x * y;
    srand(time(NULL));
    _Grid.reserve(x);
    for (size_t i = 0; i < x; i++)
        _Grid[i].reserve(y);

    for (size_t i = 0; i < x; i++)
    {
        _Grid.push_back(std::vector<Cell>());
        for (size_t j = 0; j < y; j++)
        {
            bool mine = !(rand() % 10) ? true : false;
            if (mine)
                _NumberOfMines++;
            _Grid[i].push_back(Cell(mine));
        }
    }
    _ResX = x;
    _ResY = y;
//    for (size_t i = 0; i < _Grid.size(); i++)
//    {
//        for (size_t j = 0; j < _Grid[i].size(); j++)
//        {
//            char c;
//            c = _Grid[i][j].getNeighbours();
//            c = c > 0 ? c + '0' : ' ';
//            if (_Grid[i][j].isAMine())
//                c = '*';
//            std::cout << c << '|';
//        }
//        std::cout << std::endl;
//        
//    }
}
Game::~Game()
{

}
void Game::begin()
{
    for (size_t i = 0; i < _Grid.size(); i++)
    {
        for (size_t j = 0; j < _Grid[i].size(); j++)
        {
            _Grid[i][j].getNeighbours(_Grid, i, j);
        }
    }
    printGrid();
}
void Game::discover(int x, int y)
{
    if (x >= 0 && x < _Grid.size() && y >= 0 && y < _Grid[x].size())
        _Grid[x][y].discover(_Grid, x, y);
}
void Game::printGrid()
{
    move(0, 0);
    for (size_t i = 0; i < _Grid.size(); i++)
    {
        printw("|");
        for (size_t j = 0; j < _Grid[i].size(); j++)
        {
            char c = '#';
            if (_Grid[i][j].isDiscovered())
            {
                c = _Grid[i][j].getNeighbours();
                c = c > 0 ? c + '0' : ' ';
            }
            //else if (_Grid[i][j].isAMine())
            //    c = 'B';
            //std::cout << c << '|';
            printw("%c|", c);
        }
        //std::cout << '\r' << std::endl;
        printw("\n");
    }
    int x, y;
    getsyx(x, y);
    move(x, y);
}
int Game::getX()
{
    return _ResX;
}
int Game::getY()
{
    return _ResY;
}
//void Game::printGrid()
//{
//    for (size_t i = 0; i < _Grid.size(); i++)
//    {
//        std::cout << '|';
//        for (size_t j = 0; j < _Grid[i].size(); j++)
//        {
//            char c = '#';
//            if (_Grid[i][j].isDiscovered())
//            {
//                c = _Grid[i][j].getNeighbours();
//                c = c > 0 ? c + '0' : ' ';
//            }
//            else if (_Grid[i][j].isAMine())
//                c = 'B';
//            std::cout << c << '|';
//        }
//        std::cout << '\r' << std::endl;
//    }
//}