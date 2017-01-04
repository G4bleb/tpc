#include "header.h"

int menu(){
  int saisie;
  printf("Menu principal :\n\n1)Ajouter des clients\n2)Afficher tous les clients\n3)Rechercher un client\n4)Supprimer un client\n0)Quitter\n\n");
  scanf("%d", &saisie);
  getchar();
  return saisie;
}

Client *ajoutClient(Client *tab_clients, int *nb_clients){
  int i;
  char saisie[LM];
  int brk=1;
  for (i = *nb_clients; brk!=0; i++) {
    printf("Saisir le nom du client %d (Pour annuler, taper \"fin\")\n", i+1);
    fgets(saisie, LM, stdin);
    saisie[strlen(saisie)-1]='\0';
    brk = strcmp("fin",saisie);
    if (brk){
      tab_clients = realloc(tab_clients, ((i+1)*sizeof(Client)));
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
  int i, nbFound = 0;
  int brk = 1;
  char nom[LM];
  char prenom[LM];
  while (brk){
    printf("Recherche de clients :\nEntrez le nom du client : (Pour annuler, taper \"fin\")\n");
    fgets(nom, LM, stdin);
    nom[strlen(nom)-1]='\0';
    brk = strcmp("fin",nom);
    //fgets(prenom, LM, stdin);
    //prenom[strlen(prenom)-1]='\0';
    for (i = 0; i < nb_clients; i++) {
      if (!strcmp(nom, tab_clients[i].nom)){
        dispClient(tab_clients, i);
        nbFound++;
      }
    }
    if (!nbFound) {
      printf("Aucun client trouvé\n\n");
    }
  }
  return i;
}

Client *supprClient(Client *tab_clients, int *nb_clients){
  int saisie;
  printf("Quel client souhaitez vous supprimer ? Entrez le numéro du client\n");
  scanf("%d", &saisie);
  *nb_clients--;
  tab_clients[saisie].solde=tab_clients[*nb_clients].solde;
  strcpy(tab_clients[saisie].nom,tab_clients[*nb_clients].prenom);
  strcpy(tab_clients[saisie].prenom,tab_clients[*nb_clients].nom);
  tab_clients = realloc(tab_clients, ((*nb_clients)*sizeof(Client)));
  return tab_clients;
}
