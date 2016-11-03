#include <stdio.h>
int main() //Début du programme
{
  //Décalaration des variables
  char c;
  char d;
  int x;
  float y;
  //finDéclaration des variables
  c='A';
  d='d';
  x=5;
  y=12.146;
  printf("des caractères naturels %c %c\n",c,d);
  printf("des caractères en décimal %d %d\n",c,d);
  printf("des caractères en hexa %x %x\n",c,d);
  printf("les adresses de ces char %p %p\n",&c,&d);

  printf("un entier %d\n",x);
  printf("un flottant %f\n", y);

  printf("la taille de %c est %ld\n",c,sizeof(c));
  printf("la taille de %d est %ld\n",x,sizeof(x));
  printf("la taille de %f est %ld\n",y,sizeof(y));
}
