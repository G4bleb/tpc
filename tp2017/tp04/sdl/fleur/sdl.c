/*

Programme produit le  par Gabriel LEBIS
*/
#include <stdio.h>
#include <SDL/SDL.h>
#include <time.h>

int main(){
  if (SDL_Init(SDL_INIT_VIDEO)==-1) {
    fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }

  SDL_Surface *ecran = NULL;
  ecran = SDL_SetVideoMode(800, 600 , 32, SDL_HWSURFACE | SDL_RESIZABLE | SDL_DOUBLEBUF);
  SDL_WM_SetCaption("Une fenêtre", NULL);
  //SDL_FillRect (ecran, NULL, SDL_MapRGB(ecran->format, 50, 110, 0));
  SDL_Surface *background = SDL_LoadBMP("large-artificial-grass-lawn.bmp");
  SDL_BlitSurface(background, NULL, ecran, NULL);
  SDL_Surface *fleur;
  fleur = SDL_LoadBMP("fleur1a.bmp");
  if (!fleur) {
    fprintf(stderr, "Impossible de charger le fichier BMP : %s\n", SDL_GetError());
  }

  //SDL_SetColorKey(fleur, SDL_SRCCOLORKEY, 0x000000);
  //SDL_SetAlpha(fleur, SDL_SRCALPHA, 0);
  //fleur->format->Amask = 0xFF000000;
  //fleur->format->Ashift = 24;
  //SDL_BlitSurface(fleur, NULL, ecran, NULL);
  SDL_Rect rect_fleur;
  //rect_fleur.x = 100;
  //rect_fleur.y = 50;
  //SDL_BlitSurface(fleur, NULL, ecran, &rect_fleur);
  SDL_Flip(ecran);

  char currfleur[]="fleur1a.bmp";
  char continuer = 1;

  srand(time(NULL));

  SDL_Event event;
  while (continuer) {
    SDL_WaitEvent(&event);
    switch (event.type) {
      case SDL_QUIT:
        continuer = 0;
        break;
      case SDL_MOUSEBUTTONDOWN:
        //Chargement d'un fichier fleur

        fleur = SDL_LoadBMP(currfleur);
        currfleur[5]=(rand() % 8 + 1)+'0';
        //sprintf(currfleur, "fleur%da.bmp", rand() % 8 + 1);

        /*
        currfleur[5]=currfleur[5]+1;
        if(currfleur[5]=='9') currfleur[5]='1';
        */

        SDL_SetColorKey(fleur, SDL_SRCCOLORKEY, 0x000000);
        rect_fleur.x = event.button.x-(fleur->w)/2;
        rect_fleur.y = event.button.y-fleur->h+10;
        SDL_BlitSurface(fleur, NULL, ecran, &rect_fleur);
        SDL_Flip(ecran);
        SDL_FreeSurface(fleur);
        break;
    }
  }

  SDL_Quit();
  return EXIT_SUCCESS;
}
