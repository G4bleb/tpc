/*
Swap de deux valeurs
Programme produit le 18/11/16 par Gabriel LEBIS
*/
#include <stdio.h>

void swap(int *a, int *b){
  *a = *a + *b;
  *b = *a - *b;
  *a = *a - *b;
}

int main(){
  int a=5;
  int b=10;
  printf("a=%d\nb=%d\n", a,b);
  swap(&a, &b);
  printf("a=%d\nb=%d\n", a,b);
  return 0;
}
