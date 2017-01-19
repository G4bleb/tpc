/*
Premier tp sur les fichiers
Programme produit le 19/01/2017 par Gabriel LEBIS
*/
#include <stdio.h>
#define LMAX_LIGNE 100

int main(int argc, char *argv[]){ //Un argument : chemin du fichier à lire
  FILE *fp = NULL;

  if (argc != 2){ //Si le nombre d'arguments est incorrect
    printf("Utilisation : ./fichier fichier_a_lire\n");
    return -1;
  }
  if ((fp = fopen(argv[1],"r"))==NULL){ //On ouvre le fichier pour lecture: en cas d'erreur, on rentre dans le if()
    printf("Erreur fichier\n");
    return -1;
  }

  char ligne[LMAX_LIGNE]; //buffer de lignes du fichier
  int nligne = 0;

  while (fgets(ligne, LMAX_LIGNE, fp)) { //Lecture de tout le fichier
    nligne++;
    printf("Ligne %d : %s", nligne, ligne);
  }

  printf("Nb de lignes : %d\n", nligne);
  fclose(fp);
  return 0;
}
