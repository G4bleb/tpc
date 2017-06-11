#include "header.h"


Robot* startBot(char **grid, const int xgrid, const int ygrid){
  Robot *bot= malloc(sizeof(Robot));
  bot->orient=BOT_START;
  bot->steps=0;
  bot->mat=NULL;
  bot->xmat=0;
  bot->ymat=0;
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
      if (grid[bot->xpos][bot->ypos-1] != 'x' && !(bot->mat[bot->xpos][bot->ypos-1])) return 1;
    break;
    case 2: //Q
      if (grid[bot->xpos-1][bot->ypos] != 'x' && !(bot->mat[bot->xpos-1][bot->ypos])) return 1;
    break;
    case 3: //S
      if (grid[bot->xpos][bot->ypos+1] != 'x' && !(bot->mat[bot->xpos][bot->ypos+1])) return 1;
    break;
    case 4: //D
      if (grid[bot->xpos+1][bot->ypos] != 'x' && !(bot->mat[bot->xpos+1][bot->ypos])) return 1;
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
  char tempCheck;
  if (bot->xpos+2 > bot->xmat) resizeMatrix(bot, bot->xpos+2, bot->ymat);
  if (bot->ypos+2 > bot->ymat) resizeMatrix(bot, bot->xmat, bot->ypos+2);

  if(counter && !won && (*firstStepped)) {
    botRotate(bot, 'l'); //Mur à gauche ?
    if (!check(grid, bot)){ //Mur à gauche ?
      markInMatrix(bot);
      botRotate(bot, 'r');
      if(!step(grid, bot)){// Peut avancer, mur à gauche : Avancer
        markInMatrix(bot);

        botRotate(bot, 'r');
        step(grid, bot);
        botRotate(bot, 'r');
        tempCheck=check(grid, bot);
        botRotate(bot, 'r');
        step(grid, bot);
        botRotate(bot, 'r');
        if (tempCheck) {
          bot->mat[bot->xpos][bot->ypos] = 1;
        }

        botRotate(bot, 'r');//Peut pas go, mur à gauche
        counter--;
        step(grid, bot);
      }
    }else{ //Pas de mur à gauche
      counter++;
      step(grid, bot);
    }
    printf("Did 2ndStep\n");
    drawMove(surfaces, bot, grid, xgrid, ygrid, counter, bot->steps);
  }
  if ((!counter || !(*firstStepped)) && !won) {
    if(!step(grid, bot)){//Un pas en avant si possible, sinon,
      markInMatrix(bot);
      botRotate(bot, 'r');
      counter--;
      *firstStepped=1;
      printf("Finished 1stStep\n");
    }
    drawMove(surfaces, bot, grid, xgrid, ygrid, counter, bot->steps);
  }
  *count = counter;
  displayMatrix(bot);
  //getchar();
  //printf("bot->mat[bot->xpos][bot->ypos] est %d\n", bot->mat[bot->xpos][bot->ypos]);
  //fflush(stdout);
  //printf("counter = %d\n", counter);
  return won;
}

void resizeMatrix(Robot *bot, const int newxmat, const int newymat){
  bot->mat = realloc(bot->mat,(size_t)(newxmat)*sizeof(char*)); //agrandir le x
  for (int x = 0; x < bot->xmat; x++) {
    bot->mat[x] = realloc(bot->mat[x],(size_t)(newymat)*sizeof(char));
  }
  for (int x = bot->xmat; x < newxmat; x++) {
    bot->mat[x] = calloc((size_t)(newymat),sizeof(char)); //agrandir le y
  }
  for (int y = bot->ymat; y < newymat; y++) {
    for (int x = 0; x < newxmat; x++) {
      bot->mat[x][y]=0;
    }
  }
  bot->xmat = newxmat;
  bot->ymat = newymat;
  //printf("bot->mat[%d][%d] est %d/n", bot->xpos, bot->ypos,bot->mat[bot->xpos][bot->ypos]);
  printf("resized matrix\n");
}

void markInMatrix(Robot *bot){
  switch (bot->orient) {
    case 1: //Z
      bot->mat[bot->xpos][bot->ypos-1] = 1;
    break;
    case 2: //Q
      bot->mat[bot->xpos-1][bot->ypos] = 1;
    break;
    case 3: //S
      bot->mat[bot->xpos][bot->ypos+1] = 1;
    break;
    case 4: //D
      bot->mat[bot->xpos+1][bot->ypos] = 1;
    break;
  }
}

char checkWin(char **grid, Robot *bot){
  if (grid[bot->xpos][bot->ypos+1] == 'S' || grid[bot->xpos][bot->ypos-1] == 'S' || grid[bot->xpos+1][bot->ypos] == 'S' || grid[bot->xpos-1][bot->ypos] == 'S') {
    return 1;
  }
  return 0;
}

void displayMatrix(Robot *bot){
  for (int y = 0; y < bot->ymat; y++) {
    for (int x = 0; x < bot->xmat; x++) {
      printf("%d", bot->mat[x][y]);
    }
    printf("\n");
  }
  //getchar();
}
