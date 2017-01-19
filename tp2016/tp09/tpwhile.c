/*

Programme produit le  par Gabriel LEBIS
*/
#include <stdio.h>
#define SAISIESMAX 5

int main(){
  int nbr = 10;
  int saisies =0;
  while(nbr >= 0 && saisies<SAISIESMAX) {
    printf("Nombre ? (négatif pour sortir)\n");
    scanf("%d", &nbr);
    saisies ++;
    if (nbr >= 0) {
     printf("Voici la valeur : %d\n", nbr );
     printf("Saisies : %d/%d\n",saisies, SAISIESMAX);
    }
  }
  printf("Terminé !\n");
  return 0;
}
