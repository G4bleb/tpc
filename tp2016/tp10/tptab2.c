/*

Programme produit le  par Gabriel LEBIS
*/
#include <stdio.h>
#define N 5

int main(){
  int i;
  int ntab = 0;
  int simi = 0;
  char tab1[N] = {'a','b','c','d','e'};
  char tab2[N] = {'b','a','c','a','e'};
  char tab3[N];
  for (i = 0; i < N; i++) {
    if (tab1[i] == tab2[i]) {
      printf("Identiques ! : %c, %c\n", tab1[i], tab2[i]);
      tab3[ntab]=tab1[i];
      ntab++;
      simi++;
    }
  }
  printf("Nb de similitudes : %d\n", simi);
  for (i = 0; i < ntab; i++) {
    printf("%c\n", tab3[i]);
  }
  return 0;
}
