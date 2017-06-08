#include "header.h"

Graph *initSDL(char * bgFilename, char *wallFilename, char *botFilename, char **grille, const int xgrille, const int ygrille){
  Graph *surfaces = malloc(sizeof(Graph));
  surfaces->fond = NULL;
  surfaces->ecran = init (bgFilename, &surfaces->fond, xgrille, ygrille);
  surfaces->wall = loadSprites (wallFilename);
  SDL_BlitSurface(surfaces->fond,NULL, surfaces->ecran,NULL);
  drawWalls(surfaces->wall, surfaces->ecran, grille, xgrille, ygrille);
  surfaces->botSprites = loadSprites("bot.bmp");
  return surfaces;
}

SDL_Surface *init (char * bgFilename, SDL_Surface **pFond, const int xgrille, const int ygrille){
  //srand(time(NULL));
  SDL_Surface *fond;
  fond = SDL_LoadBMP(bgFilename);
  if (!fond) {
    fprintf(stderr, "Impossible de charger le fichier %s : %s\n", bgFilename, SDL_GetError());
    exit(EXIT_FAILURE);
  }
  SDL_Surface *ecran;

  ecran = SDL_SetVideoMode(xgrille*WALL_SIZE, ygrille*WALL_SIZE, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
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
      floorTile = setSurfaceCoords(floorTile, x*FLOOR_SIZE, y*FLOOR_SIZE);
      drawImage(floorTile, ecran);
    }
  }
  SDL_Flip(ecran);
}
void drawWalls(SDL_Surface *wall, SDL_Surface *ecran, char **grille, const int xgrille, const int ygrille){
  for (int y = 0; y < ygrille; y++) {
    for (int x = 0; x < xgrille; x++) {
      if (grille[x][y]=='x') {
        wall = setSurfaceCoords(wall, x*WALL_SIZE, y*WALL_SIZE);
        drawImage(wall, ecran);
      }
    }
  }
  SDL_Flip(ecran);
}

void drawBot(SDL_Surface *ecran, Robot *bot, SDL_Surface *botSprites){
  SDL_Rect rect_src; // Rectangle source
  SDL_Rect rect_dest; // Rectangle destination
  rect_src.x =(Sint16)((bot->orient-1)*BOT_WIDTH);
  rect_src.y =0;
  //printf("%d\n", rect_src.x);
  rect_src.w = BOT_WIDTH;
  rect_src.h = BOT_HEIGHT;
  //printf("%d\n", rect_src.w);
  rect_dest.x = (Sint16)(bot->xpos*BOT_WIDTH);
  rect_dest.y = (Sint16)(bot->ypos*BOT_HEIGHT);
  SDL_BlitSurface(botSprites, &rect_src, ecran, &rect_dest);
  SDL_Flip(ecran);
}

void drawWindow(Graph *surfaces, Robot *bot, char **grille, const int xgrille, const int ygrille){
  drawBackground(surfaces->fond, surfaces->ecran, xgrille, ygrille);
  drawWalls(surfaces->wall, surfaces->ecran, grille,xgrille,ygrille);
  drawBot(surfaces->ecran, bot, surfaces->botSprites);
}
