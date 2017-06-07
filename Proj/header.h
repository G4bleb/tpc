/*

Programme produit le  par Gabriel LEBIS
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define X_GRILLE 10
#define Y_GRILLE 10
#define LMAX 100

struct Robot {
  int xpos;
  int ypos;
  char orient;
};

typedef struct Robot Robot;

char **fileOpen(char *chemin, int *xgrille, int *ygrille);
void displayGrid(char **grille, const int xgrille, const int ygrille);
void movePlayer(char **grille, Robot *bot);
void moveRobot(char **grille, Robot *bot);
void step(char **grille, Robot *bot, char mov);
