/*

Fichier des prototypes des fonctions utiliser par le bot pour jouer contre l'humain

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "AntiCheat.h"

int Randome()
{
    srand(time(NULL));
    int random_number = rand() % 8;

    return random_number;
}

int BotGame(char *p)
{
    int PlayerBloced;
    for (int i = 0; i < 9; i += 3)
    {
        if (p[i] == 'X' && p[i + 1] == 'X' && p[i + 2] == ' ')
        {
            PlayerBloced += 1;
            return (i + 2);
        }
        else if (p[i] == ' ' && p[i + 1] == 'X' && p[i + 2] == 'X')
        {
            PlayerBloced += 1;
            return i;
        }
        else if (p[i] == 'X' && p[i + 1] == ' ' && p[i + 2] == 'X')
        {
            PlayerBloced += 1;
            return (i + 1);
        }
    }

    if (PlayerBloced == 0)
    {
        for (int i = 0; i < 9; i++)
        {
            if (p[i] == 'X' && p[i + 3] == 'X' && p[i + 6] == ' ')
            {
                PlayerBloced += 1;
                return (i + 2);
            }
            else if (p[i] == ' ' && p[i + 3] == 'X' && p[i + 6] == 'X')
            {
                PlayerBloced += 1;
                return i;
            }
            else if (p[i] == 'X' && p[i + 3] == ' ' && p[i + 6] == 'X')
            {
                PlayerBloced += 1;
                return (i + 1);
            }
        }

        if (p[0] == 'X' && p[4] == 'X' && p[8] == ' ')
        {
            PlayerBloced += 1;
            return 8;
        }
        else if (p[0] == ' ' && p[4] == 'X' && p[8] == 'X')
        {
            PlayerBloced += 1;
            return 0;
        }
        else if (p[0] == 'X' && p[4] == ' ' && p[8] == 'X')
        {
            PlayerBloced += 1;
            return 4;
        }

        if (p[2] == 'X' && p[4] == 'X' && p[6] == ' ')
        {
            PlayerBloced += 1;
            return 6;
        }
        else if (p[2] == ' ' && p[4] == 'X' && p[6] == 'X')
        {
            PlayerBloced += 1;
            return 2;
        }
        else if (p[2] == 'X' && p[4] == ' ' && p[6] == 'X')
        {
            PlayerBloced += 1;
            return 4;
        }
    }

    while (AntiCheat(Randome(), p) == 1)
    {
        // retry
    }
    return Randome();
}
