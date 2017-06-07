/*

Programme produit le  par Gabriel LEBIS
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NB_VILLES 39
#define LG_MAX 100

char **villes;

ushort **create_graph( int nb_nds);
void visit(ushort **adj, int nbNds, int i, int *mark);
void parcoursDfs(ushort **adj, int nbNds, int i_dep);
int indice(char **villes, char *nom_ville);
char *name(char **villes, int indice);
FILE *openFilePointer(char *path);

int adjacent (ushort **matrice, int i1, int i2);
//return 1 si 2 noeuds adjacents, 0 si pas adjacents
int *voisins(ushort **matrice, int nb_noeuds, int i);
//retourne la liste des indices des noeuds adjacents au noeud i
//+Faire Dijkstra
