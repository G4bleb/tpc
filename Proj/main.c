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

  displayGrid(grille, xgrille, ygrille);
  moveRobot(grille, bot, xgrille, ygrille);
  
  printf("Over !\n");
  return 0;
}
