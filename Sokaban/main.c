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
    int victoir = 0;
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
    system("clear");
    printf(" ## ##    ## ##   ##  ###   ## ##   ### ##     ##     ###  ##\n");
    printf("##   ##  ##   ##  ##  ##   ##   ##   ##  ##     ##      ## ## \n");
    printf("####     ##   ##  ## ##    ##   ##   ##  ##   ## ##    # ## #  \n");
    printf(" #####   ##   ##  ## ##    ##   ##   ## ##    ##  ##   ## ##   \n");
    printf("    ###  ##   ##  ## ###   ##   ##   ##  ##   ## ###   ##  ##  \n");
    printf("##   ##  ##   ##  ##  ##   ##   ##   ##  ##   ##  ##   ##  ##  \n");
    printf(" ## ##    ## ##   ##  ###   ## ##   ### ##   ###  ##  ###  ##  \n\n");

    printf("Joueur : %d %d\n", Jx, Jy);
    printf("Boite : %d %d\n", Bx, By);
    printf("Emplacement : %d %d\n", Fx, Fy);
    displaygame(Game);

    while (victoir != 1)
    {
        Dir = 0;
        if (Game[Fx][Fy] == ' ')
        {
            Game[Fx][Fy] = '.';
        }
        printf("Choisir une direction : z(avent) q(gauche) s(bas) d(droite)\n");
        scanf("%c", &Dir);

        moveplayer(Game, &Jx, &Jy, Dir, &Bx, &By);
        system("clear");
        printf("Joueur : %d %d\n", Jx, Jy);
        printf("Boite : %d %d\n", Bx, By);
        printf("Emplacement : %d %d\n", Fx, Fy);
        displaygame(Game);

        victoir = victoire(&Bx, &By, Fx, Fy, Game);
    }

    for (int i = 0; i < 11; i++)
    {
        free(Game[i]);
    }

    free(Game);
    return 0;
}