#include "sokoban.h"

void moveplayer(char **Game, int *jx, int *jy, char Dir)
{
    switch (Dir)
    {
    case 'z':
        Game[*jx][*jy] = ' ';
        Game[(*jx + 1)][*jy] = 'o';
        break;
    case 'q':
        Game[*jx][*jy] = ' ';
        Game[*jx][(*jy - 1)] = 'o';
        break;
    case 's':
        Game[*jx][*jy] = ' ';
        Game[(*jx - 1)][*jy] = 'o';
        break;
    case 'd':
        Game[*jx][*jy] = ' ';
        Game[*jx][(*jy + 1)] = 'o';
        break;

    default:
        break;
    }
}