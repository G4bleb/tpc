#include "header.h"

void traduction(char *mot, noeud* lexique){
  noeud *parcours = lexique;
  printf("Translating...\n");
  int cmp=strcmp(mot,parcours->motfr);
  while (cmp && parcours){
    cmp=strcmp(mot,parcours->motfr);
    printf("Cmp = %d\n", cmp);
    if (cmp<0){
      parcours = parcours->filsG;
    }else if (cmp>0){
      parcours = parcours->filsD;
    }
  }
  if(!cmp){
    printf("%s\n", parcours->moteng);
  }else{
    printf("Mot non trouvé\n");
  }
}

struct noeud* inserer(char *motfr, char *moteng, struct noeud* lexique){
  struct noeud *newnoeud = malloc(sizeof(noeud*));
  newnoeud->motfr=malloc(strlen(motfr)+1);
  newnoeud->moteng=malloc(strlen(moteng)+1);
  strcpy(newnoeud->motfr, motfr);
  strcpy(newnoeud->moteng, moteng);
  newnoeud->filsG=NULL;
  newnoeud->filsD=NULL;

  if (!lexique){
    lexique=newnoeud;
    printf("root inserted !\n");
    return lexique;
  }

  noeud *parcours = lexique;
  int cmp=strcmp(motfr,parcours->motfr);
  while (cmp && parcours){
    cmp=strcmp(motfr,parcours->motfr);
    printf("Cmp = %d\n", cmp);
    if (cmp<0 && parcours->filsG){
      printf("going to the left\n");
      parcours = parcours->filsG;
    }else if (cmp>0 && parcours->filsD){
      printf("going to the right\n");
      parcours = parcours->filsD;
    }else if (!parcours->filsG){
      parcours->filsG=newnoeud;
    }else if (!parcours->filsD){
      parcours->filsD=newnoeud;
    }
  }
  printf("inserted !\n");
  return lexique;
}
