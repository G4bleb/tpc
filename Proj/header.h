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
#define WALL_SIZE 16
#define FLOOR_SIZE 16
#define BOT_WIDTH 19
#define BOT_HEIGHT 22

typedef struct{
  int xpos, ypos, steps;
  char orient;
}Robot;

typedef struct{
  SDL_Surface* ecran, *floorTile, *wall, *botSprites, *fond;
}Graph;


char **fileOpen(char *chemin, int *xgrille, int *ygrille);
void displayGrid(char **grille, const int xgrille, const int ygrille);
void moveRobot(char **grille, Robot *bot, Graph *surfaces,const int xgrille, const int ygrille);
char step(char **grille, Robot *bot);
Robot* startBot(char **grilleconst, const int xgrille, const int ygrille);
char check(char **grille, Robot *bot);
void botRotate(Robot *bot, char rotation);
char checkWin(char **grille, Robot *bot);

Graph *initSDL(char * bgFilename, char *wallFilename, char *botFilename, char **grille, const int xgrille, const int ygrille);
SDL_Surface *init (char * bgFilename, SDL_Surface **pFond,const int xgrille, const int ygrille);
SDL_Surface *setSurfaceCoords ( SDL_Surface * img, int x, int y );
void drawImage (SDL_Surface *img, SDL_Surface *ecran);
SDL_Surface *loadSprites ( char * sprites_filename );
void drawBackground(SDL_Surface *floorTile, SDL_Surface *ecran, const int xgrille, const int ygrille);
void drawWalls(SDL_Surface *wall, SDL_Surface *ecran, char **grille, const int xgrille, const int ygrille);
void drawBot(SDL_Surface *ecran, Robot *bot, SDL_Surface *botSurf);
void drawWindow(Graph *surfaces, Robot *bot, char **grille, const int xgrille, const int ygrille);
