#include "snake.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

char *get_file(FILE *fp) {

  char * content;
  char buffer[10];

  content = malloc(sizeof(char));
  content[0] = '\0';

  while(fgets(buffer, 10, fp) != NULL)
  {
    content = realloc(content, (strlen(buffer) * sizeof(char)) + strlen(content) * sizeof(char) + 1);
    content = strcat(content, buffer);
  }

  return content;
  }
void display_tab(char **tab, int lines)
{
  int i = 0;

  while(i < lines)
  {
    printf("%s\n", tab[i]);
    i++;
  }
}
int count_lines(char *str)
{
  int i = 0;
  int lines = 0;

  while(str[i] != '\0')
  {
    if(str[i] == '\n')
    {
      lines++;
    }

    i++;
  }
  lines += 1;
  return lines;
}

void createmap(SDL_Surface *surface, SDL_Renderer *renderer, char **map, int lines) {

  SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
  if (texture == NULL)
  {
    printf("Error creating texture\n");
  }
  SDL_FreeSurface(surface);

  int i = 0;
  int j = 0;

  while(i < lines) {
      while(j < 40) {
        if(map[i][j] == '#') {
          SDL_Rect rect = {0, 0, 16, 16};
          SDL_Rect dist = {j*16, 0, 16, 16};
          SDL_RenderCopy(renderer, texture, &dist, &rect);
          }

          j++;
    }
    i++;
  }
}