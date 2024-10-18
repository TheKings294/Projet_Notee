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

typedef enum {UP, DOWN, LEFT, RIGHT} Direction;

/*Createmap.c*/
char *get_file(FILE *fp);
void display_tab(char **tab, int lines);
int count_lines(char *str);

/*Game*/
int aleatoire();
int aleatoireX();
void Miam(int *x, int *y, int pos_y, int pos_x, char **tab, Snake **snake);
int Win(Snake **snake);

/*Liste chaine*/
Snake *create_list(int pos_y, int pos_x);
void display_list(Snake **list, char **tab);
void add_to_end(Snake **list, int pos_y, int pos_x);
void delete_list(Snake **list);
void moove_snake(Snake **list, int pos_y, int pos_x);
void refresh_snake(Snake **list, char **tab, int line);

#endif