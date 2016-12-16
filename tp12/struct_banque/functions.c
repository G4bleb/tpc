#include "header.h"

Client *ajoutClient(Client *tab_clients, int *nb_clients){
  int i;
  char saisie[LM];
  int brk=1;
  for (i = 0; brk!=0; i++) {
    printf("Saisir le nom du client %d (Pour annuler, taper \"fin\")\n", i+1);
    fgets(saisie, LM, stdin);
    saisie[strlen(saisie)-1]='\0';
    brk = strcmp("fin",saisie);
    if (brk){
      tab_clients = realloc(tab_clients, ((i+1)*sizeof(Client))); //ok
      tab_clients[i].nom = malloc((strlen(saisie)+1)*sizeof(char));
      strcpy(tab_clients[i].nom, saisie);

      printf("Saisir le prénom du client %d\n", i+1);
      fgets(saisie, LM, stdin);
      saisie[strlen(saisie)-1]='\0';
      tab_clients[i].prenom = malloc((strlen(saisie)+1)*sizeof(char));
      strcpy(tab_clients[i].prenom, saisie);

      printf("Saisir le solde du client %d\n", i+1);
      scanf("%d", &tab_clients[i].solde);
      getchar();
    }
  }
  *nb_clients=i-1;
  return tab_clients;
}

void dispClient(Client *tab_clients, int i){
    printf("Client %d :\n   Nom : %s\n   Prénom : %s\n   Solde : %d€\n", i+1, tab_clients[i].nom,tab_clients[i].prenom,tab_clients[i].solde);
}

void dispClients(const int nb_clients, Client *tab_clients){
  for (int i = 0; i < nb_clients; i++) {
    dispClient(tab_clients, i);
  }
}

int rechercheClient(const int nb_clients, Client *tab_clients){
  int i;
  int brk = 1;
  char nom[LM];
  char prenom[LM];
  while (brk){
    printf("Recherche de clients : \nEntrez le nom, puis le prénom du client :\n");
    fgets(nom, LM, stdin);
    fgets(prenom, LM, stdin);
    for (i = 0; i < nb_clients && brk==1; i++) {
      if (!strcmp(nom, tab_clients[i].nom) && !strcmp(prenom, tab_clients[i].prenom)){
        dispClient(tab_clients, i);
        brk=0;
      }
    }
  }
  return i;
}
