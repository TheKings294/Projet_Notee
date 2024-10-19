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

    if(serpent == 5) {
      victoire = 1;
    }
    return victoire;
}

void moved(SDL_Event e, int *y, int *x, char **tab, Snake **snake, int *fy, int *fx, Direction *curentDirection, int *winn, int *score) {
  switch (e.key.keysym.sym) {
                case SDLK_UP:
                  *y = *y - 1;
                  if(tab[*y][*x] == '#'|| tab[*y][*x] == 'X') {
                    *winn = 1;
                  }
                  Miam(fy, fx, *y, *x, tab, snake, score);
				  *curentDirection = UP;
                  break;
                case SDLK_DOWN:
                *y = *y + 1;
              	if(tab[*y][*x] == '#'||tab[*y][*x] == 'X') {
              		*winn = 1;
              	}
              	Miam(fy, fx, *y, *x, tab, snake, score);
                *curentDirection = DOWN;
                break;
                case SDLK_LEFT:
                *x = *x - 1;
              	if(tab[*y][*x] == '#' || tab[*y][*x] == 'X') {
              		*winn = 1;
              	}
              	Miam(fy, fx, *y, *x, tab, snake, score);
                *curentDirection = LEFT;
                break;
                case SDLK_RIGHT:
                *x = *x + 1;
              	if(tab[*y][*x] == '#' || tab[*y][*x] == 'X') {
              		*winn = 1;
              	}
              	Miam(fy, fx, *y, *x, tab, snake, score);
                *curentDirection = RIGHT;
                break;
                default:
                  break;
                }

}

void automoved(Direction curentDirection, int *y, int *x, char **tab, Snake **snake, int *fy, int *fx, int *winn, int *score) {
  switch (curentDirection) {
            case UP:
              *y = *y - 1;
              if(tab[*y][*x] == '#'|| tab[*y][*x] == 'X') {
                  *winn = 1;
              }
              Miam(fy, fx, *y, *x, tab, snake, score);
              break;
            case DOWN:
              *y = *y + 1;
              	if(tab[*y][*x] == '#'||tab[*y][*x] == 'X') {
              		*winn = 1;
              	}
              	Miam(fy, fx, *y, *x, tab, snake, score);
              break;
            case LEFT:
              *x = *x - 1;
              if(tab[*y][*x] == '#' || tab[*y][*x] == 'X') {
                *winn = 1;
              }
              Miam(fy, fx, *y, *x, tab, snake, score);
              break;
            case RIGHT:
              *x = *x + 1;
              if(tab[*y][*x] == '#' || tab[*y][*x] == 'X') {
              	*winn = 1;
              }
              Miam(fy, fx, *y, *x, tab, snake, score);
              break;
            default: break;
            }
}