#include "sokoban.h"

void displaygame(char **Game)
{
    for (int i = 0; i < 12; i++)
    {
        printf("%s", Game[i]);
    }
}

void placeObjet(char **Game, int *jx, int *jy, int *bx, int *by, int *fx, int *fy)
{
    srand(time(NULL));
    int random_line_j = rand() % 10 + 1;
    int random_colum_j = rand() % 10 + 1;

    /*Placer le joueur*/
    Game[random_line_j][random_colum_j] = 'o';
    *jx = random_line_j;
    *jy = random_colum_j;

    /*Placer Box Entrepot*/

    int random_line_b = rand() % 9 + 2;
    int random_colum_b = rand() % 9 + 2;

    if (random_line_j == random_line_b)
    {
        random_line_b = rand() % 9 + 2;
    }
    Game[random_line_b][random_colum_b] = 'X';
    *bx = random_line_b;
    *by = random_colum_b;

    /*Placer point de finich*/

    int random_line_f = rand() % 10 + 1;
    int random_colum_f = rand() % 10 + 1;

    if (random_line_f == random_line_b)
    {
        random_line_f = rand() % 10 + 1;
    }

    Game[random_line_f][random_colum_f] = '.';
    *fx = random_line_f;
    *fy = random_colum_f;
}