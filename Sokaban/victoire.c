#include "sokoban.h"

int victoire(int bx, int by, int fx, int fy)
{
    if (bx == fx && by == fy)
    {
        printf("Vous avez gagner !\n");
        return 1;
    }
    return 0;
}