#include "header.h"


Robot* startBot(char **grille, const int xgrille, const int ygrille){
  Robot *bot= malloc(sizeof(Robot));
  bot->orient=BOT_START;
  bot->steps=0;
  int x = 0, y = 0;
  char botPlaced =0;
  for (y = 0; (y < ygrille) && (!botPlaced); y++) {
    for (x = 0; (x < xgrille) && (!botPlaced); x++) {
      if (grille[x][y] == 'D') {
        bot->xpos = x;
        bot->ypos = y;
        botPlaced = 1;
      }
    }
  }
  if (!botPlaced) {
    printf("Erreur de placement du Robot\n");
    return NULL;
  }
  grille[bot->xpos][bot->ypos]='&';
  return bot;
}

char step(char **grille, Robot *bot){
  switch (bot->orient) {
    case 1: //Z
      if (check(grille, bot)) {
        grille[bot->xpos][bot->ypos]=' ';
        bot->ypos-=1;
        grille[bot->xpos][bot->ypos]='&';
        bot->steps++;
        return 1;
      }
    break;
    case 2: //Q
      if (check(grille, bot)) {
        grille[bot->xpos][bot->ypos]=' ';
        bot->xpos-=1;
        grille[bot->xpos][bot->ypos]='&';
        bot->steps++;
        return 2;
      }
    break;
    case 3: //S
      if (check(grille, bot)) {
        grille[bot->xpos][bot->ypos]=' ';
        bot->ypos+=1;
        grille[bot->xpos][bot->ypos]='&';
        bot->steps++;
        return 3;
      }
      break;
      case 4: //D
      if (check(grille, bot)) {
        grille[bot->xpos][bot->ypos]=' ';
        bot->xpos+=1;
        grille[bot->xpos][bot->ypos]='&';
        bot->steps++;
        return 4;
      }
      break;
  }
  return 0;
}

char check(char **grille, Robot *bot){
  switch (bot->orient) {
    case 1: //Z
      if (grille[bot->xpos][bot->ypos-1] != 'x') return 1;
    break;
    case 2: //Q
      if (grille[bot->xpos-1][bot->ypos] != 'x') return 1;
    break;
    case 3: //S
      if (grille[bot->xpos][bot->ypos+1] != 'x') return 1;
    break;
    case 4: //D
      if (grille[bot->xpos+1][bot->ypos] != 'x') return 1;
    break;
  }
  return 0;
}

void botRotate(Robot *bot, char rotation){
  switch (rotation) {
    case 'l':
      bot->orient++;
      if (bot->orient == 5) bot->orient = 1;
    break;
    case 'r':
      bot->orient--;
      if (bot->orient == 0) bot->orient = 4;
    break;
  }
}

void moveRobot(char **grille, Robot *bot, Graph *surfaces,const int xgrille, const int ygrille){
  int counter = 0;
  char won = 0;
  printf("yoyo\n");
  while(step(grille, bot)){
    //getchar();
    SDL_Delay(250);
    drawWindow(surfaces, bot, grille, xgrille, ygrille);
  }
  botRotate(bot, 'r');
  counter--;

  while (!won) {
    //displayGrid(grille, xgrille, ygrille);
    //drawBot(ecran, bot, botSprites);
    SDL_Delay(100);
    drawWindow(surfaces, bot, grille, xgrille, ygrille);
    printf("Counter = %d, Steps = %d\n",counter, bot->steps);
    //getchar(); TOREMOVE
    won = checkWin(grille, bot);
    botRotate(bot, 'l'); //Mur à gauche
    if (!check(grille, bot)){ //Mur à gauche
      botRotate(bot, 'r');
      if(!step(grille, bot)){// Peut avancer, mur à gauche : Avancer
        botRotate(bot, 'r');//Peut pas go, mur à gauche
        counter--;
        step(grille, bot);
      }
    }else{ //Pas de mur à gauche
      counter++;
      step(grille, bot);
    }

    if (!counter) {
      while(step(grille, bot)){
      //getchar(); //TOREMOVE
      SDL_Delay(100);
      //displayGrid(grille, xgrille, ygrille);  //TOREMOVE
      drawWindow(surfaces, bot, grille, xgrille, ygrille);
      //drawBot(ecran, bot, botSprites);
      }
      botRotate(bot, 'r');
      counter--;
    }
  }
  //displayGrid(grille, xgrille, ygrille);
}

char checkWin(char **grille, Robot *bot){
  if (grille[bot->xpos][bot->ypos+1] == 'S' || grille[bot->xpos][bot->ypos-1] == 'S' || grille[bot->xpos+1][bot->ypos+1] == 'S' || grille[bot->xpos-1][bot->ypos+1] == 'S') {
    return 1;
  }
  return 0;
}
