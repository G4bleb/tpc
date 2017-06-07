#include "header.h"

void initGrid(char grille[X_GRILLE][Y_GRILLE]){
  for (int y = 0; y < Y_GRILLE; y++) {
    for (int x = 0; x < X_GRILLE; x++) {
      grille[x][y]=' ';
    }
  }
}

void displayGrid(char grille[X_GRILLE][Y_GRILLE]){
  for (int y = 0; y < Y_GRILLE; y++) {
    for (int x = 0; x < X_GRILLE; x++) {
      printf("[%c]", grille[x][y]);
    }
    printf("\n");
  }
}
void movePlayer(char grille[X_GRILLE][Y_GRILLE], int *xpos, int *ypos){
  char mov;
  scanf("%c", &mov);
  step(grille, xpos, ypos, mov);
  //if (*xpos>X_GRILLE) {grille[X_GRILLE][*ypos]='X';*xpos=X_GRILLE;}
  //if (*ypos>Y_GRILLE) {grille[*xpos][Y_GRILLE]='X';*ypos=Y_GRILLE;}
  if (*xpos<0) {grille[0][*ypos]='X';*xpos=0;}
  if (*ypos<0) {grille[*xpos][0]='X';*ypos=0;}
}

void moveRobot(char grille[X_GRILLE][Y_GRILLE], int *xpos, int *ypos){

}

void step(char grille[X_GRILLE][Y_GRILLE], int *xpos, int *ypos, char mov){
  if (mov=='z') {
    grille[*xpos][*ypos]=' ';
    *ypos-=1;
    grille[*xpos][*ypos]='X';
  }
  if (mov=='q') {
    grille[*xpos][*ypos]=' ';
    *xpos-=1;
    grille[*xpos][*ypos]='X';
  }
  if (mov=='s') {
    grille[*xpos][*ypos]=' ';
    *ypos+=1;
    grille[*xpos][*ypos]='X';
  }
  if (mov=='d') {
    grille[*xpos][*ypos]=' ';
    *xpos+=1;
    grille[*xpos][*ypos]='X';
  }
}
