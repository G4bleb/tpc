/*

Programme produit le  par Gabriel LEBIS
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LM 20
struct Client{
  char *nom;
  char *prenom;
  int solde;
};
typedef struct Client Client;

int menu();
Client *ajoutClient(Client *tab_clients, int *nb_clients);
void dispClient(Client *tab_clients, int i);
void dispClients(const int nb_clients, Client *tab_clients);
int rechercheClient(const int nb_clients, Client *tab_clients);
Client *supprClient(Client *tab_clients, int *nb_clients);
