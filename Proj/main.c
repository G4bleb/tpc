#include "header.h"

//==============================================================================
// Fonction : main()
// Rôle : fonction principale
// Entrée : arguments : char *argv[1] : le chemin du fichier .txt de labyrinthe
//                      (char)atoi(argv[2]) : le mode graphique : 0:console, 1:graphique(SDL)
// Entrée/sortie : non
// Sortie : non
// Return : 0 si succès, 1(EXIT_FAILURE) si échec
//==============================================================================

int main(int argc, char *argv[]){
  if(argc!=3){ //Si le nombre d'arguments est invalide
    printf("Usage : ./main.exe labytxtpath graphicalMode(0 : Console/1 : Graphics)\n");
    return EXIT_FAILURE;
  }
  int xgrid, ygrid; //Dimensions de la grille
  char **grid = NULL; //Pointeur sur la grille
  if(!(grid = fileOpen(argv[1], &xgrid, &ygrid))){ //Ouverture du fichier, initialisation de la matrice du labyrinthe
    printf("Erreur de traitement du fichier\n");
    return EXIT_FAILURE;
  }
  Robot *bot = NULL;
  if (!(bot = startBot(grid, xgrid, ygrid))){ //Initialisation du robot
    printf("Erreur de placement du Robot\n");
    return EXIT_FAILURE;
  };
  Graph * surfaces = NULL; //Contient la plupart des surfaces
  if((char)atoi(argv[2]))surfaces = initGraphics("floorTile.bmp","wall.bmp", "bot.bmp", "exit.bmp", "won.bmp", grid, xgrid, ygrid); //Initialisation des surfaces si les graphismes sont demandés en SDL
  char won = graphicLoop(grid, bot, surfaces, xgrid, ygrid);//La boucle d'attente retourne won=1 si le robot est sorti
  if (won) { //Si le robot est sorti
    printf("Got out ! : Steps = %d\n", bot->steps);
  }else{
    printf("Got lost ! : Steps = %d\n", bot->steps);
  }

  //------------------------Free()des zones mémoire allouées
  free(surfaces);
  for (int x = 0; x < xgrid; x++) {
    free(grid[x]);
  }
  free(grid);
  for (int x = 0; x < bot->xmat; x++) {
    free(bot->mat[x]);
  }
  free(bot->mat);
  free(bot);
  return 0;
}
