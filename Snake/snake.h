#ifndef SNAKE_H
#define SNAKE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

typedef struct Snake Snake;
struct Snake {
  int x;
  int y;
  Snake *next;
  };

/*Createmap.c*/
char *get_file(FILE *fp);
void display_tab(char **tab, int lines);
int count_lines(char *str);

/*Game*/
int aleatoire();
void movesnake();

#endif