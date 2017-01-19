/*
Programme qui demande : Plusieurs chiffres en arguments, en fait la somme, puis la moyenne
Programme produit le  par Gabriel LEBIS
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  if (!(argc > 1)){
    printf("Usage : ./args2 int int int ...\n");
    return -1;
  }
  int sum = 0;
  float moy;
  for (int i = 0; i < argc; i++) {
    sum += atoi(argv[i]);
  }
  moy = (float)sum/(argc-1);
  printf("Somme : %d\nMoyenne :%.1f\n", sum, moy);
  return 0;
}
