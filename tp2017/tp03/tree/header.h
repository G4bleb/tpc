/*

Programme produit le  par Gabriel LEBIS
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct noeud {
  char* motfr;
  char* moteng;
  struct noeud* filsG;
  struct noeud* filsD;
};
typedef struct noeud noeud;

void traduction(char *mot, noeud* lexique);
