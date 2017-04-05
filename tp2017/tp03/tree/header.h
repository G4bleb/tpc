/*

Programme produit le  par Gabriel LEBIS
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
struct noeud* inserer(char *motfr, char *moteng, struct noeud* lexique);
noeud* getLexique(char *filepath);
