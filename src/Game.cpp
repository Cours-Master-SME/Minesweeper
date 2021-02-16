#include "Game.h"
#include <iostream>
Game::Game(int x, int y)
{
    _Grid.reserve(x);
    for (size_t i = 0; i < x; i++)
        _Grid[i].reserve(y);

//    for (size_t i = 0; i < _Grid.size(); i++)
//        for (size_t j = 0; j < _Grid[i].size(); j++)
//            _Grid[i][j]
}
Game::~Game()
{

}
void Game::begin()
{
    printGrid();
}
void Game::discover(int x, int y)
{

}
void Game::printGrid()
{
    for (size_t i = 0; i < _Grid.size(); i++)
    {
        std::cout << '|';
        for (size_t j = 0; j < _Grid[i].size(); j++)
        {
            char c = '#';
            if (_Grid[i][j].isDiscovered())
            {
                c = _Grid[i][j].getNeighbours();
                c = c > 0 ? c + '0' : ' ';
            }
            std::cout << c << '|';
        }
        std::cout << std::endl;
    }
}