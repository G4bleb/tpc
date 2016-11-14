/*

Programme produit le 14/11/16 par Gabriel LEBIS
*/
#include <stdio.h>
#include <string.h>

#define LM 25

char *voyelles(const char *chaine1){
  int j = 0;
  int nb_voyelles = 0;
  //TODO déclarer une chaine à malloc
  size_t long_chaine = strlen(chaine1); //size_t aka long unsigned int
  for (int i = 0; i < long_chaine; i++) {
    switch (chaine1[i]){
      case 'a': case 'e': case 'i': case 'o': case 'u': case 'y': case 'A': case 'E': case 'I': case 'O': case 'U': case 'Y':
        pretour[j]=chaine1[i];
        nb_voyelles++;
        j++;
    }
  }
  return pretour;
}

int main(){
  char chaine1[LM];
  printf("Saisir une chaîne de caractères\n");
  fgets(chaine1, LM, stdin);
  char voy[strlen(chaine1)];
  printf("Nombre de voyelles : %d, les voici : %s\n", voyelles(chaine1, voy), voy);
}
