/*

Programme démarré le 07/06/17  par Gabriel LEBIS
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <time.h>
#define X_grid 10
#define Y_grid 10
#define LMAX 100
#define BOT_START 1
#define WALL_SIZE 16
#define FLOOR_SIZE 16
#define BOT_WIDTH 19
#define BOT_HEIGHT 22
#define DELAY 30
#define RANDOM_START 500
#define MAX_RAND 2

typedef struct{
  int xpos, ypos, steps, oldx, oldy;
  char orient;
}Robot;

typedef struct{
  char enabled;
  SDL_Surface* screen, *floorTile, *wall, *exit, *won, *botSprites, *fond;
}Graph;


char **fileOpen(char *chemin, int *xgrid, int *ygrid);
void displayGrid(char **grid, const int xgrid, const int ygrid);

char moveRobot(char **grid, Robot *bot, Graph *surfaces,const int xgrid, const int ygrid, int *count, char *firstStepped);
char step(char **grid, Robot *bot);
Robot* startBot(char **gridconst, const int xgrid, const int ygrid);
char check(char **grid, Robot *bot);
void botRotate(Robot *bot, char rotation);
char checkWin(char **grid, Robot *bot);

Graph *initGraphics(char * bgFilename, char *wallFilename, char *botFilename, char *exitFilename,char *wonFilename, char **grid, const int xgrid, const int ygrid);
SDL_Surface *init (char * bgFilename, SDL_Surface **pFond,const int xgrid, const int ygrid);
SDL_Surface *setSurfaceCoords ( SDL_Surface * img, int x, int y );
void drawImage (SDL_Surface *img, SDL_Surface *screen);
SDL_Surface *loadSprites ( char * sprites_filename );
void drawBackground(SDL_Surface *floorTile, SDL_Surface *screen, const int xgrid, const int ygrid);
void drawWalls(SDL_Surface *wall, SDL_Surface *screen, char **grid, const int xgrid, const int ygrid);
void drawBot(SDL_Surface *screen, Robot *bot, SDL_Surface *botSurf);
void drawExit(SDL_Surface *exit, SDL_Surface *screen, char **grid, const int xgrid, const int ygrid);
void drawWon(SDL_Surface *exit, SDL_Surface *won, SDL_Surface *screen);
void reDrawAround(Graph *surfaces, Robot *bot, char **grid);
void reDraw(Graph *surfaces, char **grid, const int x, const int y);
void drawMove(Graph *surfaces, Robot *bot, char **grid, const int xgrid, const int ygrid, int counter, int steps);
char graphicLoop(char **grid, Robot *bot, Graph *surfaces, const int xgrid, const int ygrid);
