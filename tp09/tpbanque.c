/*
Ouverture d'un compte dans une banque.
Un client valide :
1) Est majeur et dépose au minimum 100?
ou
2) Dépose plus de 100 000
Programme produit le 26/09/2016 par Gabriel LEBIS
*/
#include <stdio.h>
//3 valeurs susceptibles de changer :
#define AGEMIN 18 //L'âge minimum
#define DEPMIN 100 //Le dépôt minimum
#define DEPOK 100000 //Le dépôt minimum où l'on ignore l'âge
#define AGEMAX 150 //L'âge maximum
int main(){
  int deposit;
  int age;
  printf("Ouverture d'un compte\n");
  printf("Quelle somme souhaitez vous déposer ? ");
  scanf("%d", &deposit);
  if (deposit < DEPMIN) {//La somme proposée est trop basse/l'entrée n'est pas bonne
    printf("Erreur : somme trop petite ou non valide\n");
    return -1;
  }
  if(deposit >= DEPOK){ //La somme est assez grande pour ignorer l'âge
    printf("Virement validé, bienvenue.\n");
    return 0;
  }
  else{ //La somme est valide, mais on souhaite l'âge du dépositaire
    printf("Veuillez entrer votre âge : ");
    scanf("%d", &age);

    if (age < AGEMIN || age > AGEMAX) { //Le client est mineur/son âge n'est pas bon
      printf("Erreur : client mineur ou âge non valide\n");
      return -1;
    }
    else{ //Le client est majeur
      printf("Virement validé, bienvenue.\n");
      return 0;
    }
  }
}
