/*

Programme produit le  par Gabriel LEBIS
*/
#include <stdio.h>

int main(){
  int nbr;
  do {
    printf("Nombre ?\n");
    scanf("%d", &nbr);
    if (nbr >= 0) {
     printf("Voici la valeur : %d\n", nbr );
    }
  } while(nbr >= 0);
  return 0;
}
