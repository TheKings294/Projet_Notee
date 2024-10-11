#include "sokoban.h"

int victoire(int *bx, int *by, int fx, int fy, char **Game)
{
    if (*bx == fx && *by == fy)
    {
        printf("Vous avez gagner !\n");
        return 1;
    }
    else if (Game[*bx + 1][*by] == '#' && Game[*bx][*by - 1] == '#' || Game[*bx - 1][*by] == '#' && Game[*bx][*by + 1] == '#' || Game[*bx - 1][*by] == '#' && Game[*bx][*by + 1] == '#' || Game[*bx - 1][*by] == '#' && Game[*bx][*by - 1] == '#')
    {
        printf("C'est perdu");
        return 1;
    }
    else if (Game[*bx + 1][*by] == '#' || Game[*bx - 1][*by] == '#' || Game[*bx][*by + 1] == '#' || Game[*bx][*by - 1] == '#')
    {
        printf("C'est perdu");
        return 1;
    }

    return 0;
}