#include "header.h"

char **fileOpen(char *chemin, int *xgrille, int *ygrille){
  FILE *fp = NULL;
  if (!(fp = fopen(chemin, "r"))){
    printf("Erreur d'ouverture du fichier\n");
    return NULL;
  }
  int coordx, coordy;

  fscanf(fp, "%d:%d ", &coordx, &coordy);
  printf("%d\n", coordx);
  printf("%d\n", coordy);

  char **grille = malloc((size_t)(coordx)*sizeof(char*));
  for (int x = 0; x < coordx; x++) {
    grille[x] = malloc((size_t)(coordy)*sizeof(char));
    printf("chaine allouée\n");
  }

  char ligne[LMAX];
  for (int y = 0; y < coordy; y++) {
    fgets(ligne, LMAX, fp);
    for (int x = 0; x < coordx; x++) {
      //printf("i = %d, j = %d\n", y, x);
      printf("%c\n", ligne[x]);
      grille[x][y]=ligne[x];
    }
  }

  fclose(fp);
  *xgrille=coordx;
  *ygrille=coordy;
  printf("Copie terminée\n");
  return grille;
}

void displayGrid(char **grille, const int xgrille, const int ygrille){
  for (int y = 0; y < ygrille; y++) {
    for (int x = 0; x < xgrille; x++) {
      printf("%c", grille[x][y]);
    }
    printf("\n");
  }
}
void movePlayer(char **grille, Robot *bot){
  char mov;
  scanf("%c", &mov);
  getchar();
  step(grille, bot, mov);
  //if (bot->xpos>X_GRILLE) {grille[X_GRILLE][bot->ypos]='X';bot->xpos=X_GRILLE;}
  //if (bot->ypos>Y_GRILLE) {grille[bot->xpos][Y_GRILLE]='X';bot->ypos=Y_GRILLE;}
  //if (bot->xpos<0) {grille[0][bot->ypos]='X';bot->xpos=0;}
  //if (bot->ypos<0) {grille[bot->xpos][0]='X';bot->ypos=0;}
}

void moveRobot(char **grille, Robot *bot){
  //step(grille, bot->xpos, bot->ypos, orient)
}

void step(char **grille, Robot *bot, char mov){
  if (mov=='z') {
    if (grille[bot->xpos][bot->ypos-1] != 'x') {
      grille[bot->xpos][bot->ypos]=' ';
      bot->ypos-=1;
      grille[bot->xpos][bot->ypos]='X';
    }
  }
  if (mov=='q') {
    if (grille[bot->xpos-1][bot->ypos] != 'x') {
      grille[bot->xpos][bot->ypos]=' ';
      bot->xpos-=1;
      grille[bot->xpos][bot->ypos]='X';
    }
  }
  if (mov=='s') {
    if (grille[bot->xpos][bot->ypos+1] != 'x') {
      grille[bot->xpos][bot->ypos]=' ';
      bot->ypos+=1;
      grille[bot->xpos][bot->ypos]='X';
    }
  }
  if (mov=='d') {
    if (grille[bot->xpos+1][bot->ypos] != 'x') {
      grille[bot->xpos][bot->ypos]=' ';
      bot->xpos+=1;
      grille[bot->xpos][bot->ypos]='X';
    }
  }
  printf("just moved : x= %d, y= %d\n", bot->xpos, bot->ypos);
}
