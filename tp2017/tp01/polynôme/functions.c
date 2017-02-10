#include "header.h"

monome* F_AjoutM(float c, int e, monome* p){
  monome *new_monome = malloc(sizeof(monome));
  new_monome->coeff = c;
  new_monome->puiss = e;
  new_monome->suiv = p;
  p=new_monome;
  return p;
}

void P_AjoutM(float c, int e, monome** p){
  monome *new_monome = malloc(sizeof(monome));
  new_monome->coeff = c;
  new_monome->puiss = e;
  new_monome->suiv = *p;
  *p=new_monome;
}

void parcours(monome* tete){
  monome *temp = tete;
  while(temp){
    printf("%.1fx^%d\n", temp->coeff, temp->puiss);
    temp = temp->suiv;
  }
}

/*monome **tgteq(monome *tete, int puiss){
  monome *temp = malloc(sizeof(monome**));
  temp = tete;
  while(temp){
    if (temp->puiss >= puiss){
      return &temp;
    }
    temp = temp->suiv;
  }
  return &temp;
}*/

void Ajout(float c, int e, monome *tete){
  monome* newTete = NULL;
  rechSupEg(e, tete, &newTete);
  P_AjoutM(c, e, &newTete);
}

int rechSupEg(int puiss, monome* tete, monome **pMSortie){
  monome *temp = tete;
  monome *supEg = NULL;
  while(temp && temp->puiss >= puiss){ //Parcours tant que la puissance cherchée (puiss) est < à la puissance liste
    supEg = temp;
    temp = temp -> suiv;
  }
  pMSortie = &supEg; //Sortie adresse monome précédent
  if(supEg == NULL) return 0;
  if(supEg->puiss == puiss) return 2;
  return 1;
}
