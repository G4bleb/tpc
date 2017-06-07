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

  SDL_Surface *floor = NULL;
  SDL_Surface *ecran = init ("floor.bmp", &floor);
  //SDL_Surface *mur = LoadImage ( "tree.bmp",	80, 80);
  SDL_Surface *sprites = LoadSprites ( "tree.bmp" );
  SDL_BlitSurface(floor,NULL, ecran,NULL);
  //DrawImage ( mur, ecran );
  DrawImage ( sprites, ecran );

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
}
SDL_Quit();
displayGrid(grille, xgrille, ygrille);
moveRobot(grille, bot, xgrille, ygrille);

printf("Over !\n");
return 0;
}
