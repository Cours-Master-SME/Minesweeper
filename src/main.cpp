#include <iostream>
#include <ncurses.h>
#include "Game.h"
int main(int argc, char const *argv[])
{
    Game game = Game(5, 5);
    game.begin();
    //std::cout << "Hello, World" << std::endl;
    return 0;
}
