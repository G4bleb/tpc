/*
Ce programme demande une date en entrée, et affiche celle du lendemain
Programme produit le 28/09/2016 par Gabriel LEBIS
*/
#include <stdio.h>
#define ANNEEMIN 0
#define ANNEEMAX 2100
int main(){
  int jour; //Jour en entrée
  int mois; //Mois en entrée
  int annee; //Année en entrée
  int jourplus; //Jour en sortie
  int moisplus; //Mois en sortie
  int anneeplus; //Année en sortie
  int jmois; //Nombre de jours dans le mois donné en entrée
  int bissext = 0; //0 si l'année n'est pas bissextile, 1 si elle l'est
  printf("jj/mm/aaaa : ");
  scanf("%d/%d/%d", &jour, &mois, &annee);
  jourplus = jour+1;
  moisplus = mois;
  anneeplus = annee;
  if (jour < 0 || jour > 31) {
    printf("Erreur : jour invalide\n");
    return -1;
  }
  if (annee < ANNEEMIN || annee > ANNEEMAX) {
    printf("Erreur : année invalide \n");
    return -1;
  }
  if((annee % 4 == 0 && annee % 100 != 0) || annee % 400 == 0){ //Si l'année donnée est bissextile
    bissext=1;
  }

  switch (mois) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12: //Mois à 31 jours
      jmois = 31;
      break;
    case 4: case 6: case 9: case 11: //Mois à 30 jours
      jmois = 30;
      break;
    case 2: //février
      jmois = 28 + bissext;
      break; // Ce break semble nécessaire
    default: //Mois impossible
      printf("Erreur : mois invalide\n");
      return -1;
  }
  if (jmois == jour) { //Si le jour donnée est le dernier jour du mois
    moisplus =+ 1;
    jourplus = 1;
    if (mois == 12) { //Si le mois donné est décembre, et qu'il faut le changer
      moisplus = 1; //Le mois en sortie sera Janvier
      anneeplus += 1;
    }
  }
  printf("Le lendemain : ");
  printf("%d/%d/%d\n",jourplus, moisplus, anneeplus);
}
