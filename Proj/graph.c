#include "header.h"

//==============================================================================
// Fonction : initGraphics
// Rôle : Initialisation graphique globale
// Entrée : char *bgFilename : chemin du fichier de case de fond
//          char *wallFilename : chemin du fichier de case de sol
//          char *botFilename : chemin du fichier de spritesheet de robot
//          char *exitFilename : chemin du fichier de case de sortie
//          char *wonFilename : chemin du fichier de case de sortie après résolution du labyrinthe
//          char **grid, const int xgrid, const int ygrid : Matrice du labyrinthe et ses dimensions
// Entrée/sortie : non
// Sortie : non
// Return : Graph *surfaces, structure contenant toutes les SDL_Surfaces initialisées
//==============================================================================

Graph *initGraphics(char * bgFilename, char *wallFilename, char *botFilename, char *exitFilename,char *wonFilename, char **grid, const int xgrid, const int ygrid){
  Graph *surfaces = malloc(sizeof(Graph)); //Allocation de la zone mémoire de surfaces
  surfaces->screen = initScreen (xgrid, ygrid); //On initie la fenêtre
  surfaces->background = SDL_LoadBMP(bgFilename); //On charge le fichier de fond dans une SDL_Surface
  surfaces->wall = loadSprites (wallFilename); //On charge le fichier de murs dans une SDL_Surface
  surfaces->exit = SDL_LoadBMP(exitFilename); //On charge le fichier de sortie dans une SDL_Surface
  surfaces->won = SDL_LoadBMP(wonFilename); //On charge le fichier de sortie "activée" dans une SDL_Surface
  surfaces->botSprites = loadSprites(botFilename);
  if (!surfaces->background) {
    fprintf(stderr, "Impossible de charger le fichier %s : %s\n", bgFilename, SDL_GetError());
    exit(EXIT_FAILURE);
  }
  if (!surfaces->exit) {
    fprintf(stderr, "Impossible de charger le fichier %s : %s\n", exitFilename, SDL_GetError());
    exit(EXIT_FAILURE);
  }
  if (!surfaces->won) {
    fprintf(stderr, "Impossible de charger le fichier %s : %s\n", wonFilename, SDL_GetError());
    exit(EXIT_FAILURE);
  }
  if (!surfaces->botSprites) {
    fprintf(stderr, "Impossible de charger le fichier %s : %s\n", botFilename, SDL_GetError());
    exit(EXIT_FAILURE);
  }
  drawBackground(surfaces->background, surfaces->screen, xgrid, ygrid); //On dessine le sol
  drawWalls(surfaces->wall, surfaces->screen, grid, xgrid, ygrid); //On dessine les murs
  drawExit(surfaces->exit, surfaces->screen, grid, xgrid, ygrid); //On dessine la sortie
  Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024); //On ouvre SDL_Mixer
  return surfaces;
}

//==============================================================================
// Fonction : initScreen
// Rôle : Initialisation graphique de la surface écran et de la fenêtre
// Entrée : const int xgrid, const int ygrid : Dimensions de la matrice du labyrinthe
// Entrée/sortie : non
// Sortie : non
// Return : SDL_Surface *screen : Surface écran
//==============================================================================

SDL_Surface *initScreen (const int xgrid, const int ygrid){
  SDL_Surface *screen;
  screen = SDL_SetVideoMode(xgrid*WALL_SIZE, ygrid*WALL_SIZE, 32, SDL_HWSURFACE|SDL_DOUBLEBUF); //On ouvre la fenêtre, en fonction de la place que va prendre les murs
  if (!screen) {
    fprintf(stderr, "Erreur : %s\n",SDL_GetError());
    exit(EXIT_FAILURE);
  }
  SDL_WM_SetCaption("Labyrinth Solver", NULL);//On nomme la fenêtre
  return screen;
}

//==============================================================================
// Fonction : setSurfaceCoords
// Rôle : Change les coordonnées x et y d'une SDL_Surface
// Entrée : SDL_Surface *img pointeur sur la surface concernée
//          const int x, const int y les nouvelles coordonnées à assigner
// Entrée/sortie : non
// Sortie : non
// Return : SDL_Surface *img : pointeur sur la SDL_Surface donnée en entrée
//==============================================================================

SDL_Surface *setSurfaceCoords ( SDL_Surface *img, const int x, const int y ){
  img->clip_rect.x = (Sint16)x;
  img->clip_rect.y = (Sint16)y;
  return img;
}

//==============================================================================
// Fonction : drawImage
// Rôle : Dessine une SDL_Surface sur une autre
// Entrée : SDL_Surface *img : SDL_Surface à dessiner
//          SDL_Surface *screen : SDL_Surface sur laquelle dessiner
// Entrée/sortie : non
// Sortie : non
// Return : non
//==============================================================================

void drawImage (SDL_Surface *img, SDL_Surface *screen){
  SDL_BlitSurface(img , NULL, screen, &img->clip_rect);
}

//==============================================================================
// Fonction : loadSprites
// Rôle : Charge une image sur une SDL_Surface, et applique une transparence ColorKey sur le blanc
// Entrée : char * sprites_filename : chemin vers l'image
// Entrée/sortie : non
// Sortie : non
// Return : SDL_Surface* pointant la SDL_Surface contenant l'image, avec la transparence appliquée
//==============================================================================

SDL_Surface *loadSprites ( char *sprites_filename ){
  SDL_Surface *spriteSheet = SDL_LoadBMP(sprites_filename);
  if (!spriteSheet) {
    fprintf(stderr, "Impossible de charger le fichier %s : %s\n", sprites_filename, SDL_GetError());
    exit(EXIT_FAILURE);
  }
  SDL_SetColorKey(spriteSheet, SDL_SRCCOLORKEY, 0xFFFFFF);
  return spriteSheet;
}

//==============================================================================
// Fonction : drawBackground
// Rôle : Dessine le fond sur l'ecran, en fonction de la taille de la matrice
// Entrée : SDL_Surface *floorTile : Pointeur sur la SDL_Surface d'une case de sol
//          SDL_Surface *screen : Pointeur sur la SDL_Surface de l'écran
//          const int xgrid, const int ygrid : Dimensions de la matrice du labyrinthe
// Entrée/sortie : non
// Sortie : non
// Return : non
//==============================================================================

void drawBackground(SDL_Surface *floorTile, SDL_Surface *screen, const int xgrid, const int ygrid){
  for (int y = 0; y < ygrid; y++) {
    for (int x = 0; x < xgrid; x++) {
      floorTile = setSurfaceCoords(floorTile, x*FLOOR_SIZE, y*FLOOR_SIZE);
      drawImage(floorTile, screen);
    }
  }
  SDL_Flip(screen);
}

//==============================================================================
// Fonction : drawWalls
// Rôle : Dessine les murs de la matrice sur l'écran
// Entrée : SDL_Surface *wall : Pointeur sur la SDL_Surface d'une case de mur
//          SDL_Surface *screen : Pointeur sur la SDL_Surface de l'écran
//          char **grid, const int xgrid, const int ygrid : Matrice du labyrinthe et ses dimensions
// Entrée/sortie : non
// Sortie : non
// Return : non
//==============================================================================

void drawWalls(SDL_Surface *wall, SDL_Surface *screen, char **grid, const int xgrid, const int ygrid){
  for (int y = 0; y < ygrid; y++) {
    for (int x = 0; x < xgrid; x++) {
      if (grid[x][y]=='x') {//Si il y a un mur dans la matrice
        wall = setSurfaceCoords(wall, x*WALL_SIZE, y*WALL_SIZE);
        drawImage(wall, screen);
      }
    }
  }
  SDL_Flip(screen);
}

//==============================================================================
// Fonction : drawExit
// Rôle : Dessine la sortie de la matrice sur l'écran
// Entrée : SDL_Surface *exit : Pointeur sur la SDL_Surface d'une case de sortie
//          SDL_Surface *screen : Pointeur sur la SDL_Surface de l'écran
//          char **grid, const int xgrid, const int ygrid : Matrice du labyrinthe et ses dimensions
// Entrée/sortie : non
// Sortie : non
// Return : non
//==============================================================================

void drawExit(SDL_Surface *exit, SDL_Surface *screen, char **grid, const int xgrid, const int ygrid){
  char continuer = 1;
  for (int y = 0; y < ygrid && continuer; y++) {
    for (int x = 0; x < xgrid && continuer; x++) {
      if (grid[x][y]=='S') {//Si il y a la sortie dans la matrice
        exit = setSurfaceCoords(exit, x*WALL_SIZE, y*WALL_SIZE);
        drawImage(exit, screen);
        continuer=0;
      }
    }
  }
  SDL_Flip(screen);
}

//==============================================================================
// Fonction : drawBot
// Rôle : Dessine le robot sur l'écran, et utilise la spriteSheet pour afficher chaque orientation
//Entrée :  SDL_Surface *screen : Pointeur sur la surface de l'écran
//          SDL_Surface *botSprites : Pointeur sur la SDL_Surface de la spriteSheet
//          Robot *bot : Pointeur sur robot, utilisé pour xpos et ypos
// Entrée/sortie : non
// Sortie : non
// Return : non
//==============================================================================

void drawBot(SDL_Surface *screen, Robot *bot, SDL_Surface *botSprites){
  SDL_Rect rect_src; // Rectangle source
  SDL_Rect rect_dest; // Rectangle destination
  rect_src.x =(Sint16)((bot->orient-1)*BOT_WIDTH); //On déplace le rect dans la spriteSheet en fonction de l'orientation du robot
  rect_src.y =0;
  rect_src.w = BOT_WIDTH;
  rect_src.h = BOT_HEIGHT;
  rect_dest.x = (Sint16)(bot->xpos*WALL_SIZE);
  rect_dest.y = (Sint16)((bot->ypos*WALL_SIZE)-WALL_SIZE/2); //On place le robot une demi case plus haut, pour créer un effet de perspective
  SDL_BlitSurface(botSprites, &rect_src, screen, &rect_dest); //On applique la surface, découpée avec rect_src, appliquée sur l'ecran, à rect_dest
  SDL_Flip(screen);
}

//==============================================================================
// Fonction : reDrawAround
// Rôle : Redessine les huits cases autour du robot, et la sienne
// Entrée : Graph *surfaces : Pointeur sur la structure contenant les SDL_Surfaces
//          Robot *bot : Pointeur sur robot, utilisé pour oldx et oldy
//          char **grid : Matrice du labyrinthe
// Entrée/sortie : non
// Sortie : non
// Return : non
//==============================================================================

void reDrawAround(Graph *surfaces, Robot *bot, char **grid){
      surfaces->background = setSurfaceCoords(surfaces->background, (bot->oldx)*FLOOR_SIZE, (bot->oldy)*FLOOR_SIZE);
      drawImage(surfaces->background, surfaces->screen);
      reDraw(surfaces, grid, bot->oldx, bot->oldy-1); //Le sprite dépasse dans les 8 directions
      reDraw(surfaces, grid, bot->oldx, bot->oldy+1);
      reDraw(surfaces, grid, bot->oldx-1, bot->oldy);
      reDraw(surfaces, grid, bot->oldx+1, bot->oldy);
      reDraw(surfaces, grid, bot->oldx+1, bot->oldy-1);
      reDraw(surfaces, grid, bot->oldx-1, bot->oldy+1);
      reDraw(surfaces, grid, bot->oldx-1, bot->oldy-1);
      reDraw(surfaces, grid, bot->oldx+1, bot->oldy+1);
}

//==============================================================================
// Fonction : reDraw
// Rôle : Redessine une case du labyrinthe sur l'écran
// Entrée : Graph *surfaces : Pointeur sur la structure contenant les SDL_Surfaces
//          char **grid : Matrice du labyrinthe
//          const int x, const int y : coordonnées de la case à redessiner
// Entrée/sortie : non
// Sortie : non
// Return : non
//==============================================================================

void reDraw(Graph *surfaces, char **grid, const int x, const int y){
  surfaces->background = setSurfaceCoords(surfaces->background, x*FLOOR_SIZE, y*FLOOR_SIZE);
  drawImage(surfaces->background, surfaces->screen);//Dessiner le sol aux coordonnées
  if (grid[x][y]=='x') {//Si c'est un mur
    surfaces->wall = setSurfaceCoords(surfaces->wall, x*WALL_SIZE, y*WALL_SIZE);//Dessiner un mur aux coordonnées
    drawImage(surfaces->wall, surfaces->screen);
  } else if(grid[x][y]=='S'){//Sinon, si c'est la sortie
    drawImage(surfaces->exit, surfaces->screen);//Dessiner las sortie aux coordonnées
  }
}

//==============================================================================
// Fonction : drawMove
// Rôle : Dessine un déplacement du robot
// Entrée : Graph *surfaces : Pointeur sur la structure contenant les SDL_Surfaces
//          Robot *bot : Pointeur sur robot
//          char **grid, const int xgrid, const int ygrid : Matrice du labyrinthe et ses dimensions
//          const int counter, const int steps : Compteur de l'algorithme, et nombre de pas : utilisés pour l'affichage console
// Entrée/sortie : non
// Sortie : non
// Return : non
//==============================================================================

void drawMove(Graph *surfaces, Robot *bot, char **grid, const int xgrid, const int ygrid, const int counter, const int steps){
  if (!surfaces) { //Si la SDL n'a pas été chargée
    displayGrid(grid, xgrid, ygrid);
    printf("Counter = %d, Steps = %d\n",counter, steps);
  }else{
    reDrawAround(surfaces, bot, grid); //Redessiner autour du robot
    drawBot(surfaces->screen, bot, surfaces->botSprites); //Dessiner le robot
    SDL_Flip(surfaces->screen); //actualiser l'écran
  }
  bot->oldx = bot->xpos; //Le déplacement a été fait
  bot->oldy = bot->ypos; //Le déplacement a été fait
  SDL_Delay(DELAY); //Délai d'affcichage, pour un déplacement plus naturel
}

//==============================================================================
// Fonction : graphicLoop
// Rôle : Boucle d'attente d'événement SDL
// Entrée : Robot *bot : Pointeur sur robot, utilisé pour xpos et ypos
//          Graph *surfaces : Pointeur sur la structure contenant les SDL_Surfaces
//          char **grid, const int xgrid, const int ygrid : Matrice du labyrinthe et ses dimensions
// Entrée/sortie : non
// Sortie : non
// Return : char won : won = 1 si la sortie a été trouvée par le robot, 0 sinon
//==============================================================================

char graphicLoop(char **grid, Robot *bot, Graph *surfaces, const int xgrid, const int ygrid){
  int counter = 0;
  char over = 0;
  char won = 0;
  char wait = 0;
  drawMove(surfaces, bot, grid, xgrid, ygrid, counter, bot->steps);//Affichage de la position de départ du robot
  SDL_Event event;
  while (!over) {
    while ( SDL_PollEvent ( &event ) ) { //Tant qu'il y a un évènement
    switch ( event.type ) {
      case SDL_KEYUP: //Relâchement d'un touche
        switch (event.key.keysym.sym) {
          case SDLK_SPACE: //Touche espace : activer/désactiver la pause
            playSound("pause.wav");
            if (wait) wait=0;
            else wait=1;
            break;
          default:
            break;
        }
      break;
      case SDL_QUIT : //Appui sur la croix, ou Ctrl-C dans la console
        over = 1;
        break;
      }
    }
    if (!wait) {//Si l'on est pas en pause
      if(!won) {//Si l'on a pas gagner
        won = moveRobot(grid, bot, surfaces, xgrid, ygrid, &counter);//Faire progresser l'algorithme
      }else if(surfaces){ //Victoire, SDL chargée
        drawWon(surfaces->exit, surfaces->won, surfaces->screen);//Dessiner la sortie "activée"
        playSound("win.wav");
        wait=1;
      }else{//Victoire, SDL non chargée
        over=1;
      }
    }
  }
  SDL_Quit();
  Mix_CloseAudio();//Fermeture du mixeur audio
  return won;
}

//==============================================================================
// Fonction : drawWon
// Rôle : Dessine la sortie "activée" de la matrice sur l'écran
// Entrée : SDL_Surface *exit : Pointeur sur la SDL_Surface d'une case de sortie (utilisée pour ses coordonnées)
//          SDL_Surface *won : Pointeur sur la SDL_Surface d'une case de sortie "activée"
//          SDL_Surface *screen : Pointeur sur la SDL_Surface de l'écran
// Entrée/sortie : non
// Sortie : non
// Return : non
//==============================================================================

void drawWon(SDL_Surface *exit, SDL_Surface *won, SDL_Surface *screen){
  won = setSurfaceCoords(won, exit->clip_rect.x, exit->clip_rect.y); //On aligne la SDL_Surface de sortie "activée" sur la SDL_Surface de sortie actuelle
  drawImage(won, screen);
  SDL_Flip(screen);
}

//==============================================================================
// Fonction : playSound
// Rôle : Joue un son
// Entrée : char *soundFilename : chemin du fichier son à lire
// Entrée/sortie : non
// Sortie : non
// Return : non
//==============================================================================

void playSound(char *soundFilename){
  Mix_Music *musique = Mix_LoadMUS(soundFilename);
  if (musique) {
    Mix_PlayMusic(musique, 1);
  }
}
