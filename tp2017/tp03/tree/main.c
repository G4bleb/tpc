#include "header.h"
int main(){
  noeud* racine = NULL;
  racine =  getLexique("lexiquefar.txt");

  noeud* pseudoRacine = malloc(sizeof(noeud));
  pseudoRacine->filsD = racine;
  int tailleArbre = size(racine);
  treeToVine(pseudoRacine);
  vineToTree(pseudoRacine, tailleArbre);
  racine = pseudoRacine->filsD;
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
