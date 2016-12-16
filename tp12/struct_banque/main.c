#include "header.h"


int main(){
  int nb_clients;
  Client *tab_clients = NULL;
  tab_clients = ajoutClient(tab_clients, &nb_clients);
  dispClients(nb_clients, tab_clients);
  rechercheClient(nb_clients, tab_clients);
  return 0;
}
