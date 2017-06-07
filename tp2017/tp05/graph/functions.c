#include "header.h"



ushort ** create_graph( int nb_nds){
  ushort **adj = malloc(nb_nds*sizeof(ushort *));//Matrice d’adjacence
  int i,i_deb,i_fin;
  //char saisie[LG_MAX];
  char ligne[LG_MAX];
  char nom1[LG_MAX], nom2[LG_MAX];
  //Initialisation de la matrice
  for (i=0; i<nb_nds; i++){
    adj[i] = malloc(nb_nds * sizeof(ushort));
    for(int j=0; j<nb_nds; j++){
      adj[i][j]=0;
    }
  }
  //Saisie des arêtes
  FILE* fp = openFilePointer("villes.txt");
  for (size_t i = 0; i < NB_VILLES; i++) {
    fgets(ligne, LG_MAX, fp);
    strcpy(villes[i],strtok(ligne, ","));
    printf("villes[i]\n");
  }
  fclose(fp);

  FILE* fp = openFilePointer("itineraires.txt");
  while(fgets(ligne, LG_MAX, fp)) {
    strcpy(nom1,strtok(ligne, ","));
    strcpy(nom2,strtok(NULL, ","));

    //printf("Saisir les noms des 2 noeuds de l’arête ('fin' pour arrêter la saisie)\n");
    //fgets(saisie, 50, stdin);
    //if(!strcmp(saisie,"fin\n")) break;
    i_deb = indice(villes, nom1);
    i_fin = indice(villes, nom2);
    adj[i_deb][i_fin] = 1;
    adj[i_fin][i_deb] = 1;
  }
  return adj;
}

void visit(ushort **adj, int nbNds, int i, int *mark) {
  int j;
  mark[i] = 1;
  printf("Noeud %s\n", name(villes, i));
  for(j=0 ; j < nbNds; j++) {
    if(adj[i][j] && !mark[j]) {
      visit(adj, nbNds, j, mark);
    }
  }
}


void parcoursDfs(ushort **adj, int nbNds, int i_dep) {
  int *mark = calloc(nbNds, sizeof(int)); //alloue et met à 0
  for(int i=i_dep ; i < nbNds+i_dep ; i++) {
    if(!mark[i%nbNds]) {
      visit(adj, nbNds, i, mark);
    }
  }
}
int indice(char **villes, char *nom_ville){
  int i ;
  for(i=0 ; i<NB_VILLES ; i++){
    if(!strcmp(nom_ville, villes[i])){
      return i;
    }
  }
  return -1 ;
}
char *name(char **villes, int indice){
  if(indice < 0 || indice >= NB_VILLES){
    return NULL;
  }
  return villes[indice] ;
}

FILE *openFilePointer(char *path){
  FILE *fp;
  if(!(fp = fopen(path, "r"))){
    printf("erreur d'ouverture\n");
    return -1;
  }
  return fp;
}
