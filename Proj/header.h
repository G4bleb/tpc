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
#define WALLSIZE 16
#define FLOORSIZE 16

struct Robot {
  int xpos, ypos, steps, haut, gauche, bas, droite;
  char orient;
};

typedef struct Robot Robot;

char **fileOpen(char *chemin, int *xgrille, int *ygrille);
void displayGrid(char **grille, const int xgrille, const int ygrille);
void moveRobot(char **grille, Robot *bot, const int xgrille, const int ygrille);
char step(char **grille, Robot *bot);
Robot* startBot(char **grilleconst, const int xgrille, const int ygrille);
char check(char **grille, Robot *bot);
void botRotate(Robot *bot, char rotation);
char checkWin(char **grille, Robot *bot);

SDL_Surface *init (char * bgFilename, SDL_Surface **pFond,const int xgrille, const int ygrille);
SDL_Surface *setSurfaceCoords ( SDL_Surface * img, int x, int y );
void drawImage (SDL_Surface *img, SDL_Surface *ecran);
SDL_Surface *loadSprites ( char * sprites_filename );
void drawBackground(SDL_Surface *floorTile, SDL_Surface *ecran, const int xgrille, const int ygrille);
void drawWalls(SDL_Surface *wall, SDL_Surface *ecran, char **grille, const int xgrille, const int ygrille);
