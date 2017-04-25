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

noeud* inserer(char *motfr, char *moteng, noeud* lexique){
  noeud *newnoeud = malloc(sizeof(noeud));
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
  char inserted = 0;

  while (cmp && parcours){

    //printf("Cmp = %d\n", cmp);
    if (cmp<0 && parcours->filsG){
      //printf("going to the left\n");
      parcours = parcours->filsG;
    }else if (cmp>0 && parcours->filsD){
      //printf("going to the right\n");
      parcours = parcours->filsD;
    }else if (!parcours->filsG){
      inserted = 1;
      parcours->filsG=newnoeud;
      parcours=parcours->filsG;
      //printf("inserted on the left\n");
    }else if (!parcours->filsD){
      inserted = 1;
      parcours->filsD=newnoeud;
      parcours=parcours->filsD;
      //printf("inserted on the right\n");
    }

    cmp=strcmp(motfr,parcours->motfr);
  }
  if (!inserted)printf("Valeur déjà dans le dictionnaire : %s\n", motfr);
  //printf("\n");
  //printf("inserted : %s\n", motfr);
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
void affiche(char *motfr, char *moteng){printf("motfr : %s\nmoteng : %s\n\n", motfr, moteng);}

void parcoursGRD(noeud *racine, void (*f)(char *motfr, char *moteng)){
  if(!racine) return;
  parcoursGRD(racine->filsG, f);
  f(racine->motfr, racine->moteng);
  parcoursGRD(racine->filsD, f);
}

int size(noeud* node){
  if (node==NULL)
    return 0;
  else
    return(size(node->filsG) + 1 + size(node->filsD));
}

int profondeur(noeud* racine){
   if (racine==NULL)
       return 0;
   else{
       /* compute the depth of each subtree */
       int gaucheH = profondeur(racine->filsG);
       int droiteH = profondeur(racine->filsD);

       /* use the larger one */
       if (gaucheH > droiteH)
           return(gaucheH+1);
       else return(droiteH+1);
   }
}

int largeur(noeud* lexique, int level){
  if(lexique == NULL)
    return 0;
  if(level == 1)
    return 1;
  else if (level > 1)
    return largeur(lexique->filsG, level-1) +largeur(lexique->filsD, level-1);
  else{return 2;}
}

int largeurmax(noeud* lexique){
  int maxlargeur = 0;
  int largeurs;
  int h = profondeur(lexique);
  int i;

  /* Get largeur of each level and compare
     the largeur with maximum largeur so far */
  for(i=1; i<=h; i++)
  {
    largeurs = largeur(lexique, i);
    if(largeurs > maxlargeur)
      maxlargeur = largeurs;
  }

  return maxlargeur;
}

void treeToVine(noeud *root){
  //Convertir un arbre en vigne, cad une liste chainée triée
  //Utiliser les bons pointeurs pour pointer le prochain noeud sur la liste
  noeud *temp = NULL;
  noeud *tail = root;
  noeud *rest = tail->filsD;
  while (rest!=NULL) {
    if (rest->filsG == NULL) {
      tail = rest;
      rest = rest->filsD;
    }else{
      temp = rest->filsG;
      rest->filsG = temp->filsD;
      temp->filsD = rest;
      rest = temp;
      tail->filsD = temp;
    }
  }
}

void vineToTree(noeud *root, int size){
  int leaves = (int) size + 1 - pow(2,(log2(size + 1)));
  compress(root, leaves);
  size = size - leaves;
  while (size > 1) {
    compress(root, (size/2));
    size = size/2;
  }
}

void compress(noeud *root, int count){
  noeud *child;
  noeud *scanner = root;
  for (int i = 1; i < count; i++) {
    child = scanner->filsD;
    scanner->filsD = child->filsD;
    scanner = scanner->filsD;
    child->filsD = scanner->filsG;
    scanner->filsG = child;
  }
}
