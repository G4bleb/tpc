/*==============================================================================
Projet d'algorithmie : Un labyrinthe est donné sous forme de fichier texte,
Un 'D' symbolise le départ, un 'S' la sortie.
Sur la première ligne, sont notées les dimensions x et y du labyrinthe, sous la forme : "coordx:coordy"
Programmer un robot qui, en partant du départ, sans connaissance du labyrinthe, trouve la sortie.
Il a pour capacités : -Faire un pas en avant
                      -Se tourner à gauche et à droite
                      -Vérifier qu'il peut faire un pas devant lui
                      -Faire un pas devant lui, si il le peut
                      -Le robot a de la mémoire, et peut faire des calculs.
================Programme produit le 11/06/17 par Gabriel LEBIS===============*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#define BOT_START 1
#define WALL_SIZE 16
#define FLOOR_SIZE 16
#define BOT_WIDTH 19
#define BOT_HEIGHT 22
#define DELAY 30

typedef struct{
  int xpos, ypos, steps, oldx, oldy;
  char orient;
  char **mat;
  int xmat, ymat;
}Robot;

typedef struct{
  SDL_Surface* screen, *floorTile, *wall, *exit, *won, *botSprites, *background;
}Graph;


char **fileOpen(char *chemin, int *xgrid, int *ygrid);
void displayGrid(char **grid, const int xgrid, const int ygrid);

char moveRobot(char **grid, Robot *bot, Graph *surfaces,const int xgrid, const int ygrid, int *count);
char step(char **grid, Robot *bot);
Robot* startBot(char **gridconst, const int xgrid, const int ygrid);
char check(char **grid, Robot *bot);
void botRotate(Robot *bot, char rotation);
void resizeMatrix(Robot *bot, const int newxmat, const int newymat);
void markInMatrix(Robot *bot);
void displayMatrix(Robot *bot);
char checkWin(char **grid, Robot *bot);

Graph *initGraphics(char * bgFilename, char *wallFilename, char *botFilename, char *exitFilename,char *wonFilename, char **grid, const int xgrid, const int ygrid);
SDL_Surface *initScreen (const int xgrid, const int ygrid);
SDL_Surface *setSurfaceCoords ( SDL_Surface * img, const int x, const int y );
void drawImage (SDL_Surface *img, SDL_Surface *screen);
SDL_Surface *loadSprites ( char * sprites_filename );
void drawBackground(SDL_Surface *floorTile, SDL_Surface *screen, const int xgrid, const int ygrid);
void drawWalls(SDL_Surface *wall, SDL_Surface *screen, char **grid, const int xgrid, const int ygrid);
void drawBot(SDL_Surface *screen, Robot *bot, SDL_Surface *botSurf);
void drawExit(SDL_Surface *exit, SDL_Surface *screen, char **grid, const int xgrid, const int ygrid);
void drawWon(SDL_Surface *exit, SDL_Surface *won, SDL_Surface *screen);
void reDrawAround(Graph *surfaces, Robot *bot, char **grid);
void reDraw(Graph *surfaces, char **grid, const int x, const int y);
void drawMove(Graph *surfaces, Robot *bot, char **grid, const int xgrid, const int ygrid, const int counter, const int steps);
char graphicLoop(char **grid, Robot *bot, Graph *surfaces, const int xgrid, const int ygrid);

void playSound(char *soundFilename);
