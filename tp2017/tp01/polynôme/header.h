/*

Programme produit le  par Gabriel LEBIS
*/
#include <stdio.h>
#include <stdlib.h>

struct monome{
  float coeff;
  int puiss;
  struct monome* suiv;
};
typedef struct monome monome;

monome* F_AjoutM(float c, int e, monome* p);
void P_AjoutM(float c, int e, monome* p);
void parcours(monome* tete);
monome *ajoutM(float c, int e, monome *tete);
int rechSupEg(int puiss, monome* tete, monome **pMSortie);
monome *ADD(const monome* tete_A, const monome* tete_B);
