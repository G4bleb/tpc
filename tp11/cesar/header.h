/*
Programme de cryptage/décryptage du code de César
Programme produit le 19/11/16 par Gabriel LEBIS
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define KEY3 4
int testUpperCase (char letter_c);
char lowerToUpper(char letter_c);
char *encryption(char *message_1_pc, int key1_i);
char *decryption(const char *code1_pc, int key1_i);
float *freqAnalysis(const char *texte1_pc);
void printfreq(const float *freq);
int computeKey(const float *freq);
