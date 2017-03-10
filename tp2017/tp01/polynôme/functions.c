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
    printf("%.1fx^%d", temp->coeff, temp->puiss);
    temp = temp->suiv;
    if(temp) printf(" + ");
  }
  printf("\n");
}

monome *ajoutM(float c, int e, monome *tete){
  monome *new_monome = malloc(sizeof(monome));
  new_monome->coeff = c;
  new_monome->puiss = e;
  new_monome->suiv = tete;
  monome* supEg = NULL;
  int res = rechSupEg(e, tete, &supEg);
  switch (res) {
    case 0: tete=new_monome; break;
    case 1:
    new_monome->suiv = supEg->suiv;
    supEg->suiv = new_monome;
    break;
    case 2: tete->coeff+=new_monome->coeff; break;
  }
  return tete;
}

int rechSupEg(int puiss, monome* tete, monome **pMSortie){
  monome *temp = tete;
  monome *supEg = NULL;
  while(temp && temp->puiss >= puiss){ //Parcours tant que la puissance cherchée (puiss) est < à la puissance liste
    supEg = temp;
    temp = temp -> suiv;
  }
  *pMSortie = supEg; //Sortie adresse monome précédent
  if(supEg == NULL) return 0;
  if(supEg->puiss == puiss) return 2;
  return 1;
}

monome *ADD(const monome* tete_A, const monome* tete_B){
  monome *tete_ADD = NULL;
  monome *tempA = tete_A;
  monome *tempB = tete_B;
  while(tempA){
    tete_ADD = ajoutM(tempA->coeff,tempA->puiss, tete_ADD);
    tempA = tempA->suiv;
  }
  while(tempB){
    tete_ADD = ajoutM(tempB->coeff, tempB->puiss, tete_ADD);
    tempB = tempB->suiv;
  }
  return tete_ADD;
}
