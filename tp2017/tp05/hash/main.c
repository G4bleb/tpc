#include "header.h"
int main(){
  Entree *htab[HASHSIZE];
  init(htab);
  add(htab, "Paul", 8);
  parcoursTab(htab);
  return 0;
}
