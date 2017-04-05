#include "header.h"
int main(){
  noeud* racine = NULL;
  racine = inserer("age", "age", racine);
  racine = inserer("age", "age", racine);
  racine =  getLexique("lexiquefar.txt");
  /*racine = inserer("avion", "plane", racine);
  racine = inserer("age", "age", racine);
  racine = inserer("noeud", "node", racine);
  racine = inserer("fraise", "strawberry", racine);
  racine = inserer("vert", "green", racine);
  racine = inserer("robinet", "tap", racine);*/
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
