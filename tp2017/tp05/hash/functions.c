#include "header.h"

int hash(char *cle){ //fct à mettre en place
	longueur = strlen(cle);
	for(i=0 ; i < longueur ; i++){
		hash = cle[i]+31*hash;
	}
	hash=hash%HASHIZE;
}
void init(Entree **htab){
	for(i=0 ; i < HASHSIZE ; i++) {
		htab[i] = NULL;
	}
}

Entree *search(Entree **htab, char *cle) {
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
	if((elt = search(hab, cle)) == NULL) {
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
