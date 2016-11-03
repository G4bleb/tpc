/*

Programme produit le  par Gabriel LEBIS
*/
#include <stdio.h>

int main(){
  int i;
  int tab[10]={1,2,3,4,5,6,7,8,9,10};
  int *ptr = tab;
  for (ptr=tab; ptr < tab+10; ptr++) {
    printf("%d\n", *ptr);
  }
  for (i=0, ptr=tab;i < 10;i++, ptr++) {
    printf("%d\n", *ptr);
  }
}
