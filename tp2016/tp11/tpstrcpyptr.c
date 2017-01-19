/*
Copie d'une chaine1 vers une chaine2 sans utiliser la fonction strcpy, en utilisant des pointeurs
Programme produit le 03/11/16 par Gabriel LEBIS
*/
#include <stdio.h>
#include <string.h>
#define LM 60
int main(){
  printf("Chaîne ?\n");
  char chaine1 [LM];
  char chaine2 [LM];
  char *ptr1;
  char *ptr2;
  fgets(chaine1, LM, stdin);
  for (ptr1 = chaine1, ptr2 = chaine2; *ptr1 != '\n'; ptr1++, ptr2++) {
    *ptr2 = *ptr1;
  }
  *ptr2='\0';
  printf("chaine2 : \n%s\n", chaine2);
}
