/*

Programme produit le  par Gabriel LEBIS
*/
#include <stdio.h>

int main(){
  struct client {
    char nom[10];
    char prenom[10];
    int solde;
  };
  struct client tab[2]={{"Dupont", "Marcel", 1000}, {"Le Gall", "Kevin", 500}};
  FILE *fp = fopen("test","w");
  fwrite(tab, sizeof(struct client), 2, fp);
  fclose(fp);
  return 0;
}
