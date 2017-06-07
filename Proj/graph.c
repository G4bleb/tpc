#include "header.h"


SDL_Surface *init (char * bgFilename, SDL_Surface **pFond){
  //srand(time(NULL));
  SDL_Surface *fond;
  fond = SDL_LoadBMP(bgFilename);
  if (!fond) {
    fprintf(stderr, "Impossible de charger le fichier %s : %s\n", bgFilename, SDL_GetError());
    exit(EXIT_FAILURE);
  }
  SDL_Surface *ecran;
  ecran = SDL_SetVideoMode(fond->w, fond->h, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
  if (!ecran) {
    fprintf(stderr, "Erreur : %s\n",SDL_GetError());
    exit(EXIT_FAILURE);
  }
  SDL_BlitSurface(fond, NULL, ecran, NULL);
  *pFond = fond;
  return ecran;
}

SDL_Surface *LoadImage ( char * img_filename, int x, int y ){
  SDL_Surface *img = SDL_LoadBMP(img_filename);
  img->clip_rect.x = (Sint16)x;
  img->clip_rect.y = (Sint16)y;
  return img;
}

void DrawImage (SDL_Surface *img, SDL_Surface *ecran){
  SDL_BlitSurface(img , NULL, ecran, &img->clip_rect);
}

SDL_Surface *LoadSprites ( char * sprites_filename ){
  SDL_Surface *spriteSheet = SDL_LoadBMP(sprites_filename);
  SDL_SetColorKey(spriteSheet, SDL_SRCCOLORKEY, 0xFFFFFF);
  return spriteSheet;
}
