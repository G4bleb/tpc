/*

Programme produit le  par Gabriel LEBIS
*/
#include <stdio.h>
#include <stdlib.h>

struct element{
  int data;
  struct element *suiv;
};
typedef struct element element;

element *ajout(element *tete, int data);
void parcours(element* tete);
void ajoutfin(element* tete, int data);
void liberation(element *tete);
