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
  int brk=1;
  char **tab_chaine = NULL;
  for (i = 0; brk!=0; i++) {
    printf("Saisir la  chaîne de caractères %d (longueur max : %d)\n", i+1, LM);
    fgets(chaine1, LM, stdin);
    chaine1[strlen(chaine1)-1]='\0';
    brk = strcmp("fin",chaine1);
    if (brk){
      tab_chaine= realloc(tab_chaine, ((i+1)*sizeof(char*)));
      tab_chaine[i]= malloc((strlen(chaine1)+1)*sizeof(char));
      strcpy(tab_chaine[i], chaine1);
    }
  }
  printf("\n");
  int nb_chaines = i-1;
  for (i = 0; i < nb_chaines; i++){
    printf("Chaîne %d %s\n", i+1, tab_chaine[i]);
    free(tab_chaine[i]);
  }
  free(tab_chaine);
  return 0;
}
