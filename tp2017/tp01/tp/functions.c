#include "header.h"

element *ajout(element *tete, int data){
  element *new_element = malloc(sizeof(element));
  new_element->data = data;
  new_element->suiv = tete;
  tete=new_element;
  return tete;
}

void parcours(element* tete){
  element *temp = tete;
  while(temp){
    printf("Payload : %d\n", temp->data);
    temp = temp->suiv;
  }
}

void ajoutfin(element* tete, int data){
  element *new_element = malloc(sizeof(element));
  new_element->data = data;
  new_element->suiv = NULL;

  element *temp = tete;
  while(temp->suiv){
  temp = temp->suiv;
  }
  temp->suiv = new_element;
}

void liberation(element *tete){
  element *temp = tete;
  while(temp){
    tete = temp->suiv;
    free(temp);
    temp = tete;
  }
  
}
