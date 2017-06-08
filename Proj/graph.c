#include "header.h"


SDL_Surface *init (char * bgFilename, SDL_Surface **pFond, const int xgrille, const int ygrille){
  //srand(time(NULL));
  SDL_Surface *fond;
  fond = SDL_LoadBMP(bgFilename);
  if (!fond) {
    fprintf(stderr, "Impossible de charger le fichier %s : %s\n", bgFilename, SDL_GetError());
    exit(EXIT_FAILURE);
  }
  SDL_Surface *ecran;

  ecran = SDL_SetVideoMode(xgrille*WALLSIZE, ygrille*WALLSIZE, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
  if (!ecran) {
    fprintf(stderr, "Erreur : %s\n",SDL_GetError());
    exit(EXIT_FAILURE);
  }

  drawBackground(fond, ecran, xgrille, ygrille);
  //drawImage (fond, ecran);
  SDL_Flip(ecran);
  *pFond = fond;
  return ecran;
}

SDL_Surface *setSurfaceCoords ( SDL_Surface * img, int x, int y ){
  img->clip_rect.x = (Sint16)x;
  img->clip_rect.y = (Sint16)y;
  return img;
}

void drawImage (SDL_Surface *img, SDL_Surface *ecran){
  SDL_BlitSurface(img , NULL, ecran, &img->clip_rect);
}

SDL_Surface *loadSprites ( char * sprites_filename ){
  SDL_Surface *spriteSheet = SDL_LoadBMP(sprites_filename);
  SDL_SetColorKey(spriteSheet, SDL_SRCCOLORKEY, 0xFFFFFF);
  return spriteSheet;
}
void drawBackground(SDL_Surface *floorTile, SDL_Surface *ecran, const int xgrille, const int ygrille){
  for (int y = 0; y < ygrille; y++) {
    for (int x = 0; x < xgrille; x++) {
      floorTile = setSurfaceCoords(floorTile, x*FLOORSIZE, y*FLOORSIZE);
      drawImage(floorTile, ecran);
    }
  }
  SDL_Flip(ecran);
}
void drawWalls(SDL_Surface *wall, SDL_Surface *ecran, char **grille, const int xgrille, const int ygrille){
  for (int y = 0; y < ygrille; y++) {
    for (int x = 0; x < xgrille; x++) {
      if (grille[x][y]=='x') {
        wall = setSurfaceCoords(wall, x*WALLSIZE, y*WALLSIZE);
        drawImage(wall, ecran);
      }
    }
  }
  SDL_Flip(ecran);
}

//void drawBot(SDL_Surface *)
