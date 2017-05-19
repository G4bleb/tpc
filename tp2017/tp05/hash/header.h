/*

Programme produit le  par Gabriel LEBIS
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define HASHSIZE //nb de valeurs max +25%, nombre premier supérieur le + proche
typedef struct Entree {
		char *key;
		int value;
		struct Entree *next;
	} Entree;

void add(htab, cle, valeur);
int exists(htab, cle);
Entree *search(htab, cle);
void delete(htab, cle);
