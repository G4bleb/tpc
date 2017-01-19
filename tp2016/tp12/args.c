/*
Programme qui demande : une chaine quelconque, et un entier positif
Programme produit le  par Gabriel LEBIS
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  if (argc!=3) {
    printf("Utilisation : ./args chaine entier_positif\n");
    return -1;
  }
  if (atoi(argv[2])<=0){
    printf("L'argument 2 doit être un entier positif\n");
    return -1;
  }
  for (int i = 0; i < atoi(argv[2]); i++) {
    printf("%s\n", argv[1]);
  }
  return 0;
}
