#include "header.h"
int testUpperCase (char letter_c){
  if (65<=letter_c && letter_c<=90) {
    return 1;
  }else{
    return 0;
  }
}

char lowerToUpper(char letter_c){
  if (97<=letter_c && letter_c<=122) {
    return (char)(letter_c-32);
  }else{
    return letter_c;
  }
}

char *encryption(char *message_1_pc, int key1_i){
  int i;
  size_t long_texte = strlen(message_1_pc);
  for (i = 0; i < long_texte+1; i++) {
    message_1_pc[i]=lowerToUpper(message_1_pc[i]);
  }
  char *code1_pc = malloc((long_texte+1)*sizeof(char));
  for (i = 0; i < long_texte; i++) {
    if (testUpperCase(message_1_pc[i])) {
      code1_pc[i]=(char)(message_1_pc[i]+key1_i);
      if (code1_pc[i]>90) {
        code1_pc[i]=(char)(code1_pc[i]-26);
      }
    }else{
      code1_pc[i]=(message_1_pc[i]);
    }
  }
  code1_pc[long_texte+1]='\0';
  return code1_pc;
}

char *decryption(const char *code1_pc, int key1_i){
  int i;
  size_t long_texte = strlen(code1_pc);
  char *message_1_pc = malloc((long_texte+1)*sizeof(char));
  for (i = 0; i < long_texte; i++) {
    if (testUpperCase(code1_pc[i])) {
      message_1_pc[i]=(char)(code1_pc[i]-key1_i);
      if (message_1_pc[i]<65) {
        message_1_pc[i]=(char)(message_1_pc[i]+26);
      }
    }else{
      message_1_pc[i]=(code1_pc[i]);
    }
  }
  message_1_pc[long_texte+1]='\0';
  return message_1_pc;
}

float *freqAnalysis(const char *texte1_pc){
  int i;
  int nmaj=0;
  size_t long_texte = strlen(texte1_pc);
  float *freq = calloc(26,sizeof(float)); //calloc = malloc, mais écrit 0 sur tous les éléments du tableau (Clear memory ALLOCation)
  for (i = 0; i < long_texte; i++) {
    if (testUpperCase(texte1_pc[i])) {
      nmaj++;
      freq[texte1_pc[i]-65]+=1;
    }
  }
  for (i = 0; i < 26; i++) {
    freq[i]=(freq[i]/(float)nmaj)*100;
  }
  return freq;
}

void printfreq(const float *freq){
  int i;
  for (i = 0; i < 26; i++) {
    printf("%3.1f\t", freq[i]);
  }
}

int computeKey(const float *freq){
  int i, key=0, j=0;
  for (i = 1; i < 26; i++){
    if (freq[i]>freq[j]) {
      j=i;
    }
  }
  if (j<4) {
    key = j+22;
  }
  if (j>4) {
    key = j-4;
  }
  return key;
}
