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

