/*

Programme produit le  par Gabriel LEBIS
*/
#include <stdio.h>
#include <string.h>
int main(){
  int i;
  printf("Chaîne ?\n");
  char chaine [30];
  fgets(chaine, 30, stdin);
  for (i = 0; chaine[i] != '\n'; i++) {
  }
  chaine [i]= '\0';
  printf("La longueur de la chaîne est de %d caractères\n", i);
}
