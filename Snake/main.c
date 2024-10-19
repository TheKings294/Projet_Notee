#include "snake.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

int main(void) {

    FILE *fp = fopen("map.txt", "r");
    FILE *fp2 = fopen("lives.txt", "r");
    char * map;
    char * lives;
    char **tab;
    char * line;
    int lines;
    int *tab2;
    int i = 0;
    int j = 0;
    int heady = 5;
    int headx = 4;
    int foody = aleatoire();
    int foodx = aleatoire();
    int score = 0;
    Direction curentDirection = RIGHT;

    map = get_file(fp);
    lives = get_file(fp2);
    lines = count_lines(map);

    tab = malloc(lines * sizeof(*tab));
    tab2 = malloc(lines * sizeof(int));

    line = strtok(map, "\n");
    while((line != NULL) && (i < lines))
    {
        tab[i] = malloc(strlen(line) * sizeof(char));
        tab[i] = strcpy(tab[i], line);
        i++;

        line = strtok(NULL, "\n");
    }

    line = strtok(lives, "\n");
    tab2[0] = atoi(line);
    line = strtok(NULL, "\n");
    tab2[1] = atoi(line);

    free(map);
    fclose(fp);
    free(lives);
    fclose(fp2);

    Snake *snakeHead;
    snakeHead = create_list(heady, headx);
    add_to_end(&snakeHead, heady, (headx - 1));
	add_to_end(&snakeHead, heady, (headx - 2));

    tab[foody][foodx] = 'O';

    display_list(&snakeHead, tab);

    printf("%d\n", tab2[0]);
    printf("%d\n", tab2[1]);


    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0) {
        printf("Error SDL2 Init : %s\n", SDL_GetError());
        return 1;
    }
    if (TTF_Init() == -1) {
    SDL_Log("Unable to initialize SDL_ttf: %s", TTF_GetError());
    return 1;
	}
    TTF_Font *font = TTF_OpenFont("/System/Library/Fonts/MarkerFelt.ttc", 20); // Remplace "path/to/font.ttf" par le chemin de ta police, et 24 par la taille souhaitée
	if (font == NULL) {
    SDL_Log("Failed to load font: %s", TTF_GetError());
    return 1;
	}
    SDL_Window* window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 448, SDL_WINDOW_OPENGL);
    if (window == NULL) {
         printf("Error while creating a window : %s\n", SDL_GetError());
         return 1;
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
    	return 1;
	}
    SDL_FreeSurface(surface);

    display_game(renderer, texture, font,  tab, lines, score, *tab[1], *tab[0]);

    int winn = 0;
    while (winn == 0)
    {
      SDL_Event e;
        if (SDL_WaitEventTimeout(&e, 125)) {
          if (e.type == SDL_QUIT) {
            break;
            }
            else if (e.type == SDL_KEYDOWN) {
                moved(e, &heady, &headx, tab, &snakeHead, &foody, &foodx, &curentDirection, &winn, &score);
                moove_snake(&snakeHead, heady, headx);
                if(Win(&snakeHead) == 1) {
                	winn = 1;
                }
            	refresh_snake(&snakeHead, tab, lines);
             }
        } else {
            automoved(curentDirection, &heady, &headx, tab, &snakeHead, &foody, &foodx, &winn, &score);
            moove_snake(&snakeHead, heady, headx);
            if(Win(&snakeHead) == 1) {
               winn = 1;
            }
              refresh_snake(&snakeHead, tab, lines);
        }
        display_game(renderer, texture, font, tab, lines, score, *tab[1], *tab[0]);
    }

    while((line != NULL) && (i < lines))
    {
        free(tab[i]);
        i++;
    }
    free(tab);
    free(tab2);

    SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	TTF_CloseFont(font);
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();

    return 0;
}