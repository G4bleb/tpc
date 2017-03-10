#include "header.h"

int main(){
  monome *tete_A=NULL;
  tete_A = F_AjoutM(1, 2, tete_A);
  tete_A = F_AjoutM(4, 5, tete_A);
  tete_A = ajoutM(3, 4, tete_A);
  printf("Polynôme A :\n");
  parcours(tete_A);
  monome *tete_B=NULL;
  tete_B = F_AjoutM(2, 3, tete_B);
  tete_B = F_AjoutM(4, 5, tete_B);
  tete_B = ajoutM(3, 4, tete_B);
  printf("Polynôme B :\n");
  parcours(tete_B);
  monome *tete_ADD=ADD(tete_A, tete_B);
  printf("Somme :\n");
  parcours(tete_ADD);
  return 0;
}
