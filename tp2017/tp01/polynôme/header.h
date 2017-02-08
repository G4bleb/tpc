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
