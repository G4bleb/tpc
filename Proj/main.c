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
  Robot *bot = malloc(sizeof(bot));
  bot->xpos = 3;
  bot->ypos = 3;
  grille[bot->ypos][bot->xpos]='X';
  for(int i=0; 1; i++){
    system("clear");
    printf("boucle %d\n", i);
    printf("bot : x=%d, y=%d\n", bot->xpos, bot->ypos);
    printf("x= %d y=%d\n", xgrille, ygrille);
    displayGrid(grille, xgrille, ygrille);
    movePlayer(grille, bot);
  }
  return 0;
}
