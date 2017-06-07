#include "header.h"


Robot* startBot(char **grille, const int xgrille, const int ygrille){
  Robot *bot= malloc(sizeof(Robot));
  bot->orient=BOT_START;
  int x = 0, y = 0;
  for (y = 0; (y < ygrille); y++) {
    for (x = 0; (x < xgrille); x++) {
      if (grille[x][y] == 'D') {
        bot->xpos = x;
        bot->ypos = y;
        break;
      }
    }
  }
  grille[bot->xpos][bot->ypos]='&';
  return bot;
}

char step(char **grille, Robot *bot, char mov){
  if (mov==1) { //Z
    if (check(grille, bot, mov)) {
      grille[bot->xpos][bot->ypos]=' ';
      bot->ypos-=1;
      grille[bot->xpos][bot->ypos]='&';
      return 1;
    }
  }
  if (mov==2) { //Q
    if (check(grille, bot, mov)) {
      grille[bot->xpos][bot->ypos]=' ';
      bot->xpos-=1;
      grille[bot->xpos][bot->ypos]='&';
      return 2;
    }
  }
  if (mov==3) { //S
    if (check(grille, bot, mov)) {
      grille[bot->xpos][bot->ypos]=' ';
      bot->ypos+=1;
      grille[bot->xpos][bot->ypos]='&';
      return 3;
    }
  }
  if (mov==4) { //D
    if (check(grille, bot, mov)) {
      grille[bot->xpos][bot->ypos]=' ';
      bot->xpos+=1;
      grille[bot->xpos][bot->ypos]='&';
      return 4;
    }
  }
  return 0;
}

char check(char **grille, Robot *bot, char mov){
  if (mov==1) { //Z
    if (grille[bot->xpos][bot->ypos-1] != 'x') {
      return 1;
    }
  }
  if (mov==2) { //Q
    if (grille[bot->xpos-1][bot->ypos] != 'x') {
      return 1;
    }
  }
  if (mov==3) { //S
    if (grille[bot->xpos][bot->ypos+1] != 'x') {
      return 1;
    }
  }
  if (mov==4) { //D
    if (grille[bot->xpos+1][bot->ypos] != 'x') {
      return 1;
    }
  }
  return 0;
}

void botRotate(Robot *bot, char rotation){
  if (rotation == 'r') {
    bot->orient+=1;
    if (bot->orient == 5) bot->orient = 1;
  }
  if (rotation == 'l') {
    bot->orient-=1;
    if (bot->orient == 0) bot->orient = 4;
  }
}

void moveRobot(char **grille, Robot *bot, const int xgrille, const int ygrille){
  int counter = 0;
  char won = 0;

  while(step(grille, bot, bot->orient));
  botRotate(bot, 'r');
  counter--;

  while (!won) {
    displayGrid(grille, xgrille, ygrille);
    printf("%d\n",counter);
    getchar();
    won = checkWin(grille, bot);
    botRotate(bot, 'l'); //Mur à gauche
    if (!check(grille, bot, bot->orient)){ //Mur à gauche
      botRotate(bot, 'r');
      if(!step(grille, bot, bot->orient)){// Peut avancer, mur à gauche : Avancer
        botRotate(bot, 'r');//Peut pas go, mur à gauche
        counter--;
        step(grille, bot, bot->orient);
      }
    }else{ //Pas de mur à gauche
      counter++;
      step(grille, bot, bot->orient);
    }

    if (!counter) {
      while(step(grille, bot, bot->orient));
      botRotate(bot, 'r');
      counter--;
    }
  }
  displayGrid(grille, xgrille, ygrille);
}

char checkWin(char **grille, Robot *bot){
  if (grille[bot->xpos][bot->ypos+1] == 'S' || grille[bot->xpos][bot->ypos-1] == 'S' || grille[bot->xpos+1][bot->ypos+1] == 'S' || grille[bot->xpos-1][bot->ypos+1] == 'S') {
    return 1;
  }
  return 0;
}
