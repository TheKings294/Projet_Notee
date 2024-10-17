#ifndef SNAKE_H
#define SNAKE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

/*Createmap.c*/
char *get_file(FILE *fp);
//void createmap(SDL_Surface *surface, SDL_Renderer *renderer, char **map, int lines);
void display_tab(char **tab, int lines);
int count_lines(char *str);

#endif