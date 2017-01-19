/*

Programme produit le  par Gabriel LEBIS
*/
#include <stdio.h>
#include <string.h>
int main(){
  printf("Chaîne ?\n");
  char chaine [30];
  fgets(chaine, 30, stdin);
  chaine [strlen(chaine)-1]='\0';
  printf("La longueur de la chaîne est de %ld caractères\n", strlen(chaine));
}
