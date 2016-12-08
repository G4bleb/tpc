/*

Programme produit le  par Gabriel LEBIS
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LM 50
int main(){
  int i;
  char chaine1[LM];
  char* tab_chaine[3];
  for (i = 0; i < 3; i++) {
    printf("Saisir une chaîne de caractères (longueur max : %d)\n", LM);
    fgets(chaine1, LM, stdin);
    chaine1[strlen(chaine1)-1]='\0';
    tab_chaine[i]= malloc((strlen(chaine1)+1)*sizeof(char));
    strcpy(tab_chaine[i], chaine1);
  }
  printf("\n");
  for (i = 0; i < 3; i++){
    printf("%s\n", tab_chaine[i]);
    free(tab_chaine[i]);}
  return 0;
}
