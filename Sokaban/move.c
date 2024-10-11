#include "sokoban.h"

int movebox(char **Game, int *bx, int *by, char Dir)
{
    switch (Dir)
    {
    case 'z':
        if (Game[*bx - 1][*by] == '#')
        {
            return 1;
        }
        else
        {
            Game[*bx][*by] = ' ';
            Game[*bx - 1][*by] = 'X';
            *bx = *bx - 1;
            return 0;
        }
        break;
    case 'q':
        if (Game[*bx][*by - 1] == '#')
        {
            return 1;
        }
        else
        {
            Game[*bx][*by] = ' ';
            Game[*bx][*by - 1] = 'X';
            *by = *by - 1;
            return 0;
        }
        break;
    case 's':
        if (Game[*bx + 1][*by] == '#')
        {
            return 1;
        }
        else
        {
            Game[*bx][*by] = ' ';
            Game[*bx + 1][*by] = 'X';
            *bx = *bx + 1;
            return 0;
        }
        break;
    case 'd':
        if (Game[*bx][*by + 1] == '#')
        {
            return 1;
        }
        else
        {
            Game[*bx][*by] = ' ';
            Game[*bx][*by + 1] = 'X';
            *by = *by + 1;
            return 0;
        }
        break;
    default:
        return 0;
        break;
    }
}

void moveplayer(char **Game, int *jx, int *jy, char Dir, int *bx, int *by)
{
    int result;
    switch (Dir)
    {
    case 'z':
        if (Game[(*jx - 1)][*jy] == '#')
        {
        }
        else if (Game[(*jx - 1)][*jy] == 'X')
        {
            result = movebox(Game, bx, by, Dir);
            if (result == 0)
            {
                Game[*jx][*jy] = ' ';
                Game[(*jx - 1)][*jy] = 'o';
                *jx = *jx - 1;
            }
        }
        else
        {
            Game[*jx][*jy] = ' ';
            Game[(*jx - 1)][*jy] = 'o';
            *jx = *jx - 1;
        }
        break;
    case 'q':
        if (Game[*jx][(*jy - 1)] == '#')
        {
        }
        else if (Game[*jx][(*jy - 1)] == 'X')
        {
            result = movebox(Game, bx, by, Dir);
            if (result == 0)
            {
                Game[*jx][*jy] = ' ';
                Game[*jx][(*jy - 1)] = 'o';
                *jy = *jy - 1;
            }
        }
        else
        {
            Game[*jx][*jy] = ' ';
            Game[*jx][(*jy - 1)] = 'o';
            *jy = *jy - 1;
        }
        break;
    case 's':
        if (Game[(*jx + 1)][*jy] == '#')
        {
        }
        else if (Game[(*jx + 1)][*jy] == 'X')
        {
            result = movebox(Game, bx, by, Dir);
            if (result == 0)
            {
                Game[*jx][*jy] = ' ';
                Game[(*jx + 1)][*jy] = 'o';
                *jx = *jx + 1;
            }
        }
        else
        {
            Game[*jx][*jy] = ' ';
            Game[(*jx + 1)][*jy] = 'o';
            *jx = *jx + 1;
        }
        break;
    case 'd':
        if (Game[*jx][(*jy + 1)] == '#')
        {
        }
        else if (Game[*jx][(*jy + 1)] == 'X')
        {
            result = movebox(Game, bx, by, Dir);
            if (result == 0)
            {
                Game[*jx][*jy] = ' ';
                Game[*jx][(*jy + 1)] = 'o';
                *jy = *jy + 1;
            }
        }
        else
        {
            Game[*jx][*jy] = ' ';
            Game[*jx][(*jy + 1)] = 'o';
            *jy = *jy + 1;
        }
        break;

    default:
        break;
    }
}
