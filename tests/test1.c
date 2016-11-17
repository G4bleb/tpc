#include <stdio.h>
#include <string.h>
int main() //Début du programme
{
  char taf[25];
  char demande[] = "spartiate";
  printf("Quel est votre métier ? ");
  fgets(taf, 25, stdin); //demande d'une entrée (à rentrer dans taf)
  printf("Vous êtes %s",taf);
  if (strcmp(taf,demande)== 10) { //si taf==demande, strcmp(taf,demande)==10
    printf("Ahou ! Ahou ! Ahou ! \n");
  }else{
    printf("Vous n'êtes pas un guerrier :(\n");
  }
}
