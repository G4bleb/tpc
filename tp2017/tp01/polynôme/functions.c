#include "header.h"

monome* F_AjoutM(float c, int e, monome* p){
  monome *new_monome = malloc(sizeof(monome));
  new_monome->coeff = c;
  new_monome->puiss = e;
  new_monome->suiv = p;
  p=new_monome;
  return p;
}

void P_AjoutM(float c, int e, monome* p){
  monome *new_monome = malloc(sizeof(monome));
  new_monome->coeff = c;
  new_monome->puiss = e;
  new_monome->suiv = p;
  p=new_monome;
}

void parcours(monome* tete){
  monome *temp = tete;
  while(temp){
    printf("%.1fx^%d\n", temp->coeff, temp->puiss);
    temp = temp->suiv;
  }
}
