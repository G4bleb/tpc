#include "header.h"
//==============================================================================
// Fonction : fileOpen
// Rôle : charger la carte depuis le fichier texte dans une matrice
// Entrée : char *chemin : chemin du fichier texte
// Entrée/sortie : non
// Sortie : int *xgrid, int *ygrid dimensions x et y du labyrinthe
// Return : Matrice 2 dimensions où est recopié le contenu du fichier .txt
//==============================================================================
char **fileOpen(char *chemin, int *xgrid, int *ygrid){
  FILE *fp = NULL;
  if (!(fp = fopen(chemin, "r"))){
    printf("Erreur d'ouverture du fichier : chemin invalide\n");
    exit(EXIT_FAILURE); //échec de l'ouverture : quitter le programme prématurément
  }
  int coordx, coordy;

  fscanf(fp, "%d:%d ", &coordx, &coordy); //découpage de la première ligne du fichier texte, récupération des coordonnées
  //printf("Taille matrice : %d:%d\n", coordx, coordy); //DEBUG
  char **grid = malloc((size_t)(coordx)*sizeof(char*)); //Allocation des pointeurs de colonnes
  for (int x = 0; x < coordx; x++) {
    grid[x] = malloc((size_t)(coordy)*sizeof(char)); //Allocation du contenu des colonnes
  }
  char ligne[coordx+2]; //Chaîne tampon (de la taille d'un ligne)
  for (int y = 0; y < coordy; y++) {
    fgets(ligne, coordx+2, fp);
    for (int x = 0; x < coordx; x++) {
      grid[x][y]=ligne[x]; //Copie du contenu du fichier dans la matrice
    }
  }

  fclose(fp); //Fermeture du pointeur sur FILE
  *xgrid=coordx; //Sortie des coordonnées
  *ygrid=coordy; //Sortie des coordonnées
  //printf("Copie terminée\n"); //DEBUG
  return grid;
}

//==============================================================================
// Fonction : displayGrid
// Rôle : afficher la matrice du labyrinthe
// Entrée : char **grid : la matrice
//          const int xgrid et const int ygrid ses dimensions
// Entrée/sortie : non
// Sortie : non
// Return : non
//==============================================================================

void displayGrid(char **grid, const int xgrid, const int ygrid){
  for (int y = 0; y < ygrid; y++) {
    for (int x = 0; x < xgrid; x++) {
      printf("%c", grid[x][y]); //Affichage du caractère de la ligne
    }
    printf("\n"); //Affichage d'une ligne terminé : retour à la ligne
  }
}
