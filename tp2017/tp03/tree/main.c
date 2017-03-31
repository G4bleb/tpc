#include "header.h"
int main(){
  noeud* racine = NULL;
  racine = inserer("avion", "plane", racine);
  racine = inserer("age", "age", racine);
  racine = inserer("noeud", "node", racine);
  printf("Root : FR : %s ENG : %s\n", racine->motfr, racine->moteng);
  noeud *filsde = racine->filsG;
  printf("FilsG : FR : %s ENG : %s\n", filsde->motfr, filsde->moteng);
  filsde = racine->filsD;
  printf("FilsD : FR : %s ENG : %s\n", filsde->motfr, filsde->moteng);
  traduction("age", racine);
  traduction("noeud", racine);
  return 0;
}
