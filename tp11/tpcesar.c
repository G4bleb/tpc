/*

Programme produit le  par Gabriel LEBIS
*/
#include <stdio.h>
#include <string.h>

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
  size_t long_texte = strlen(message_1_pc);
  char *code1_pc = malloc((long_texte+1)*sizeof(char));
  for (int i = 0; i < long_texte; i++) {
    code1_pc[i]=(lowerToUpper(message_1_pc[i])+key1_i);

  }
  code1_pc[i+1]='\0';
  return code1_pc;
}

int main(){
  /*Début partie 1*/
  char texte1_pc[] ="CeCI EsT uN BeaU MeSsAGE !";
  size_t long_texte = strlen(texte1_pc);
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
  printf("%s\n", lowupr);
  /*Fin partie 1*/

  int key1_i = 4;
  long_texte = strlen(message_1_pc);
  printf("Message 1 :\n\n%s size = %ld\n\n Key 1 :\n\n%d\n\n", message_1_pc, long_texte, key1_i);
  long_texte = strlen(message_1_pc);

  return 0;
}
