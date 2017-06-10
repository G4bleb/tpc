void resizeMatrix(Robot *bot, const int newxmat, const int newymat){
  bot->mat = realloc(bot->mat,(size_t)(newxmat)*sizeof(char*));
  for (int x = 0; x < bot->xmat; x++) {
    bot->mat[x] = realloc(bot->mat,(size_t)(newymat)*sizeof(char));
  }
  for (int y = bot->xmat; y < newymat; y++) {
    for (int x = bot->ymat; x < newxmat; x++) {
      bot->mat[x][y]=0;
    }
  }
  bot->xmat = newxmat;
  bot->ymat = newymat;
}

char moveRobot(char **grid, Robot *bot, Graph *surfaces,const int xgrid, const int ygrid, int *count, char *firstStepped){
  int counter = *count;
  char won = checkWin(grid, bot);
  if(!won && (*firstStepped)) {
    botRotate(bot, 'l'); //Mur à gauche ?
    if (!check(grid, bot)){ //Mur à gauche ?
      markInMatrix(bot);
      botRotate(bot, 'r');
      if(!step(grid, bot)){// Peut avancer, mur à gauche : Avancer
        markInMatrix(bot);
        bot->mat[bot->xpos][bot->ypos] = 1;
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
    if(!step(grid, bot)){//Un pas en avant si possible, sinon,
      markInMatrix(bot);
      botRotate(bot, 'r');
      counter--;
      *firstStepped=1;
    }
    drawMove(surfaces, bot, grid, xgrid, ygrid, counter, bot->steps);
  }
  *count = counter;
  //printf("counter = %d\n", counter);
  return won;
}

char check(char **grid, Robot *bot){
  switch (bot->orient) {
    case 1: //Z
      if (grid[bot->xpos][bot->ypos-1] != 'x' || !bot->mat[bot->xpos][bot->ypos-1]) return 1;
    break;
    case 2: //Q
      if (grid[bot->xpos-1][bot->ypos] != 'x' || !bot->mat[bot->xpos-1][bot->ypos]) return 1;
    break;
    case 3: //S
      if (grid[bot->xpos][bot->ypos+1] != 'x' || !bot->mat[bot->xpos][bot->ypos+1]) return 1;
    break;
    case 4: //D
      if (grid[bot->xpos+1][bot->ypos] != 'x' || !bot->mat[bot->xpos+1][bot->ypos]) return 1;
    break;
  }
  return 0;
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
      if (bot->ypos+1 < bot->ymat) {
        resizeMatrix(bot, bot->xmat, bot->ypos+1);
      }
      bot->mat[bot->xpos][bot->ypos+1] = 1;
    break;
    case 4: //D
      if (bot->xpos+1 < bot->xmat) {
        resizeMatrix(bot, bot->xpos+1, bot->ymat);
      }
      bot->mat[bot->xpos+1][bot->ypos] = 1;
    break;
  }
}
