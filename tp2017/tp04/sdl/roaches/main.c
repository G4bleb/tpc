#include "header.h"
int main(){
  SDL_Surface *floor = NULL;
  SDL_Surface *ecran = init ("floor.bmp", &floor);
  SDL_Surface *tapis = LoadImage ( "bathmat.bmp",	X_INIT_TAPIS, Y_INIT_TAPIS );
  SDL_Surface *sprites = LoadSprites ( "roach.bmp" );

  //Roach roach = CreateRoach (ecran, sprites);
  Roach *roaches = CreateRoaches ( ecran, sprites, MAX_ROACHES );

  //DrawRoach(roach, ecran);

  //SDL_Flip(ecran);
  int nVis;
  int continuer = 1;
  SDL_Event event;
  while (continuer) {
    while ( SDL_PollEvent ( &event ) ) { // tant qu'il y a un évènement
    switch ( event.type ) {
      case SDL_QUIT :
      continuer = 0;
      break;
    }
  }
  /*CleanRoach(roach, ecran, floor);
  MoveRoach( &roach, ROACH_SPEED, ecran);
  DrawRoach(roach, ecran);
  SDL_Flip(ecran);
  SDL_Delay(DELAI_P_TOUR);*/

  //CleanRoaches ( roaches, MAX_ROACHES, ecran, floor );// option 2
  nVis = MarkHiddenRoaches(roaches, MAX_ROACHES, tapis);
  if (nVis) {
    CleanRoach(roaches[0], ecran, floor);
  	MoveRoaches( roaches, MAX_ROACHES, ROACH_SPEED, ecran);
  	DrawRoaches ( roaches, MAX_ROACHES, ecran );
  }
  DrawImage ( tapis, ecran );
  SDL_Flip(ecran);
	SDL_Delay(DELAI_P_TOUR);
}

SDL_Quit();
return EXIT_SUCCESS;
}
