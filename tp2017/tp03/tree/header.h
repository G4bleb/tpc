/*

Programme produit le  par Gabriel LEBIS
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define SAISIE_MAX 20
#define LM 100

struct noeud {
  char* motfr;
  char* moteng;
  struct noeud* filsG;
  struct noeud* filsD;
};
typedef struct noeud noeud;

void traduction(char *mot, noeud* lexique);
noeud* inserer(char *motfr, char *moteng, struct noeud* lexique);
noeud* getLexique(char *filepath);
int profondeur(noeud* racine);
int largeur(noeud* lexique, int level);
int largeurmax(noeud* lexique);
void affiche(char *motfr, char *moteng);
void parcoursGRD(noeud *racine, void (*f)(char *motfr, char *moteng));
int size(noeud* node);
void treeToVine(noeud *root);
void vineToTree(noeud *root, int size);
void compress(noeud *root, int count);
