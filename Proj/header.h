/*

Programme produit le  par Gabriel LEBIS
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define X_GRILLE 10
#define Y_GRILLE 10
#define LMAX 100
#define BOT_START 1
#define UP 1
#define LEFT 2
#define DOWN 3
#define RIGHT 4

struct Robot {
  int xpos;
  int ypos;
  char orient;
};

typedef struct Robot Robot;

char **fileOpen(char *chemin, int *xgrille, int *ygrille);
void displayGrid(char **grille, const int xgrille, const int ygrille);
void movePlayer(char **grille, Robot *bot);
void moveRobot(char **grille, Robot *bot, const int xgrille, const int ygrille);
char step(char **grille, Robot *bot, char mov);
Robot* startBot(char **grilleconst, const int xgrille, const int ygrille);
char check(char **grille, Robot *bot, char mov);
void botRotate(Robot *bot, char rotation);
char checkWin(char **grille, Robot *bot);
