#include "header.h"

int main(int argc, char *argv[]){
  if(argc!=2){
    printf("utilisation : ./main.exe chemin\n");
    return -1;
  }
  int xgrille, ygrille;
  char **grille;
  if(!(grille = fileOpen(argv[1], &xgrille, &ygrille))){
    printf("Erreur de traitement du fichier\n");
    return -1;
  }
  printf("Creating bot\n");
  Robot *bot = startBot(grille, xgrille, ygrille);
  printf("bot->xpos = %d, bot->ypos = %d\n", bot->xpos, bot->ypos);

  Graph *surfaces = initSDL("floorTile.bmp","wall.bmp", "bot.bmp", grille, xgrille, ygrille);

  drawBot(surfaces->ecran, bot, surfaces->botSprites);
  moveRobot(grille, bot, surfaces, xgrille, ygrille);
/*
  int continuer = 1;
  SDL_Event event;
  while (continuer) {
    while ( SDL_PollEvent ( &event ) ) { // tant qu'il y a un évènement
    switch ( event.type ) {
      case SDL_QUIT :
      continuer = 0;
      break;
    }
    SDL_Flip(ecran);
  }
}*/
SDL_Quit();
//displayGrid(grille, xgrille, ygrille);
//moveRobot(grille, bot, xgrille, ygrille);
//moveRobot(grille, bot, ecran, botSprites);

printf("Over ! : Steps = %d\n", bot->steps);
free(grille);
return 0;
}
