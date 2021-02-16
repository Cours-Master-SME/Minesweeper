#include <iostream>
#include <ncurses.h>
#include "Game.h"

#define ENTER 10

void ncurses_initialiser() {
  initscr();	        /* Demarre le mode ncurses */
  cbreak();	            /* Pour les saisies clavier (desac. mise en buffer) */
  noecho();             /* Desactive l'affichage des caracteres saisis */
  keypad(stdscr, TRUE);	/* Active les touches specifiques */
  refresh();            /* Met a jour l'affichage */
  curs_set(TRUE);      /* Masque le curseur */
}

int main(int argc, char const *argv[])
{
    int key;
    int selected=0;
    ncurses_initialiser();
    Game game = Game(10, 10);
    game.begin();

    //std::cout << "Hello, World" << std::endl;
    int x = 0;
    int y = 0;
    
//    while(1)
//    {
//        key=getch();
//        if (key == KEY_DOWN)
//        {
//          x += 1;
//        }
//        else if (key == KEY_UP)
//        {
//          x -= 1;
//        }
//        else if (key == KEY_LEFT)
//        {
//          y -= +1;
//        }
//        else if (key == KEY_RIGHT)
//          y += 1;
//        mvaddch(x, y, NCURSES_ACS(' '));
//        refresh();
//        printf("%d %d\n", x, y);
//        //game.discover(x, y);
//        //game.printGrid();
//    }

//    int x;
//    int y;
    move(0, 1);
    while (1)
    {
        key=getch();
        if (key == KEY_DOWN)
            x += 1;
        else if (key == KEY_UP)
            x -= 1;
        else if (key == KEY_LEFT)
            y -= 1;
        else if (key == KEY_RIGHT)
            y += 1;
        //if (x < 0)
        //    x = 0;
        //if (x >= game.getX() - 1)
        //    x = game.getX() - 1;
        //if (y < 0)
        //    y = 1;
        //if (y >= game.getY() - 2)
        //    y = game.getY() - 2;
        if (x < 0)
            x = 0;
        if (x >= game.getX())
            x = game.getX() - 1;
        if (y < 0)
            y = 0;
        if (y >= game.getY())
            y = game.getY() - 1;
        if (key == ENTER)
        {
            //std::cout << "here\n";
            game.discover(x, y);
            game.printGrid();
        }
        else
        {
            move(x, y * 2 + 1);
            refresh();
        }
    }
    return 0;
}