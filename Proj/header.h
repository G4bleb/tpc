/*

Programme démarré le 07/06/17  par Gabriel LEBIS
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
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

SDL_Surface *init (char * bgFilename, SDL_Surface **pFond);
SDL_Surface *LoadImage ( char * img_filename, int x, int y );
void DrawImage (SDL_Surface *img, SDL_Surface *ecran);
