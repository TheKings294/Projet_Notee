#include "sokoban.h"

int main()
{
    char **Game;
    int Jx;
    int Jy;
    int Bx;
    int By;
    int Fx;
    int Fy;
    int victoire = 0;
    char Dir;
    Game = malloc(13 * sizeof(char *));

    Game[0] = malloc(16 * sizeof(char));
    strcpy(Game[0], "##############");
    Game[0][14] = '\n';
    Game[0][15] = '\0';

    for (int i = 1; i < 11; i++)
    {
        Game[i] = malloc(16 * sizeof(char));
        strcpy(Game[i], "#            #");
        Game[i][14] = '\n';
        Game[i][15] = '\0';
    }

    Game[11] = malloc(16 * sizeof(char));
    strcpy(Game[11], "##############");
    Game[11][14] = '\n';
    Game[11][15] = '\0';
    Game[12] = NULL;

    placeObjet(Game, &Jx, &Jy, &Bx, &By, &Fx, &Fy);
    displaygame(Game);

    while (victoire != 1)
    {
        Dir = -1;
        printf("Choisir une direction : z(avent) q(gauche) s(bas) d(droite)\n");
        scanf("%c", &Dir);

        moveplayer(Game, &Jx, &Jy, Dir);
        displaygame(Game);
    }

    for (int i = 0; i < 11; i++)
    {
        free(Game[i]);
    }

    free(Game);
    return 0;
}