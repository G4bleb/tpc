#include "header.h"

void traduction(char *mot, noeud* lexique){
  noeud *parcours = lexique;
  noeud *parent = NULL;
  printf("Translating step 1/2\n");
  while (strcmp(mot,parcours->motfr) && parcours != NULL){
    if (strcmp(parcours->motfr, mot)<0){
      parcours = parcours->filsG;
    }else if (strcmp(mot, parcours->motfr)>0){
      parcours = parcours->filsD;
    }else if (strcmp(mot, parcours->motfr)=0){
    }
  }
  printf("Translating step 2/2\n");
  if (parcours == NULL){
    printf("Mot non trouvé\n");
  }else{
    strcpy(mot,parcours->moteng);
    printf("%s\n", mot);
  }
}
