#include "snake.h"

int aleatoire() {
    srand(time(NULL));
    int random_number = rand() % 21 + 2;

    return random_number;
  }
