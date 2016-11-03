#include <stdio.h>
#include <string.h>
int main() //Début du programme
{
  char taf[25];
  printf("Entrez votre métier:\n");
  fgets(taf, 25, stdin);
  printf("Vous êtes un %s",taf);
  printf("Vous êtes un %d\n",strcmp(taf,"pompiste"));
  if (strcmp(taf,"pompiste")== 10) {
    printf("Aha c'est marrant\n");
  }
}
