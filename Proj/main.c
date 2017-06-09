#include "header.h"

int main(int argc, char *argv[]){
  if(argc!=3){
    printf("Usage : ./main.exe labytxtpath graphicalMode(0/1)\n");
    return -1;
  }
  int xgrid, ygrid;
  char **grid;
  if(!(grid = fileOpen(argv[1], &xgrid, &ygrid))){
    printf("Erreur de traitement du fichier\n");
    return -1;
  }
  printf("Creating bot\n");
  Robot *bot = startBot(grid, xgrid, ygrid);
  printf("bot->xpos = %d, bot->ypos = %d\n", bot->xpos, bot->ypos);

  Graph *surfaces = initGraphics("floorTile.bmp","wall.bmp", "bot.bmp", "exit.bmp", grid, xgrid, ygrid);
  char won = graphicLoop(grid, bot, surfaces, xgrid, ygrid, argv[2][0]);
  if (won) {
    printf("Got out ! : Steps = %d\n", bot->steps);
  }
  free(grid);
  return 0;
}
