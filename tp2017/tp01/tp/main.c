#include "header.h"

int main(){
  element *tete = NULL;
  tete = ajout(tete, 12);
  tete = ajout(tete, 45);
  ajoutfin(tete, 999);
  parcours(tete);
  liberation(tete);
  return 0;
}
