int **initMatrice(char **grille, Robot *bot, const int coordx, const int coordy){
  int **mat = malloc((size_t)(coordx)*sizeof(int*));
  for (int x = 0; x < coordx; x++) {
    mat[x] = malloc((size_t)(coordy)*sizeof(int));
    //printf("chaine allouée\n");
  }
  for (int y = 0; y < coordy; y++) {
    for (int x = 0; x < coordx; x++) {
      if (grille[x][y]=='x') {
        mat[x][y]=2147483647;
      }else{
        mat[x][y]=0;
      }
    }
  }
  return mat;
}

void moveRobot(char **grille, Robot *bot, const int xgrille, const int ygrille){
  int counter = 0;
  char won = 0;
  int **mat = initMatrice(grille, bot, xgrille, ygrille);

  while (!won) {
    displayGrid(grille, xgrille, ygrille);
    printf("Counter = %d, Steps = %d\n",counter, bot->steps);
    getchar();
    won = checkWin(grille, bot);
    for (int i = 1; i < 5; i++) {
      if(check(grille, bot))increMat(grille, bot, mat);
      botRotate(bot, 'r');
    }
    while (bot->orient != lesserDirValue(bot)) {
      botRotate(bot, 'r');
    }
    step(grille, bot);
  }
  displayGrid(grille, xgrille, ygrille);
}

void increMat(char **grille, Robot *bot, int **mat){
  switch (bot->orient) {
    case 1: //Z
      mat[bot->xpos][bot->ypos-1]++;
      bot->haut=mat[bot->xpos][bot->ypos-1];
    break;
    case 2: //Q
      mat[bot->xpos-1][bot->ypos]++;
      bot->gauche=mat[bot->xpos-1][bot->ypos];
    break;
    case 3: //S
      mat[bot->xpos][bot->ypos+1]++;
      bot->bas=mat[bot->xpos][bot->ypos+1];
    break;
    case 4: //D
      mat[bot->xpos+1][bot->ypos]++;
      bot->droite=mat[bot->xpos+1][bot->ypos];
    break;
  }
}

int lesserDirValue(Robot *bot){
  int i = 1;
  int lesservalue = bot->haut;
  if (lesservalue < bot->gauche) {
    lesservalue=bot->gauche;
    i=2;
  }
  if (lesservalue < bot->bas) {
    lesservalue=bot->bas;
    i=3;
  }
  if (lesservalue < bot->droite) {
    lesservalue=bot->droite;
    i=4;
  }
  return i;
}
