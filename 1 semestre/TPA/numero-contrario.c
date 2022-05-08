#include <stdio.h>

// sempre tem que ter a main
int main(){
  int n, m, auxiliar;
  int C, U, D;
  printf("Digite n: ");
  scanf("%d", &n);
    C = n / 100; // primeiro dígito
    auxiliar = n % 100;
    U = auxiliar % 10;
    D = auxiliar / 10;
    
  //printf("%d", n);
 	m = (U * 100) + (D * 10) + C;
  printf("%d", m);

}
