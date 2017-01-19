/*

Programme produit le  par Gabriel LEBIS
*/
#include <stdio.h>
#include <string.h>

void swap(int *tab){
  tab[0] = tab[0] + tab[1];
  tab[1] = tab[0] - tab[1];
  tab[0] = tab[0] - tab[1];
}

int main(){
  int tab[2]={5,10};
  printf("a=%d\nb=%d\n", tab[0],tab[1]);
  swap(tab);
  printf("a=%d\nb=%d\n", tab[0],tab[1]);
  return 0;
}
