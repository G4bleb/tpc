/*

Programme produit le  par Gabriel LEBIS
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#define TAILLE_TAB 1000000

void tri_insertion(int *tab, int n){
  int longueur, i, memoire, compteur;
  char marqueur;
  for (i = 1; i < n; i++) {
    memoire = tab[i];
    compteur = i-1;
    marqueur = 1;
    while (marqueur) {
      marqueur = 0;
      if (tab[compteur]>memoire) {
        tab[compteur+1] = tab[compteur];
        compteur--;
        marqueur = 1;
      }
      if (compteur < 0) {
        marqueur = 0;
      }
    }
    tab[compteur+1]=memoire;
  }
}

void lire_tab(int *tab, int n){
  for (int i = 0; i < n; i++) {
    printf("Valeur n°%d = %d\n", i, tab[i]);
  }
}

int comp_int (const void*p1, const void*p2){
  return *(int *)p1 - *(int*)p2;
}

int main(){
  /*int tab[9]={8, 4, 6, 7, 5, 48, 26, 14, 36};
  int n=9;
  lire_tab(tab, n);
  tri_insertion(tab, n);
  lire_tab(tab, n);*/
  int tab[TAILLE_TAB];
  long int i, debut, fin;
  struct timeval temps;
  srand(time(NULL));
  for (i = 0; i < TAILLE_TAB; i++) {
    tab[i] = rand();
  }
  gettimeofday(&temps, NULL);
  debut = temps.tv_sec * 1000000 + temps.tv_usec;
  //tri_insertion(tab, TAILLE_TAB);
  qsort(tab, TAILLE_TAB, sizeof(int), &comp_int);
  gettimeofday(&temps, NULL);
  fin = temps.tv_sec * 1000000 + temps.tv_usec;
  printf("Tri par insertion : %f secondes\n", (fin-debut)/(double)1000000);
  printf("1ère valeur : %d\n", tab[0]);
  printf("%dème valeur : %d\n", TAILLE_TAB, tab[TAILLE_TAB-1]);
  return 0;
}
