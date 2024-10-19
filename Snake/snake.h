#ifndef SNAKE_H
#define SNAKE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

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
void Miam(int *x, int *y, int pos_y, int pos_x, char **tab, Snake **snake, int *score);
int Win(Snake **snake);
void moved(SDL_Event e, int *y, int *x, char **tab, Snake **snake, int *fy, int *fx, Direction *curentDirection, int *winn, int *score);
void automoved(Direction curentDirection, int *y, int *x, char **tab, Snake **snake, int *fy, int *fx, int *winn, int *score);

/*Liste chaine*/
Snake *create_list(int pos_y, int pos_x);
void display_list(Snake **list, char **tab);
void add_to_end(Snake **list, int pos_y, int pos_x);
void delete_list(Snake **list);
void moove_snake(Snake **list, int pos_y, int pos_x);
void refresh_snake(Snake **list, char **tab, int line);

/*sdl*/
void display_game(SDL_Renderer* renderer, SDL_Texture* texture, TTF_Font *font, char **tab, int lines, int score, int hightscore, int game);

#endif