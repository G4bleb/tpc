#include "header.h"

void traduction(char *mot, noeud* lexique){
  noeud *parcours = lexique;
  int cmp=strcmp(mot,parcours->motfr);
  while (cmp && parcours){
    cmp=strcmp(mot,parcours->motfr);
    //printf("Cmp = %d\n", cmp);
    if (cmp<0){
      parcours = parcours->filsG;
    }else if (cmp>0){
      parcours = parcours->filsD;
    }
  }
  if(!cmp){
    printf("FR : %s EN : %s\n", mot, parcours->moteng);
  }else{
    printf("Mot non trouvé\n");
  }
}

struct noeud* inserer(char *motfr, char *moteng, struct noeud* lexique){
  struct noeud *newnoeud = malloc(sizeof(noeud));
  newnoeud->motfr=malloc(strlen(motfr)+1);
  newnoeud->moteng=malloc(strlen(moteng)+1);
  strcpy(newnoeud->motfr, motfr);
  strcpy(newnoeud->moteng, moteng);
  newnoeud->filsG=NULL;
  newnoeud->filsD=NULL;

  if (!lexique){
    lexique=newnoeud;
    return lexique;
  }

  noeud *parcours = lexique;
  int cmp=strcmp(motfr,parcours->motfr);
  while (cmp && parcours){
    //printf("Cmp = %d\n", cmp);
    if (cmp<0 && parcours->filsG){
      //printf("going to the left\n");
      parcours = parcours->filsG;
    }else if (cmp>0 && parcours->filsD){
      //printf("going to the right\n");
      parcours = parcours->filsD;
    }else if (!parcours->filsG){
      parcours->filsG=newnoeud;
    }else if (!parcours->filsD){
      parcours->filsD=newnoeud;
    }
    cmp=strcmp(motfr,parcours->motfr);
  }
  if (!cmp)printf("Valeur déjà dans le dictionnaire\n");
  //printf("\n");

  return lexique;
}

noeud* getLexique(char *filepath){
  noeud* racine = NULL;
  FILE *fp = NULL;
  if (!(fp = fopen(filepath,"r"))){ //On ouvre le fichier pour lecture et on vérifie pour une erreur
    printf("Erreur fichier\n");
  }

  char ligne[LM];
  char *motfr = NULL;
  char *moteng = NULL;
  while (fgets(ligne, LM, fp)) { //Lecture de tout le fichier
    motfr = strtok(ligne, ":");
    //printf("%s\n", motfr);
    moteng = strtok(NULL, ":");
    moteng[strlen(moteng)-1] = '\0';
    //printf("%s\n\n", moteng);
    racine = inserer(motfr, moteng, racine);
  }
  fclose(fp);
  return racine;
}
