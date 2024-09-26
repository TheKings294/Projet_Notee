#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, const char * argv[]) {
    srand(time(NULL));
    int random_number = rand() % 100 + 1;
    int nb_user;
 
    printf(" M   M    A    GGGG  I  CCCC     N   N  U   U  M   M  BBBB  EEEEE  RRRR  \n");
    printf(" MM MM   A A   G     I  C        NN  N  U   U  MM MM  B   B  E      R   R \n");
    printf(" M M M  AAAAA  G  GG I  CCCC     N N N  U   U  M M M  BBBB   EEEEE  RRRR  \n");
    printf(" M   M  A   A  G   G I  C        N  NN  U   U  M   M  B   B  E      R  R  \n");
    printf(" M   M  A   A   GGGG I  CCCC     N   N   UUU   M   M  BBBB   EEEEE  R   R \n\n");
    
    while (random_number != nb_user) {
        nb_user = -1;
        printf("Donne un nombre entre 1 et 100 : ");
        scanf("%d", &nb_user);
        
        if ((nb_user != random_number) && (nb_user >= 1 && nb_user <= 100)) {
            if (nb_user < random_number) {
                printf("C'est plus !\n");
            }
            else {
                printf("C'est moins !\n");
            }
        }
        else {
            printf("Ton input n'est pas nombre\n");
            exit(0);
        }
    }
    printf("Bravo !\n");
    
    
}
