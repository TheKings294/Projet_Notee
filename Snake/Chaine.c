#include "snake.h"

Snake *create_list(int pos_y, int pos_x) {
    Snake *first = malloc(sizeof(*first));
    first->y = pos_y;
    first->x = pos_x;
    first->next = NULL;

    return first;
}

void add_to_end(Snake **list, int pos_y, int pos_x)
{
    Snake *tmp = *list;

    while(tmp->next != NULL)
    {
        tmp = tmp->next;
    }

    Snake *item = malloc(sizeof(*item));
    item->y = pos_y;
    item->x = pos_x;
    item->next = NULL;

    tmp->next = item;
}

void display_list(Snake **list, char **tab)
{
    Snake *tmp = *list;

    while(tmp != NULL)
    {
        tab[tmp->y][tmp->x] = 'X';
        tmp = tmp->next;
    }
}
void delete_list(Snake **list)
{
    Snake *tmp = *list;

    while(tmp != NULL)
    {
        Snake *to_remove = tmp;
        tmp = tmp->next;
        free(to_remove);
    }
}

void moove_snake(Snake **list, int pos_y, int pos_x) {
  Snake *tmp = *list;

  Snake *to_add = malloc(sizeof(Snake));
        to_add->x = pos_x;
        to_add->y = pos_y;
        to_add->next = tmp;
        *list = to_add;

  while(tmp->next->next != NULL) {
  	  tmp = tmp->next;
  }
  free(tmp->next);
  tmp->next = NULL;
}

void refresh_snake(Snake **list, char **tab, int line) {
  int i = 0;
  int j = 0;
  while(i < line) {
  j = 0;
  	while(j < 40) {
    	if(tab[i][j] == 'X') {
    		tab[i][j] = ' ';
    	}
        j++;
  	}
    i++;
  }

  Snake *tmp = *list;

    while(tmp != NULL)
    {
        tab[tmp->y][tmp->x] = 'X';
        tmp = tmp->next;
    }

}

