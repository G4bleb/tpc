#include "header.h"

//==============================================================================
// Fonction : StartBot
// Rôle : Initialisation du Robot, et placement dans la matrice
// Entrée : char **grid : la matrice
//          const int xgrid, const int ygrid ses dimensions
// Entrée/sortie : non
// Sortie : non
// Return : Pointeur sur le Robot : bot
//==============================================================================

Robot* startBot(char **grid, const int xgrid, const int ygrid){
  Robot *bot = malloc(sizeof(Robot)); //Allocation de la zone mémoire utilisée par le robot
  bot->orient = BOT_START; //Le robot est orienté arbitrairement au départ
  bot->steps = 0; //Le Robot n'a fait aucun pas
  bot->mat = NULL; //Sa matrice n'est pas encore initialisée
  bot->xmat = 0; //Sa matrice a des dimensions nulles
  bot->ymat = 0; //Sa matrice a des dimensions nulles
  int x = 0, y = 0;
  char botPlaced = 0; //Variable booléen
  for (y = 0; (y < ygrid) && (!botPlaced); y++) { //Tant que la matrice n'a pas été intégralement parcourue, ou que
    for (x = 0; (x < xgrid) && (!botPlaced); x++) {
      if (grid[x][y] == 'D') { //Si cette position est celle du départ du robot
        bot->xpos = x;
        bot->ypos = y;
        botPlaced = 1; //Le robot a été placé
      }
    }
  }
  if (!botPlaced) { //Le robot n'a pas été correctement placé
    return NULL;
  }
  grid[bot->xpos][bot->ypos]='&';//Placement du robot sur la matrice labyrinthe
  return bot;
}

//==============================================================================
// Fonction : step
// Rôle : Faire faire au robot un pas en avant, renvoie 0 si impossible
// Entrée : char **grid : la matrice labyrinthe
//          Robot *bot le robot
// Entrée/sortie : non
// Sortie : non
// Return : 0 si échec du déplacement, une autre valeur si succès, en fonction de la direction du déplacement
//==============================================================================

char step(char **grid, Robot *bot){
  bot->oldx = bot->xpos; //On garde l'ancienne position du robot
  bot->oldy = bot->ypos;  //On garde l'ancienne position du robot
  switch (bot->orient) { //Le robot fait un pas en avant en fonction de son orientation
    case 1: //Z
      if (check(grid, bot)) { //Pas de mur en face du robot : on peut faire un pas
        grid[bot->xpos][bot->ypos]=' '; //On efface le '&' à notre position actuelle
        bot->ypos-=1; //On déplace le robot
        grid[bot->xpos][bot->ypos]='&'; //On écrit le '&' à notre nouvelle position
        bot->steps++; //Un pas a été fait
        return 1;
      }
    break;
    case 2: //Q
      if (check(grid, bot)) { //Pas de mur en face du robot : on peut faire un pas
        grid[bot->xpos][bot->ypos]=' '; //On efface le '&' à notre position actuelle
        bot->xpos-=1; //On déplace le robot
        grid[bot->xpos][bot->ypos]='&'; //On écrit le '&' à notre nouvelle position
        bot->steps++; //Un pas a été fait
        return 2;
      }
    break;
    case 3: //S
      if (check(grid, bot)) { //Pas de mur en face du robot : on peut faire un pas
        grid[bot->xpos][bot->ypos]=' '; //On efface le '&' à notre position actuelle
        bot->ypos+=1; //On déplace le robot
        grid[bot->xpos][bot->ypos]='&'; //On écrit le '&' à notre nouvelle position
        bot->steps++; //Un pas a été fait
        return 3;
      }
      break;
      case 4: //D
      if (check(grid, bot)) { //Pas de mur en face du robot : on peut faire un pas
        grid[bot->xpos][bot->ypos]=' '; //On efface le '&' à notre position actuelle
        bot->xpos+=1; //On déplace le robot
        grid[bot->xpos][bot->ypos]='&'; //On écrit le '&' à notre nouvelle position
        bot->steps++; //Un pas a été fait
        return 4;
      }
      break;
  }
  return 0; //Il y a un mur devant le robot : échec
}

//==============================================================================
// Fonction : check
// Rôle : Vérifie la possibilité au robot d'avancer d'un pas
// Entrée : char **grid : la matrice labyrinthe,
//          Robot *bot : le robot
// Entrée/sortie : non
// Sortie : non
// Return : 1 si le pas en avant est possible, 0 sinon
//==============================================================================

char check(char **grid, Robot *bot){
  switch (bot->orient) { //On vérifie dans un direction qui dépend de l'orientation du robot
    case 1: //Z
      if (grid[bot->xpos][bot->ypos-1] != 'x' && !(bot->mat[bot->xpos][bot->ypos-1])) return 1;
          //Si il n'y a pas mur, ou que le robot n'a pas déja marqué sa matrice à ces coordonnées, renvoyer 1
    break;
    case 2: //Q
      if (grid[bot->xpos-1][bot->ypos] != 'x' && !(bot->mat[bot->xpos-1][bot->ypos])) return 1;
          //Si il n'y a pas mur, ou que le robot n'a pas déja marqué sa matrice à ces coordonnées, renvoyer 1
    break;
    case 3: //S
      if (grid[bot->xpos][bot->ypos+1] != 'x' && !(bot->mat[bot->xpos][bot->ypos+1])) return 1;
          //Si il n'y a pas mur, ou que le robot n'a pas déja marqué sa matrice à ces coordonnées, renvoyer 1
    break;
    case 4: //D
      if (grid[bot->xpos+1][bot->ypos] != 'x' && !(bot->mat[bot->xpos+1][bot->ypos])) return 1;
          //Si il n'y a pas mur, ou que le robot n'a pas déja marqué sa matrice à ces coordonnées, renvoyer 1
    break;
  }
  return 0; //Si il y a un mur, ou que le robot a déja marqué sa matrice à ces coordonnées, renvoyer 0
}

//==============================================================================
// Fonction : botRotate
// Rôle : Tourne le robot vers la droite ou la gauche
// Entrée : char rotation : 'l' left, ou 'r' right le sens de rotation
// Entrée/sortie : Robot *bot : (int bot->orient l'orientation du robot)
// Sortie : non
// Return : non
//==============================================================================

void botRotate(Robot *bot, char rotation){
  switch (rotation) {
    case 'l':
      bot->orient++; //Tourner le robot vers la gauche
      if (bot->orient == 5) bot->orient = 1; //Si la valeur dépasse la plage de valeur d'orientation, la faire "boucler"
    break;
    case 'r':
      bot->orient--; //Tourner le robot vers la droite
      if (bot->orient == 0) bot->orient = 4; //Si la valeur dépasse la plage de valeur d'orientation, la faire "boucler"
    break;
  }
}

//==============================================================================
// Fonction : moveRobot
// Rôle : Algorithme de déplacement du robot
// Entrée : char **grid : la matrice du labyrinthe
//          Robot *bot : le robot
//          Graph *surfaces : la structure de surfaces SDL
//          const int xgrid, const int ygrid : les dimensions du labyrinthe
// Entrée/sortie : int *count pointeur sur le compteur de l'algorithme de Pledge, l'entrée/sortie permet d'utiliser la boucle d'événement de la SDL
// Sortie : non
// Return : won : booléen : 1 si le robot est sorti, 0 sinon
//==============================================================================

char moveRobot(char **grid, Robot *bot, Graph *surfaces, const int xgrid, const int ygrid, int *count){
  int counter = *count; //On déréférence count dans une variable tampon
  char won = checkWin(grid, bot); //On vérifie si le Robot est à coté de la sortie
  char tempCheck; //Variable booléene tampon
  if (bot->xpos+2 > bot->xmat) resizeMatrix(bot, bot->xpos+2, bot->ymat); //Si la position du robot dépasse les dimensions de la matrice, l'agrandir
  if (bot->ypos+2 > bot->ymat) resizeMatrix(bot, bot->xmat, bot->ypos+2); //Si la position du robot dépasse les dimensions de la matrice, l'agrandir

  if(counter && !won) { //Etape 1 de l'algorithme de Pledge : suivre le mur
    botRotate(bot, 'l'); //Tourner le bot vers la gauche, pour vérifier s'il y a toujours le mur qu'on suivait
    if (!check(grid, bot)){ //Si il y a un mur à gauche
      markInMatrix(bot); //Marquer ce mur dans la matrice
      botRotate(bot, 'r'); //Se remettre en position initiale
      if(!step(grid, bot)){ //Si on peut avancer, et qu'il y a un mur à gauche : Avancer. Sinon :
        markInMatrix(bot);//Marquer le mur que l'on vient de rencontrer dans la matrice
        /*Etape : verification de la validité de la configuration des murs*/
        botRotate(bot, 'l');//Se retourner
        botRotate(bot, 'l');//Se retourner
        step(grid, bot);//Faire un pas
        botRotate(bot, 'l');//Se tourner vers le mur à vérifier
        tempCheck=check(grid, bot);//Pas de mur : tempCheck = 1
        botRotate(bot, 'l');
        step(grid, bot);//Revenir en place
        /*Etape : fin de laverification de la validité de la configuration des murs*/
        if (tempCheck) { //Si la configuration est valide
          bot->mat[bot->xpos][bot->ypos] = 1; //Marquer la position du robot : on n'y reviendra plus
        }

        botRotate(bot, 'r');//On n'a pas pu avancer, et on a un mur a gauche, il faut se tourner
        counter--;
        step(grid, bot);
      }
    }else{ //Pas de mur à gauche : il faut tourner à gauche et avancer pour suivre le mur
      counter++;
      step(grid, bot);
    }
    drawMove(surfaces, bot, grid, xgrid, ygrid, counter, bot->steps);//Dessiner le déplacement
  }
  if (!counter && !won) { //Etape 2 de l'algorithme de Pledge : aller tout droit jusqu'à rencontrer un mur
    if(!step(grid, bot)){//Un pas en avant si possible, sinon,
      markInMatrix(bot);//Marquer le mur que l'on vient de rencontrer
      botRotate(bot, 'r');
      counter--;
    }
    drawMove(surfaces, bot, grid, xgrid, ygrid, counter, bot->steps);//Dessiner le déplacement
  }
  *count = counter; //On fait sortir le compteur
  //displayMatrix(bot); //DEBUG
  return won;
}

//==============================================================================
// Fonction : resizeMatrix
// Rôle : Agrandissement de la matrice du robot, si nécéssaire
// Entrée : Robot *bot : le robot
//          const int newxmat, const int newymat: les nouvelles dimensions de la matrice à appliquer
// Entrée/sortie : non
// Sortie : non
// Return : non
//==============================================================================

void resizeMatrix(Robot *bot, const int newxmat, const int newymat){
  bot->mat = realloc(bot->mat,(size_t)(newxmat)*sizeof(char*)); //Agrandir la coordonnée x
  for (int x = 0; x < bot->xmat; x++) { //Pour toutes les colonnes
    bot->mat[x] = realloc(bot->mat[x],(size_t)(newymat)*sizeof(char));//Ajouter le nombre de lignes nécéssaire
  }
  for (int x = bot->xmat; x < newxmat; x++) { //Pour toutes les nouvelles colonnes
    bot->mat[x] = calloc((size_t)(newymat),sizeof(char)); //Les allouer en mettant leurs valeurs à 0
  }
  for (int y = bot->ymat; y < newymat; y++) {//Pour toutes les nouvelles lignes
    for (int x = 0; x < newxmat; x++) {//Les parcourir entièrement
      bot->mat[x][y]=0; //mettre leurs valeurs à 0
    }
  }
  bot->xmat = newxmat;
  bot->ymat = newymat;
  //printf("Resized matrix\n"); //DEBUG
}

//==============================================================================
// Fonction : markInMatrix
// Rôle : Marque un dans la matrice du robot à la position devant le robot : il ne passera plus ici
// Entrée : non
// Entrée/sortie :  Robot *bot : le robot (bot->mat : la matrice du robot)
// Sortie : non
// Return : non
//==============================================================================

void markInMatrix(Robot *bot){
  switch (bot->orient) { //En fonction de l'orientation du robot
    case 1: //Z
      bot->mat[bot->xpos][bot->ypos-1] = 1; //Marquer un 1 dans la matrice du robot, devant lui
    break;
    case 2: //Q
      bot->mat[bot->xpos-1][bot->ypos] = 1; //Marquer un 1 dans la matrice du robot, devant lui
    break;
    case 3: //S
      bot->mat[bot->xpos][bot->ypos+1] = 1; //Marquer un 1 dans la matrice du robot, devant lui
    break;
    case 4: //D
      bot->mat[bot->xpos+1][bot->ypos] = 1; //Marquer un 1 dans la matrice du robot, devant lui
    break;
  }
}

//==============================================================================
// Fonction : checkWin
// Rôle : Vérifie dans les 4 directions cardinales si le robot est à coté de la sortie (oui : 1, non : 0)
// Entrée : char **grid la matrice labyrinthe,
//          Robot *bot le robot (bot->xpos, bot->ypos sa position)
// Entrée/sortie : non
// Sortie : non
// Return : Si le robot est à coté de la sortie : 1, sinon 0
//==============================================================================

char checkWin(char **grid, Robot *bot){
  if (grid[bot->xpos][bot->ypos+1] == 'S' || grid[bot->xpos][bot->ypos-1] == 'S' || grid[bot->xpos+1][bot->ypos] == 'S' || grid[bot->xpos-1][bot->ypos] == 'S') {
          //On vérifie dans les 4 directions cardinales si le robot est à coté de la sortie
    return 1;
  }
  return 0;
}

//==============================================================================
// Fonction : displayMatrix
// Rôle : Affiche la matrice du robot
// Entrée : Robot *bot le robot (bot->mat sa matrice)
// Entrée/sortie : non
// Sortie : non
// Return : non
//==============================================================================

void displayMatrix(Robot *bot){
  for (int y = 0; y < bot->ymat; y++) {//Pour toutes les lignes
    for (int x = 0; x < bot->xmat; x++) {//Pour toutes les colonnes
      printf("%d", bot->mat[x][y]);
    }
    printf("\n");//Ligne terminée : retour à la ligne
  }
}
