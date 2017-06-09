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

char step(char **grid, Robot *bot, Graph *surfaces){
  switch (bot->orient) {
    case 1: //Z
      if (check(grid, bot)) {
        reDrawAround(surfaces, bot, grid);
        grid[bot->xpos][bot->ypos]=' ';
        bot->ypos-=1;
        grid[bot->xpos][bot->ypos]='&';
        bot->steps++;
        return 1;
      }
    break;
    case 2: //Q
      if (check(grid, bot)) {
        reDrawAround(surfaces, bot, grid);
        grid[bot->xpos][bot->ypos]=' ';
        bot->xpos-=1;
        grid[bot->xpos][bot->ypos]='&';
        drawBot(surfaces->screen, bot, surfaces->botSprites);
        bot->steps++;
        return 2;
      }
    break;
    case 3: //S
      if (check(grid, bot)) {
        reDrawAround(surfaces, bot, grid);
        grid[bot->xpos][bot->ypos]=' ';
        bot->ypos+=1;
        grid[bot->xpos][bot->ypos]='&';
        drawBot(surfaces->screen, bot, surfaces->botSprites);
        bot->steps++;
        return 3;
      }
      break;
      case 4: //D
      if (check(grid, bot)) {
        reDrawAround(surfaces, bot, grid);
        grid[bot->xpos][bot->ypos]=' ';
        bot->xpos+=1;
        grid[bot->xpos][bot->ypos]='&';
        drawBot(surfaces->screen, bot, surfaces->botSprites);
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

char moveRobot(char **grid, Robot *bot, Graph *surfaces,const int xgrid, const int ygrid, int *count, char *firstStepped, const char graphMode){
  int counter = *count;
  char won = checkWin(grid, bot);
  if(!won && (*firstStepped)) {
    botRotate(bot, 'l'); //Mur à gauche ?
    if (!check(grid, bot)){ //Mur à gauche ?
      botRotate(bot, 'r');
      if(!step(grid, bot, surfaces)){// Peut avancer, mur à gauche : Avancer
        botRotate(bot, 'r');//Peut pas go, mur à gauche
        counter--;
        step(grid, bot, surfaces);
      }
    }else{ //Pas de mur à gauche
      counter++;
      step(grid, bot, surfaces);
    }
  drawMove(graphMode, surfaces, bot, grid, xgrid, ygrid, counter, bot->steps);
  }
  if ((!counter || !(*firstStepped)) && !won) {
    if(step(grid, bot, surfaces)){
    }else{
      botRotate(bot, 'r');
      counter--;
      *firstStepped=1;
      printf("did a firstStep\n");
    }
    drawMove(graphMode, surfaces, bot, grid, xgrid, ygrid, counter, bot->steps);
  }
  *count = counter;
  //printf("counter = %d\n", counter);
  return won;
}

char checkWin(char **grid, Robot *bot){
  if (grid[bot->xpos][bot->ypos+1] == 'S' || grid[bot->xpos][bot->ypos-1] == 'S' || grid[bot->xpos+1][bot->ypos+1] == 'S' || grid[bot->xpos-1][bot->ypos+1] == 'S') {
    return 1;
  }
  return 0;
}
