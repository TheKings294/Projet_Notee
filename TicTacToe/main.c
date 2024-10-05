#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "./header/AntiCheat.h"
#include "./header/jeux.h"
#include "./header/Verif.h"
#include "./header/bot.h"
#define HUMANSYMBOL 'X'
#define BOTSYMBOL 'O'

char Plateau[9];
int ChoiseOfHumanPlayer;
int i = 0;

int Random()
{
    srand(time(NULL));
    int random_number = rand() % 8;

    return random_number;
}

int main()
{
    system("clear");

    printf(" TTTTT  III  CCCCC   TTTTT    A     CCCCC   TTTTT   OOO   EEEEE \n");
    printf("   T     I  C          T     A A   C          T    O   O  E     \n");
    printf("   T     I  C          T    AAAAA  C          T    O   O  EEEE  \n");
    printf("   T     I  C          T    A   A  C          T    O   O  E     \n");
    printf("   T    III  CCCCC     T    A   A   CCCCC     T     OOO   EEEEE \n\n");

    while (Plateau[i] != '\0')
    {
        Plateau[i] = ' ';
    }

    int count = 0;
    affichPlateauStart();

    printf("\n\nVous commencez !\n");

    while (count < 9)
    {
        printf("Choisisez ou jouer :");
        scanf("%d", &ChoiseOfHumanPlayer);

        if (AntiCheat(ChoiseOfHumanPlayer, Plateau) == 1)
        {
            ChoiseOfHumanPlayer = 9;
            printf("Bien essayer mais il y a un anti cheat");
            printf("Recommence : ");
            scanf("%d", &ChoiseOfHumanPlayer);
        }
        Plateau[ChoiseOfHumanPlayer] = HUMANSYMBOL;
        count++;

        if (VerifWinner(Plateau) == 1)
        {
            affichePlateauEnJeux(Plateau);
            printf("le jeux est fini c'est l'humain qui gagne !");
            return 0;
        }
        else if (VerifWinner(Plateau) == 10)
        {
            affichePlateauEnJeux(Plateau);
            printf("Match Nul !");
            return 0;
        }

        if (count > 2)
        {
            sleep(1);
            int Were = BotGame(Plateau);
            Plateau[Were] = 'O';
        }
        else
        {
            sleep(1);
            while (AntiCheat(Random(), Plateau) == 1)
            {
                // retry
            }

            Plateau[Random()] = BOTSYMBOL;
            count++;
        }

        if (VerifWinner(Plateau) == 1)
        {
            affichePlateauEnJeux(Plateau);
            printf("le jeux est fini c'est le Bot qui gagne !");
            return 0;
        }

        system("clear");
        affichePlateauEnJeux(Plateau);
    }

    return 0;
}

/*
    srand(time(NULL));
    int random_number = rand() % 100 + 1;

    Fonction pour genere un nombre aléatoire entre 1 et 100
*/