#include "header.h"

int main(){
  monome *tete=NULL;
  tete = F_AjoutM(1, 2, tete);
  Ajout(3, 1, tete);
  parcours(tete);
  return 0;
}
