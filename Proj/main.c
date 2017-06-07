#include "header.h"

int main(int argc, char *argv[]){
  int xpos = 3;
  int ypos = 3;
  char grille[X_GRILLE][Y_GRILLE];
  initGrid(grille);
  grille[xpos][ypos]='X';
  for(;;){
    system("clear");
    displayGrid(grille);
    movePlayer(grille, &xpos, &ypos);
  }
  return 0;
}
