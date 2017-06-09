char moveRobot(char **grille, Robot *bot, Graph *surfaces,const int xgrille, const int ygrille, int *count, char *firstStepped, const char graphMode);


main(){
  char graphMode = 1;
  int count = 0;
  char firstStepped = 0;
  moveRobot(grille, bot, surfaces,xgrille, ygrille, &count, &firstStepped, graphMode);
}

char moveRobot(char **grille, Robot *bot, Graph *surfaces,const int xgrille, const int ygrille, int *count, char *firstStepped, const char graphMode){
  int counter = *count;
  char won = checkWin(grille, bot);
  if(!won && firstStepped) {
    botRotate(bot, 'l'); //Mur à gauche ?
    if (!check(grille, bot)){ //Mur à gauche ?
      botRotate(bot, 'r');
      if(!step(grille, bot, surfaces)){// Peut avancer, mur à gauche : Avancer
        botRotate(bot, 'r');//Peut pas go, mur à gauche
        counter--;
        step(grille, bot, surfaces);
      }
    }else{ //Pas de mur à gauche
      counter++;
      step(grille, bot, surfaces);
    }
  drawMove(graphMode, surfaces, bot, grille, xgrille, ygrille);
  }
  if ((!counter || firstStepped) && !won) {
    if(step(grille, bot, surfaces)){
    }else{
      botRotate(bot, 'r');
      counter--;
    }
  }
  drawMove(graphMode, surfaces, bot, grille, xgrille, ygrille);
  *count = counter;
  return won;
}

void drawMove(const char graphMode, Graph *surfaces, Robot *bot, char **grille, const int xgrille, const int ygrille)){
  if (!graphMode) {
    displayGrid(grille, xgrille, ygrille);
    printf("Counter = %d, Steps = %d\n",counter, bot->steps);
  }else{
    reDrawAround(surfaces, bot, grille);
    drawBot(surfaces->screen, bot, surfaces->botSprites);
    SDL_Flip(surfaces->screen);
  }
  SDL_Delay(DELAY);
}
