/*

Programme produit le  par Gabriel LEBIS
*/
#include <stdio.h>
#define X_GRILLE 10
#define Y_GRILLE 10

void afficher_grille(char grille[][Y_GRILLE],int xpos, int ypos){
  for (int y = 0; y < Y_GRILLE; y++) {
    for (int x = 0; x < X_GRILLE; x++) {
      printf("[%c]", grille[x][y]);
      }
      printf("\n");
    }
  }
int main(){
  char grille[X_GRILLE][Y_GRILLE];
  for (int y = 0; y < Y_GRILLE; y++) {
    for (int x = 0; x < X_GRILLE; x++) {
      grille[x][y]=' ';
    }
  }
  int xpos = 4;
  int ypos = 4;
  afficher_grille(grille, xpos, ypos);
  return 0;
}
