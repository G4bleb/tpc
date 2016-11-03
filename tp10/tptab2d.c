/*

Programme produit le 12/10/16 par Gabriel LEBIS
*/
#include <stdio.h>
#define NL 2
#define NC 3

int main(){
  int i=0;
  int j=0;
  int somlign=0;
  int sommetotale = 0;

  int tab [NL] [NC] = {{12,7,18},{1,14,2}};
  int somcol [NC] = {0};

  for (i = 0; i < NL; i++) { //passe sur chaque ligne
    for (j = 0; j < NC; j++) { //passe sur chaque élément de la ligne
      printf("\e[4m%4d|",tab[i][j]); //On affiche l'élément (souligné)
      somlign+=tab[i][j];
      somcol[j]+=tab[i][j]; //On incrémente au total de la colonne en cours
    }
    printf("%4d\n",somlign);
    somlign=0;
  }
  for (j = 0; j < NC; j++) {
    printf("%4d|",somcol[j]); //Affichage de l'élément de la dernière ligne
    sommetotale+=somcol[j]; //Incrémentation à la dernière valeur
  }
  printf("%4d\n\e[24m", sommetotale);
  return 0;
}
