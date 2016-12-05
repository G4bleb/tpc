/*

Programme produit le  par Gabriel LEBIS
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAILLE_TAB 100

int main(){
	int i = 0;
  int tab[TAILLE_TAB];
	srand(time(NULL)); // initialisation de rand
	for(i=0; i<TAILLE_TAB; i++){
		tab[i] = rand();
	}
  int j=0;
  int y;
  char ok;
  for(ok=0;ok=1;ok=0){
    for (i = 1, j=0; i < TAILLE_TAB; i++,j++){
      if (tab[i]>tab[j]) {
        y=tab[i];
        tab[i]=tab[j];
        tab[j]=y;
        ok = 1;
      }
    }
  }
  printf("%d\t, indice = %d\n",tab[j], j);
	return 0;
}
