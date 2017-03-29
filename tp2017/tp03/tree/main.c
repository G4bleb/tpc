#include "header.h"
int main(){
  noeud* racine = malloc(sizeof(noeud));
  racine->motfr = malloc(sizeof("oui"));
  strcpy(racine->motfr, "oui");
  racine->moteng = malloc(sizeof("yes"));
  strcpy(racine->moteng, "yes");
  char mot[] = "non";
  printf("Root : FR : %s ENG : %s\n", racine->motfr, racine->moteng);
  printf("Going to translate\n");
  traduction(mot, racine);
  return 0;
}
