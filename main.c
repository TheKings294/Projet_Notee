#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, const char * argv[]) {
    srand(time(NULL));
    int random_number = rand() % 100 + 1;
    int nb_user;
    
    
    while (random_number != nb_user) {
        printf("Donne un nombre entre 1 et 100 : ");
        scanf("%d", &nb_user);
        
        if (nb_user != random_number) {
            if (nb_user < random_number) {
                printf("C'est plus !\n");
            }
            else {
                printf("C'est moins !\n");
            }        }
    }
    printf("Bravo !\n");
    
    
}
