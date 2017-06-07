#include "header.h"

 int hash(char *cle){ //fct à mettre en place
	int longueur = (int)strlen(cle);
	unsigned int hash = 1;
	for(int i=0 ; i < longueur ; i++){
		hash = cle[i]+31*hash;
	}
	return hash%HASHSIZE;
}
void init(Entree **htab){
	for(int i=0 ; i < HASHSIZE ; i++) {
		htab[i] = NULL;
	}
}

Entree *searchTab(Entree **htab, char *cle) {
	Entree *element;
	element = htab[hash(cle)];

	while(element) {
		if(!strcmp(cle, element->key)) {
			return element;
		}
		element = element->next;
	}
	return NULL;
}

void add(Entree **htab, char *cle, int val) {
	Entree *elt; int index;
	if((elt = searchTab(htab, cle)) == NULL) {
		elt = malloc(sizeof(Entree));
		elt->key=malloc((strlen(cle)+1)*sizeof(char));
		strcpy(elt->key, cle);
		elt->value=val;
		index = hash(cle);
		elt->next = htab[index];
		htab[index]=elt;
	}
	else {
		elt->value = val;
	}
}

void parcoursTab(Entree **htab) {
  while(htab){
    Entree *parcours=*htab;
		printf("%d\n", parcours->value);
    htab = parcours->suiv;
	}
}
