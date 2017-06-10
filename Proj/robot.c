#include "header.h"


Robot* startBot(char **grid, const int xgrid, const int ygrid){
  Robot *bot= malloc(sizeof(Robot));
  bot->orient=BOT_START;
  bot->steps=0;
  int x = 0, y = 0;
  char botPlaced =0;
  for (y = 0; (y < ygrid) && (!botPlaced); y++) {
    for (x = 0; (x < xgrid) && (!botPlaced); x++) {
      if (grid[x][y] == 'D') {
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
  grid[bot->xpos][bot->ypos]='&';
  return bot;
}

char step(char **grid, Robot *bot){
  bot->oldx = bot->xpos;
  bot->oldy = bot->ypos;
  switch (bot->orient) {
    case 1: //Z
      if (check(grid, bot)) {
        grid[bot->xpos][bot->ypos]=' ';
        bot->ypos-=1;
        grid[bot->xpos][bot->ypos]='&';
        bot->steps++;
        return 1;
      }
    break;
    case 2: //Q
      if (check(grid, bot)) {
        grid[bot->xpos][bot->ypos]=' ';
        bot->xpos-=1;
        grid[bot->xpos][bot->ypos]='&';
        bot->steps++;
        return 2;
      }
    break;
    case 3: //S
      if (check(grid, bot)) {
        grid[bot->xpos][bot->ypos]=' ';
        bot->ypos+=1;
        grid[bot->xpos][bot->ypos]='&';
        bot->steps++;
        return 3;
      }
      break;
      case 4: //D
      if (check(grid, bot)) {
        grid[bot->xpos][bot->ypos]=' ';
        bot->xpos+=1;
        grid[bot->xpos][bot->ypos]='&';
        bot->steps++;
        return 4;
      }
      break;
  }
  return 0;
}

char check(char **grid, Robot *bot){
  switch (bot->orient) {
    case 1: //Z
      if (grid[bot->xpos][bot->ypos-1] != 'x') return 1;
    break;
    case 2: //Q
      if (grid[bot->xpos-1][bot->ypos] != 'x') return 1;
    break;
    case 3: //S
      if (grid[bot->xpos][bot->ypos+1] != 'x') return 1;
    break;
    case 4: //D
      if (grid[bot->xpos+1][bot->ypos] != 'x') return 1;
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

char moveRobot(char **grid, Robot *bot, Graph *surfaces,const int xgrid, const int ygrid, int *count, char *firstStepped){
  int counter = *count;
  char won = checkWin(grid, bot);
  if(!won && (*firstStepped)) {
    if (rand()%MAX_RAND && bot->steps>RANDOM_START) {
      botRotate(bot, 'r');
    }
    botRotate(bot, 'l'); //Mur à gauche ?
    if (!check(grid, bot)){ //Mur à gauche ?
      botRotate(bot, 'r');
      if(!step(grid, bot)){// Peut avancer, mur à gauche : Avancer
        botRotate(bot, 'r');//Peut pas go, mur à gauche
        counter--;
        step(grid, bot);
      }
    }else{ //Pas de mur à gauche
      counter++;
      step(grid, bot);
    }
  drawMove(surfaces, bot, grid, xgrid, ygrid, counter, bot->steps);
  }
  if ((!counter || !(*firstStepped)) && !won) {
    if(step(grid, bot)){
    }else{
      botRotate(bot, 'r');
      counter--;
      *firstStepped=1;
      //printf("did a firstStep\n");
    }
    drawMove(surfaces, bot, grid, xgrid, ygrid, counter, bot->steps);
  }
  *count = counter;
  //printf("counter = %d\n", counter);
  return won;
}

char checkWin(char **grid, Robot *bot){
  if (grid[bot->xpos][bot->ypos+1] == 'S' || grid[bot->xpos][bot->ypos-1] == 'S' || grid[bot->xpos+1][bot->ypos] == 'S' || grid[bot->xpos-1][bot->ypos] == 'S') {
    return 1;
  }
  return 0;
}
