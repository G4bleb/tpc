/*
Copie d'une chaine1 vers une chaine2 sans utiliser la fonction strcpy
Programme produit le 19/10/16 par Gabriel LEBIS
*/
#include <stdio.h>
#include <string.h>
#define LM 60
int main(){
  int i;
  printf("Chaîne ?\n");
  char chaine [LM];
  char chaine2 [LM];
  fgets(chaine, LM, stdin);
  for (i = 0; chaine[i] != '\n'; i++) {
    chaine2[i]=chaine[i];
  }
  chaine2 [i]= '\0';
  printf("chaine2 : \n%s\n", chaine2);
}
