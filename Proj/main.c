#include "header.h"

int main(int argc, char *argv[]){
  if(argc!=3){ //Si le nombre d'arguments est invalide
    printf("Usage : ./main.exe labytxtpath graphicalMode(0 : Console/1 : Graphics)\n");
    return -1;
  }
  int xgrid, ygrid; //Dimensions de la grille
  char **grid; //Pointeur sur la grille
  if(!(grid = fileOpen(argv[1], &xgrid, &ygrid))){ //Si la grille n'a pas été ouverte avec succès
    printf("Erreur de traitement du fichier\n");
    return -1;
  }
  srand((unsigned int)time(NULL)); //Graine de tirage aléatoire
  printf("Creating bot\n");
  Robot *bot = startBot(grid, xgrid, ygrid); //Initialisation du robot
  printf("bot->xpos = %d, bot->ypos = %d\n", bot->xpos, bot->ypos);
  Graph * surfaces = NULL; //Contient la plupart des surfaces
  if((char)atoi(argv[2]))surfaces = initGraphics("floorTile.bmp","wall.bmp", "bot.bmp", "exit.bmp", "won.bmp", grid, xgrid, ygrid); //Initialisation des surfaces si les graphismes sont demandés en SDL
  char won = graphicLoop(grid, bot, surfaces, xgrid, ygrid);//La boucle d'attente ren
  if (won) { //Si le robot est sorti
    printf("Got out ! : Steps = %d\n", bot->steps);
  }else{
    printf("Got lost ! : Steps = %d\n", bot->steps);
  }
  free(surfaces);
  for (int x = 0; x < xgrid; x++) {
    free(grid[x]);
  }
  free(grid);
  free(bot);
  return 0;
}
