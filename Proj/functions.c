#include "header.h"

char **fileOpen(char *chemin, int *xgrid, int *ygrid){
  FILE *fp = NULL;
  if (!(fp = fopen(chemin, "r"))){
    printf("Erreur d'ouverture du fichier\n");
    return NULL;
  }
  int coordx, coordy;

  fscanf(fp, "%d:%d ", &coordx, &coordy);
  printf("Taille matrice : %d:%d\n", coordx, coordy);

  char **grid = malloc((size_t)(coordx)*sizeof(char*));
  for (int x = 0; x < coordx; x++) {
    grid[x] = malloc((size_t)(coordy)*sizeof(char));
    //printf("chaine allouée\n");
  }

  char ligne[LMAX];
  for (int y = 0; y < coordy; y++) {
    fgets(ligne, LMAX, fp);
    for (int x = 0; x < coordx; x++) {
      //printf("i = %d, j = %d\n", y, x);
      //printf("%c\n", ligne[x]);
      grid[x][y]=ligne[x];
    }
  }

  fclose(fp);
  *xgrid=coordx;
  *ygrid=coordy;
  printf("Copie terminée\n");
  return grid;
}

void displayGrid(char **grid, const int xgrid, const int ygrid){
  for (int y = 0; y < ygrid; y++) {
    for (int x = 0; x < xgrid; x++) {
      printf("%c", grid[x][y]);
    }
    printf("\n");
  }
}
