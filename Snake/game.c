#include "snake.h"

int aleatoire() {
    srand(time(NULL));
    int random_number = rand() % 23;

    return random_number;
}
int aleatoireX() {
    srand(time(NULL));
    int random_number = rand() % 39;

    return random_number;
}

void Miam(int *x, int *y, int pos_y, int pos_x, char **tab, Snake **snake) {
 if(pos_x == *x && pos_y == *y) {
 	  add_to_end(snake, pos_x, pos_y);
      *x = aleatoireX();
      *y = aleatoire();

      while(tab[*y][*x] == 'X' || tab[*y][*x] == '#') {
         *x = aleatoireX();
      	 *y = aleatoire();
      }

      tab[*y][*x] = 'O';

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

    if(serpent == 874) {
      victoire = 1;
    }
    return victoire;
}