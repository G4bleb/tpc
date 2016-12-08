/*
Programme qui demande : Plusieurs chiffres en arguments
Programme produit le  par Gabriel LEBIS
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  int sum = 0;
  float moy;
  for (int i = 0; i < argc; i++) {
    sum += atoi(argv[i]);
  }
  moy = (float)sum/(argc-1);
  printf("Somme : %d\nMoyenne :%.1f\n", sum, moy);
  return 0;
}
