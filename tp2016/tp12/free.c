/*

Programme produit le  par Gabriel LEBIS
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LM 50
int main(){
  char chaine1[LM];
  printf("Saisir une chaîne de caractères (longueur max : %d)\n", LM);
  fgets(chaine1, LM, stdin);

  chaine1[strlen(chaine1)-1]='\0';
  char *chaine2 = malloc((strlen(chaine1)+1)*sizeof(char));

  strcpy(chaine2, chaine1);
  printf("%s\n", chaine2);

  free(chaine2);
  return 0;
}
