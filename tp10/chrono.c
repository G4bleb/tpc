/*

Programme produit le  par Gabriel LEBIS
*/
#include <stdio.h>
#include <unistd.h>
int main(){
  int i;
  for (i = 99; i >= 0; i--) {
    printf("%d\b\b", i);
    fflush(stdout);
    sleep(1);
  }
}
