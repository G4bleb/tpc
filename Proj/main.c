#include "header.h"

int main(int argc, char *argv[]){
  if(argc!=3){
    printf("Usage : ./main.exe labytxtpath graphicalMode(0 : Console/1 : Graphics)\n");
    return -1;
  }
  int xgrid, ygrid;
  char **grid;
  if(!(grid = fileOpen(argv[1], &xgrid, &ygrid))){
    printf("Erreur de traitement du fichier\n");
    return -1;
  }
  srand((unsigned int)time(NULL));
  printf("Creating bot\n");
  Robot *bot = startBot(grid, xgrid, ygrid);
  printf("bot->xpos = %d, bot->ypos = %d\n", bot->xpos, bot->ypos);
  Graph * surfaces = NULL;
  if((char)atoi(argv[2]))surfaces = initGraphics("floorTile.bmp","wall.bmp", "bot.bmp", "exit.bmp", "won.bmp", grid, xgrid, ygrid);
  char won = graphicLoop(grid, bot, surfaces, xgrid, ygrid);
  if (won) {
    printf("Got out ! : Steps = %d\n", bot->steps);
  }else{
    printf("Got lost ! : Steps = %d\n", bot->steps);
  }
  free(grid);
  return 0;
}
