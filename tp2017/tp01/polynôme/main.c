#include "header.h"

int main(){
  monome *tete=NULL;
  tete = F_AjoutM(1, 2, tete);
  P_AjoutM(3,2, tete);
  parcours(tete);
  return 0;
}
