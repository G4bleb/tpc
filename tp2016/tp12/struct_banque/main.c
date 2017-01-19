#include "header.h"


int main(){
  int brk = 1;
  int nb_clients = 0;
  Client *tab_clients = NULL;
  while (brk){
    switch (menu()) {
      case 0: brk = 0; break;
      case 1: tab_clients = ajoutClient(tab_clients, &nb_clients); break;
      case 2: dispClients(nb_clients, tab_clients); break;
      case 3: rechercheClient(nb_clients, tab_clients); break;
      case 4: virement(tab_clients, nb_clients); break;
      case 5: tab_clients = supprClient(tab_clients, &nb_clients); break;
      default: printf("Saisie non valide");
    }
  }
  return 0;
}
