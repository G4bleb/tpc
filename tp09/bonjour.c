#include <stdio.h>
int main()
{
char nom[50];
printf ("Tapez votre nom :");
fgets (nom, 50, stdin);
printf ("bonjour %s\n", nom);
return 0;
}
