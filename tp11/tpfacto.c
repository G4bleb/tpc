/*

Programme produit le  par Gabriel LEBIS
*/
#include <stdio.h>
long long int factorielle(int n){
  if (n==0){
    return 1;
  }
  return n*factorielle(n-1);
}
int main(){
  for (int n = 1; n>0; n++) {
    printf("!%d : %lld\n", n,factorielle(n));
  }
  return 0;
}
