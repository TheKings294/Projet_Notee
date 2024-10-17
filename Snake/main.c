#include "snake.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int main(void) {

    FILE *fp = fopen("map.txt", "r");
    char * map;
    int lines;
    char **tab;
    char * line;
    int i = 0;
    int j = 0;

    map = get_file(fp);
    lines = count_lines(map);

    tab = malloc(lines * sizeof(*tab));

    line = strtok(map, "\n");
    while((line != NULL) && (i < lines))
    {
        tab[i] = malloc(strlen(line) * sizeof(char));
        tab[i] = strcpy(tab[i], line);
        i++;

        line = strtok(NULL, "\n");
    }

    free(map);
    fclose(fp);

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0) {
        printf("Error SDL2 Init : %s\n", SDL_GetError());
        return 1;
    }
    SDL_Window* window = SDL_CreateWindow("First program", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL);
    if (window == NULL) {
         printf("Error while creating a window : %s\n", SDL_GetError());
         return 1;
    }

    while (1)
    {
        SDL_Event e;
        if (SDL_WaitEvent(&e)) {
          if (e.type == SDL_QUIT) {
            SDL_Quit();
            break;
            }
            }
    }

    while((line != NULL) && (i < lines))
    {
        free(tab[i]);
        i++;
    }
    free(tab);

    return 0;
}
