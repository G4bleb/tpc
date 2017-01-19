/*
Fonction puissance
Programme produit le 7/11/2016 par Gabriel LEBIS
*/
#include <stdio.h>

double puissance(double x, int n){
  double z = x;
  for (int i=1;i<n;i++){
    x *= z;
  }
  return x;
}

int main(){
  double x;
  int n;
  printf("x ?\n");
  scanf("%lf", &x);
  printf("puissance ?\n");
  scanf("%d",&n);
  printf("%lf\n", puissance(x,n));
  return 0;
}
