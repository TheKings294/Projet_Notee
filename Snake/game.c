#include "snake.h"

int aleatoire() {
    srand(time(NULL));
    int random_number = rand() % 21 + 2;

    return random_number;
}
int aleatoireX() {
    srand(time(NULL));
    int random_number = rand() % 40 + 2;

    return random_number;
}

void Miam(int *x, int *y, int pos_y, int pos_x, char **tab, Snake **snake) {
 if(pos_x == *x && pos_y == *y) {
 	  add_to_end(snake, pos_x, pos_y);
      *x = aleatoireX();
      *y = aleatoire();

      while(tab[*y][*x] == 'X') {
         *x = aleatoireX();
      	 *y = aleatoire();
      }

      tab[*y][*x] = 'O';

	}
}