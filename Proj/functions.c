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
    //printf("chaine allouée\n");
  }

  char ligne[LMAX];
  for (int y = 0; y < coordy; y++) {
    fgets(ligne, LMAX, fp);
    for (int x = 0; x < coordx; x++) {
      //printf("i = %d, j = %d\n", y, x);
      //printf("%c\n", ligne[x]);
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
