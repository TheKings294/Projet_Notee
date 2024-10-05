/*

Fichier des prototypes des fonctions de mon affichage et fonctionement du jeux

*/

void affichPlateauStart()
{
    printf("   |   |   \n ---------- \n   |   |   \n ---------- \n   |   |   ");
}

void affichePlateauEnJeux(char *p)
{
    printf("  %c | %c | %c \n ---------- \n  %c | %c | %c \n ---------- \n  %c | %c | %c \n", p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7], p[8]);
}