#include "header.h"
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
