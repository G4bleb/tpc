/*

Programme produit le  par Gabriel LEBIS
*/
#include <stdio.h>
#include <stdlib.h>
#define X_GRILLE 10
#define Y_GRILLE 10

void initGrid(char grille[X_GRILLE][Y_GRILLE]);
void displayGrid(char grille[X_GRILLE][Y_GRILLE]);
void movePlayer(char grille[X_GRILLE][Y_GRILLE], int *xpos, int *ypos);
void moveRobot(char grille[X_GRILLE][Y_GRILLE], int *xpos, int *ypos);
void step(char grille[X_GRILLE][Y_GRILLE], int *xpos, int *ypos, char mov);
