#include "snake.h"
#include <SDL2/SDL.h>

int aleatoire() {
    srand(time(NULL));
    int random_number = rand() % 22;

    return random_number;
}
int aleatoireX() {
    srand(time(NULL));
    int random_number = rand() % 38;

    return random_number;
}

void Miam(int *x, int *y, int pos_y, int pos_x, char **tab, Snake **snake, int *score) {
 if(pos_x == *x && pos_y == *y) {
 	  add_to_end(snake, pos_x, pos_y);
      *x = aleatoireX();
      *y = aleatoire();

      while(tab[*y][*x] == 'X' || tab[*y][*x] == '#') {
         *x = aleatoireX();
      	 *y = aleatoire();
      }

      tab[*y][*x] = 'O';

      *score += 10;

	}
}

int Win(Snake **snake) {
	Snake *tmp = *snake;
    int serpent = 0;
    int victoire = 0;

    while(tmp != NULL)
    {
        serpent++;
        tmp = tmp->next;
    }

    if(serpent == 5) { //874
      victoire = 1;
    }
    return victoire;
}

void moved(SDL_Event e, int *y, int *x, char **tab, Snake **snake, int *fy, int *fx, Direction *curentDirection, int *winn, int *score, SDL_Renderer* renderer, SDL_Texture *Texture, TTF_Font *font) {
	SDL_Color color = {255, 255, 255, 255};
	char scoreText[20];
	snprintf(scoreText, sizeof(scoreText), "Score: %d", *score);
	SDL_Surface *scoreTextSurface = TTF_RenderText_Solid(font, scoreText, color);
	if (scoreTextSurface == NULL) {
		SDL_Log("Unable to render text surface: %s", TTF_GetError());
	}
	SDL_Texture *scoreTextTexture = SDL_CreateTextureFromSurface(renderer, scoreTextSurface);
	SDL_FreeSurface(scoreTextSurface);
	if (scoreTextTexture == NULL) {
		SDL_Log("Unable to create texture from surface: %s", SDL_GetError());
	}
  SDL_Rect rect;
  rect.x = 190;
  rect.y = 150;
  SDL_Rect rect2;
  rect2.x = 270;
  rect2.y = 300;
  SDL_QueryTexture(Texture, NULL, NULL, &rect.w, &rect.h);
  SDL_QueryTexture(scoreTextTexture, NULL, NULL, &rect2.w, &rect2.h);
  SDL_RenderClear(renderer);
  switch (e.key.keysym.sym) {
                case SDLK_UP:
                  *y = *y - 1;
                  if(tab[*y][*x] == '#'|| tab[*y][*x] == 'X') {
                    *winn = 1;
                  	SDL_RenderCopy(renderer, Texture, NULL, &rect);
                  	SDL_RenderCopy(renderer, scoreTextTexture, NULL, &rect2);
                  	SDL_RenderPresent(renderer);
                  	sleep(2);
                  }
                  Miam(fy, fx, *y, *x, tab, snake, score);
				  *curentDirection = UP;
                  break;
                case SDLK_DOWN:
                *y = *y + 1;
              	if(tab[*y][*x] == '#'||tab[*y][*x] == 'X') {
              		*winn = 1;
              		SDL_RenderCopy(renderer, Texture, NULL, &rect);
              		SDL_RenderCopy(renderer, scoreTextTexture, NULL, &rect2);
              		SDL_RenderPresent(renderer);
              		sleep(2);
              	}
              	Miam(fy, fx, *y, *x, tab, snake, score);
                *curentDirection = DOWN;
                break;
                case SDLK_LEFT:
                *x = *x - 1;
              	if(tab[*y][*x] == '#' || tab[*y][*x] == 'X') {
              		*winn = 1;
              		SDL_RenderCopy(renderer, Texture, NULL, &rect);
              		SDL_RenderCopy(renderer, scoreTextTexture, NULL, &rect2);
              		SDL_RenderPresent(renderer);
              		sleep(2);
              	}
              	Miam(fy, fx, *y, *x, tab, snake, score);
                *curentDirection = LEFT;
                break;
                case SDLK_RIGHT:
                *x = *x + 1;
              	if(tab[*y][*x] == '#' || tab[*y][*x] == 'X') {
              		*winn = 1;
              		SDL_RenderCopy(renderer, Texture, NULL, &rect);
              		SDL_RenderCopy(renderer, scoreTextTexture, NULL, &rect2);
              		SDL_RenderPresent(renderer);
              		sleep(2);
              	}
              	Miam(fy, fx, *y, *x, tab, snake, score);
                *curentDirection = RIGHT;
                break;
                default:
                  break;
                }

}

void automoved(Direction curentDirection, int *y, int *x, char **tab, Snake **snake, int *fy, int *fx, int *winn, int *score, SDL_Renderer* renderer, SDL_Texture *Texture, TTF_Font *font) {
	SDL_Color color = {255, 255, 255, 255};
	char scoreText[20];
  	snprintf(scoreText, sizeof(scoreText), "Score: %d", *score);
	SDL_Surface *scoreTextSurface = TTF_RenderText_Solid(font, scoreText, color);
	if (scoreTextSurface == NULL) {
		SDL_Log("Unable to render text surface: %s", TTF_GetError());
	}
	SDL_Texture *scoreTextTexture = SDL_CreateTextureFromSurface(renderer, scoreTextSurface);
	SDL_FreeSurface(scoreTextSurface);
	if (scoreTextTexture == NULL) {
		SDL_Log("Unable to create texture from surface: %s", SDL_GetError());
	}
  	SDL_Rect rect;
	rect.x = 190;
	rect.y = 150;
	SDL_Rect rect2;
	rect2.x = 270;
	rect2.y = 300;
	SDL_QueryTexture(Texture, NULL, NULL, &rect.w, &rect.h);
	SDL_QueryTexture(scoreTextTexture, NULL, NULL, &rect2.w, &rect2.h);
	SDL_RenderClear(renderer);
  switch (curentDirection) {
            case UP:
              *y = *y - 1;
              if(tab[*y][*x] == '#'|| tab[*y][*x] == 'X') {
                  *winn = 1;
              	SDL_RenderCopy(renderer, Texture, NULL, &rect);
              	SDL_RenderCopy(renderer, scoreTextTexture, NULL, &rect2);
              	SDL_RenderPresent(renderer);
              	sleep(2);
              }
              Miam(fy, fx, *y, *x, tab, snake, score);
              break;
            case DOWN:
              *y = *y + 1;
              	if(tab[*y][*x] == '#'||tab[*y][*x] == 'X') {
              		*winn = 1;
              		SDL_RenderCopy(renderer, Texture, NULL, &rect);
              		SDL_RenderCopy(renderer, scoreTextTexture, NULL, &rect2);
              		SDL_RenderPresent(renderer);
              		sleep(2);
              	}
              	Miam(fy, fx, *y, *x, tab, snake, score);
              break;
            case LEFT:
              *x = *x - 1;
              if(tab[*y][*x] == '#' || tab[*y][*x] == 'X') {
                *winn = 1;
              	SDL_RenderCopy(renderer, Texture, NULL, &rect);
              	SDL_RenderCopy(renderer, scoreTextTexture, NULL, &rect2);
              	SDL_RenderPresent(renderer);
              	sleep(2);
              }
              Miam(fy, fx, *y, *x, tab, snake, score);
              break;
            case RIGHT:
              *x = *x + 1;
              if(tab[*y][*x] == '#' || tab[*y][*x] == 'X') {
              	*winn = 1;
              	SDL_RenderCopy(renderer, Texture, NULL, &rect);
              	SDL_RenderCopy(renderer, scoreTextTexture, NULL, &rect2);
              	SDL_RenderPresent(renderer);
              	sleep(2);
              }
              Miam(fy, fx, *y, *x, tab, snake, score);
              break;
            default: break;
            }
}