#include "header.h"
int main(){
  noeud* racine = NULL;
  racine =  getLexique("lexiquefar.txt");
  //parcoursGRD(racine, &affiche);
  noeud* pseudoRacine = malloc(sizeof(noeud));
  pseudoRacine->filsD = racine;
  int tailleArbre = size(racine);

  printf("Size : %d\n", tailleArbre);
  printf("Depth : %d\n", profondeur(racine));
  printf("Width : %d\n", largeurmax(racine));

  treeToVine(pseudoRacine);
  printf("treetovine\n");
  vineToTree(pseudoRacine, tailleArbre);
  printf("vinetotree\n");
  racine = pseudoRacine->filsD;

  printf("Size : %d\n", size(racine));
  printf("Depth : %d\n", profondeur(racine));
  printf("Width : %d\n", largeurmax(racine));

  free(pseudoRacine);

  char saisie[SAISIE_MAX];
  printf("Lexique Anglais-Français :\nRentrez un mot à traduire, tapez \"fin\" pour arrêter:\n");
  while(1){
    printf("\n");
    fgets(saisie, SAISIE_MAX, stdin);
    saisie[strlen(saisie)-1] = '\0';
    if (!strcmp(saisie, "fin")) return 0;
    traduction(saisie, racine);
  }
  return -1;
}
