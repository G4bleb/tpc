/*

Programme produit le  par Gabriel LEBIS
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define HASHSIZE 20//nb de valeurs max +25%, nombre premier supérieur le + proche
typedef struct Entree {
		char *key;
		int value;
		struct Entree *next;
	} Entree;

void parcoursTab(Entree **htab);
void init(Entree **htab);
void add(Entree **htab, char *cle, int valeur);
int exists(Entree **htab, char *cle);
Entree *searchTab(Entree **htab, char *cle);
void deleteTab(Entree **htab, char *cle);
int hash(char *cle);
