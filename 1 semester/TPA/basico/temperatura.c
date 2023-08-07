#include <stdio.h>

// sempre tem que ter a main
int main(){
  float temperatura_f, conversao;
  printf("Digite a temperatura em Fehreiemrnti: ");
  scanf("%f", &temperatura_f);
  conversao = (temperatura_f - 32) * 0.55 ;
  printf("A temperatura, em termos normais, eh de: %f", conversao);
    
  return 0;
}
