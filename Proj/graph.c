#include "header.h"

Graph *initGraphics(char * bgFilename, char *wallFilename, char *botFilename, char *exitFilename, char **grid, const int xgrid, const int ygrid){
  Graph *surfaces = malloc(sizeof(Graph));
  surfaces->fond = NULL;
  surfaces->screen = init (bgFilename, &surfaces->fond, xgrid, ygrid);
  surfaces->wall = loadSprites (wallFilename);
  surfaces->exit = SDL_LoadBMP(exitFilename);
  if (!surfaces->exit) {
    fprintf(stderr, "Impossible de charger le fichier %s : %s\n", exitFilename, SDL_GetError());
    exit(EXIT_FAILURE);
  }
  SDL_BlitSurface(surfaces->fond,NULL, surfaces->screen,NULL);
  drawWalls(surfaces->wall, surfaces->screen, grid, xgrid, ygrid);
  drawExit(surfaces->exit, surfaces->screen, grid, xgrid, ygrid);
  surfaces->botSprites = loadSprites(botFilename);
  return surfaces;
}

SDL_Surface *init (char * bgFilename, SDL_Surface **pFond, const int xgrid, const int ygrid){
  //srand(time(NULL));
  SDL_Surface *fond;
  fond = SDL_LoadBMP(bgFilename);
  if (!fond) {
    fprintf(stderr, "Impossible de charger le fichier %s : %s\n", bgFilename, SDL_GetError());
    exit(EXIT_FAILURE);
  }
  SDL_Surface *screen;

  screen = SDL_SetVideoMode(xgrid*WALL_SIZE, ygrid*WALL_SIZE, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
  if (!screen) {
    fprintf(stderr, "Erreur : %s\n",SDL_GetError());
    exit(EXIT_FAILURE);
  }

  drawBackground(fond, screen, xgrid, ygrid);
  //drawImage (fond, screen);
  SDL_Flip(screen);
  *pFond = fond;
  return screen;
}

SDL_Surface *setSurfaceCoords ( SDL_Surface * img, int x, int y ){
  img->clip_rect.x = (Sint16)x;
  img->clip_rect.y = (Sint16)y;
  return img;
}

void drawImage (SDL_Surface *img, SDL_Surface *screen){
  SDL_BlitSurface(img , NULL, screen, &img->clip_rect);
}

SDL_Surface *loadSprites ( char * sprites_filename ){
  SDL_Surface *spriteSheet = SDL_LoadBMP(sprites_filename);
  if (!spriteSheet) {
    fprintf(stderr, "Impossible de charger le fichier %s : %s\n", sprites_filename, SDL_GetError());
    exit(EXIT_FAILURE);
  }
  SDL_SetColorKey(spriteSheet, SDL_SRCCOLORKEY, 0xFFFFFF);
  return spriteSheet;
}

void drawBackground(SDL_Surface *floorTile, SDL_Surface *screen, const int xgrid, const int ygrid){
  for (int y = 0; y < ygrid; y++) {
    for (int x = 0; x < xgrid; x++) {
      floorTile = setSurfaceCoords(floorTile, x*FLOOR_SIZE, y*FLOOR_SIZE);
      drawImage(floorTile, screen);
    }
  }
  SDL_Flip(screen);
}
void drawWalls(SDL_Surface *wall, SDL_Surface *screen, char **grid, const int xgrid, const int ygrid){
  for (int y = 0; y < ygrid; y++) {
    for (int x = 0; x < xgrid; x++) {
      if (grid[x][y]=='x') {
        wall = setSurfaceCoords(wall, x*WALL_SIZE, y*WALL_SIZE);
        drawImage(wall, screen);
      }
    }
  }
  SDL_Flip(screen);
}

void drawExit(SDL_Surface *exit, SDL_Surface *screen, char **grid, const int xgrid, const int ygrid){
  char continuer = 1;
  for (int y = 0; y < ygrid && continuer; y++) {
    for (int x = 0; x < xgrid && continuer; x++) {
      if (grid[x][y]=='S') {
        exit = setSurfaceCoords(exit, x*WALL_SIZE, y*WALL_SIZE);
        drawImage(exit, screen);
        continuer=0;
      }
    }
  }
  SDL_Flip(screen);
}

void drawBot(SDL_Surface *screen, Robot *bot, SDL_Surface *botSprites){
  SDL_Rect rect_src; // Rectangle source
  SDL_Rect rect_dest; // Rectangle destination
  rect_src.x =(Sint16)((bot->orient-1)*BOT_WIDTH);
  rect_src.y =0;
  //printf("%d\n", rect_src.x);
  rect_src.w = BOT_WIDTH;
  rect_src.h = BOT_HEIGHT;
  //printf("%d\n", rect_src.w);
  rect_dest.x = (Sint16)(bot->xpos*WALL_SIZE);
  rect_dest.y = (Sint16)((bot->ypos*WALL_SIZE)-FLOOR_SIZE/2);
  SDL_BlitSurface(botSprites, &rect_src, screen, &rect_dest);
  SDL_Flip(screen);
}

void reDrawAround(Graph *surfaces, Robot *bot, char **grid){
      surfaces->fond = setSurfaceCoords(surfaces->fond, (bot->xpos)*FLOOR_SIZE, (bot->ypos)*FLOOR_SIZE);
      drawImage(surfaces->fond, surfaces->screen);
      reDraw(surfaces, grid, bot->xpos, bot->ypos-1);
      reDraw(surfaces, grid, bot->xpos, bot->ypos+1);
      reDraw(surfaces, grid, bot->xpos-1, bot->ypos);
      reDraw(surfaces, grid, bot->xpos+1, bot->ypos);
      reDraw(surfaces, grid, bot->xpos+1, bot->ypos-1);
      reDraw(surfaces, grid, bot->xpos-1, bot->ypos+1);
      reDraw(surfaces, grid, bot->xpos-1, bot->ypos-1);
      reDraw(surfaces, grid, bot->xpos+1, bot->ypos+1);
}

void reDraw(Graph *surfaces, char **grid, int x, int y){
  surfaces->fond = setSurfaceCoords(surfaces->fond, x*FLOOR_SIZE, y*FLOOR_SIZE);
  drawImage(surfaces->fond, surfaces->screen);
  if (grid[x][y]=='x') {
    surfaces->wall = setSurfaceCoords(surfaces->wall, x*WALL_SIZE, y*WALL_SIZE);
    drawImage(surfaces->wall, surfaces->screen);
  } else if(grid[x][y]=='S'){
    drawImage(surfaces->exit, surfaces->screen);
  }
}

void drawMove(const char graphMode, Graph *surfaces, Robot *bot, char **grid, const int xgrid, const int ygrid, int counter, int steps){
  if (!graphMode) {
    displayGrid(grid, xgrid, ygrid);
    printf("Counter = %d, Steps = %d\n",counter, steps);
  }else{
    //reDrawAround(surfaces, bot, grid);
    drawBot(surfaces->screen, bot, surfaces->botSprites);
    SDL_Flip(surfaces->screen);
  }
  SDL_Delay(DELAY);
}

char graphicLoop(char **grid, Robot *bot, Graph *surfaces, const int xgrid, const int ygrid, char graphMode){
  int counter = 0;
  char firstStepped = 0;
  char over = 0;
  char won=0;
  SDL_Event event;
  while (!over) {
    while ( SDL_PollEvent ( &event ) ) { // tant qu'il y a un évènement
      switch ( event.type ) {
        case SDL_QUIT :
        over = 1;
        break;
      }
    }
    if(!won) won = moveRobot(grid, bot, surfaces, xgrid, ygrid, &counter, &firstStepped, graphMode);
  }
  SDL_Quit();
  return won;
}
