/*
Programme de cryptage/décryptage du code de César
Programme produit le 19/11/16 par Gabriel LEBIS
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define KEY3 4

int testUpperCase (char letter_c){
  if (65<=letter_c && letter_c<=90) {
    return 1;
  }else{
    return 0;
  }
}

char lowerToUpper(char letter_c){
  if (97<=letter_c && letter_c<=122) {
    return letter_c-32;
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
      code1_pc[i]=(message_1_pc[i]+key1_i);
      if (code1_pc[i]>90) {
        code1_pc[i]-=26;
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
      message_1_pc[i]=(code1_pc[i]-key1_i);
      if (message_1_pc[i]<65) {
        message_1_pc[i]+=26;
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
    freq[i]=(freq[i]/nmaj)*100;
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

int main(){
  size_t long_texte;

  printf("-----------------------PARTIE 1-----------------------\n\n");

  char texte1_pc[] ="CeCI EsT uN BeaU MeSsAGE !";
  long_texte = strlen(texte1_pc);
  int testupper[long_texte];
  printf("Text 1 :\n\n%s  size = %ld\n", texte1_pc, long_texte);
  for (int i = 0; i < long_texte; i++) {
    testupper[i]=testUpperCase(texte1_pc[i]);
    printf("%d", testupper[i]);
  }
  printf("\n\n");
  char texte2_pc[]="Ave Caesar morituri te salutant !";
  long_texte = strlen(texte2_pc);
  char lowupr[long_texte];
  printf("Text 2 :\n\n%s  size = %ld\n", texte2_pc, long_texte);
  for (int i = 0; i < long_texte+1; i++) {
    lowupr[i]=lowerToUpper(texte2_pc[i]);
  }
  printf("%s\n\n", lowupr);

  printf("-----------------------PARTIE 2-----------------------\n\n");

  int key1_i = 3;
  char message_1_pc[] = "VERCINGETORIX";
  long_texte = strlen(message_1_pc);
  printf("Message 1 :\n\n%s size = %ld\n\nKey 1 :\n\n%d\n\n", message_1_pc, long_texte, key1_i);
  char *code1_pc = encryption(message_1_pc, key1_i);
  long_texte = strlen(code1_pc);
  printf("Code 1 :\n\n%s size = %ld\n\n", code1_pc, long_texte);
  int key2_i = 20;
  char message_2_pc[] = "En l'occurrence l'imbecillite est un dilemme etymologique !";
  long_texte = strlen(message_2_pc);
  printf("Message 2 :\n\n%s size = %ld\n\nKey 2 :\n\n%d\n\n", message_2_pc, long_texte, key2_i);
  char *code2_pc = encryption(message_2_pc, key2_i);
  long_texte = strlen(code2_pc);
  printf("Code 2 :\n\n%s size = %ld\n\n", code2_pc, long_texte);

  printf("-----------------------PARTIE 3-----------------------\n\n");//attention les parties 2&3 "communiquent" entre elles

  char *decode1_pc = decryption(code1_pc, key1_i);
  long_texte = strlen(decode1_pc);
  printf("Decode 1 :\n\n%s size = %ld\n\n", decode1_pc, long_texte);
  char *decode2_pc = decryption(code2_pc, key2_i);
  long_texte = strlen(decode2_pc);
  printf("Decode 2 :\n\n%s size = %ld\n\n", decode2_pc, long_texte);

  printf("-----------------------Dernière Partie-----------------------\n\n");

  char texte3_pc[] = "Depuis longtemps, j'ai la manie de glisser des jeux de mots lors des conversations. Les gens de mon entourage ne pouvant plus me supporter, je me suis mis a les ecrire. Lorsque je suis entre a l'Ecole Polytechnique de Montreal, j'ai eu l'occasion d'ecrire une chronique hebdomadaire dans le journal etudiant, le Polyscope. Ce sont ces textes qui se retrouvent dans le present recueil.";
  printf("Texte 3 : \n\n%s\n\n", texte3_pc);
  //char *code3_pc = encryption(texte3_pc, KEY3);
  char code3_pc[] ="ZNVGER PBEORNH, FHE HA NEOER CREPUR, GRANVG RA FBA ORP HA SEBZNTR. ZNVGER ERANEQ CNE Y'BQRHE NYYRPUR, YHV GVAG N CRH CERF PR YNATNTR : RG OBAWBHE ZBAFVRHE QH PBEORNH. DHR IBHF RGRF WBYV! DHR IBHF ZR FRZOYRM ORNH! FNAF ZRAGVE, FV IBGER ENZNTR FR ENCCBEGR N IBGER CYHZNTR IBHF RGRF YR CURAVK QRF UBGRF QR PRF OBVF. N PRF ZBGF YR PBEORNH AR FR FRAG CNF QR WBVR; RG CBHE ZBAGERE FN ORYYR IBVK, VY BHIER HA YNETR ORP YNVFFR GBZORE FN CEBVR. YR ERANEQ F'RA FNVFVG RG QVG : ZBA OBA ZBAFVRHE, NCERARM DHR GBHG SYNGGRHE IVG NH QRCRAF QR PRYHV DHV Y'RPBHGR : PRGGR YRPBA INHG OVRA HA SEBZNTR FNAF QBHGR. YR PBEORNH UBAGRHK RG PBASHF WHEN ZNVF HA CRH CYHF GNEQ, DH'BA AR Y'L CERAQENVG CYHF.";
  printf("Code 3 : \n\n%s\n\n", code3_pc);
  printfreq(freqAnalysis(code3_pc));
  int key3_i=computeKey(freqAnalysis(code3_pc));
  printf("\n\nClé : %d\n\n", key3_i);
  printf("Decode 3 :\n\n%s\n\n", decryption(code3_pc, key3_i));

  return 0;
}
