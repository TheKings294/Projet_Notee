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
    //display_tab(tab, lines);

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0) {
        printf("Error SDL2 Init : %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 448, SDL_WINDOW_OPENGL);
    if (window == NULL) {
        printf("Error Window Creation\n");
        return 3;
    }
    if (IMG_Init(IMG_INIT_PNG) == 0)
    {
        printf("Erreur d'initialisation de la SDL_Image\n");
        return 1;
    }
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL)
    {
        printf("Erreur à la création du renderer\n");
        return 1;
    }
    SDL_Surface* surface = IMG_Load("levels.png");
    if (surface == NULL)
    {
        printf("Error loading image %s\n", IMG_GetError());
        return 1;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (texture == NULL)
    {
        printf("Error creating texture\n");
    }
    SDL_FreeSurface(surface);

    i = 0;
    j = 0;
    SDL_RenderClear(renderer);
    while(i < lines) {
      j = 0;
        while(j < 40) {
            if(tab[i][j] == '#') {
                SDL_Rect rect = {0, 0, 16, 16};
                SDL_Rect dist = {j * 16, i * 16, 16, 16};
                SDL_RenderCopy(renderer, texture, &rect, &dist);
            }
            else {

            }

            j++;
        }
        i++;
    }
    SDL_RenderPresent(renderer);

    while (1)
    {
        SDL_Event e;
        if (SDL_WaitEvent(&e)) {
            if (e.type == SDL_QUIT) {
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

    //SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
    return 0;
}