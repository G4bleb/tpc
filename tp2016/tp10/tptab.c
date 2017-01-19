/*

Programme produit le  par Gabriel LEBIS
*/
#include <stdio.h>
#define TAB 10

int main(){

  int tab[TAB];
  int i= 0;
  int somme = 0;
  for (i=0; i<TAB; i++){
    printf("Entrez la valeur %d\n", i+1);
    scanf ("%d", &tab[i]);
  }
  for (i=0; i<TAB; i++){
    printf ("Valeur %d : %d\n", i+1, tab[i]);
    somme += tab[i];
  }
  for (i = 0; i+1 < TAB; i++) {
    printf ("%d,", tab[i]);
  }
  printf("%d\n", tab[i]);
  printf("somme : %d, son adresse est %p\n", somme, &somme);
  printf("L'adresse de i est : %p\n", &i);
  for (i=TAB-1; i>=0; i--){
    printf ("Valeur %d : %d, Son Adresse est %p\n", i+1, tab[i], &tab[i]);
  }
  printf("Somme ? :%d\n i ? :%d\n", tab[-1], tab[-2]);
}
