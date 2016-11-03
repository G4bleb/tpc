#include <stdio.h>
#include <string.h>
int main() //Début du programme
{
  int a;
  int b;
  char ope[1];
  char fois[] = "*";
  printf("calcul :  ");
  scanf("%d %s %d", &a, ope ,&b);; //demande d'une entrée (à rentrer dans taf)
  if (strcmp(ope,fois)== 10) { //si taf==demande, strcmp(taf,demande)==10
    printf("%d", a*b);
  }
}
