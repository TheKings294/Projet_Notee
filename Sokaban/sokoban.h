#ifndef __SOKABAN_H__
#define __SOKABAN_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

/*Prototype des fonctions du fichier plateau*/
void displaygame(char **Game);
void placeObjet(char **Game, int *jx, int *jy, int *bx, int *by, int *fx, int *fy);

/*Prototype des fonctions du mouvement du joueur*/
void moveplayer(char **Game, int *jx, int *jy, char Dir, int *bx, int *by);
int movebox(char **Game, int *bx, int *by, char Dir);

/*Prototype des fonctions de la victoire*/
int victoire(int *bx, int *by, int fx, int fy, char **Game);
#endif