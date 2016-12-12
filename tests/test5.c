/*

Programme produit le  par Gabriel LEBIS
*/
#include <stdio.h>
#include <stdlib.h>
#define X_GRILLE 10
#define Y_GRILLE 10

void afficher_grille(int xpos, int ypos){
  int y = 0;
  int x = 0;
  for (y; y < Y_GRILLE; y++) {
    for (x; x < X_GRILLE; x++) {
      if (xpos == x && ypos == y) {
        printf("[X]");
      }else{
        printf("[ ]");
      }
    }
    printf("\n");
  }
}
void move(int *xpos, int *ypos){
  char mov;
  scanf("%c", &mov);
  if (mov=='z') {
    *ypos-=1;
  }
  if (mov=='q') {
    *xpos-=1;
  }
  if (mov=='s') {
    *ypos+=1;
  }
  if (mov=='d') {
    *xpos+=1;
  }
}

int main(){
  int xpos = 3;
  int ypos = 3;
  for(;;){
    system("clear");
    afficher_grille(xpos, ypos);
    move(&xpos, &ypos);
  }
  return 0;
}
