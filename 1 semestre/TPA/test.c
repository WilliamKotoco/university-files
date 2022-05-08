#include <stdio.h>

// sempre tem que ter a main
int main(){
  float raio, area;
  printf("Digite o raio do circulo: ");
  scanf("%f", &raio);
  // o %f é para formatar  para float
  area = 3.141592 * raio * raio;
  printf("A area do circulo eh:%f",area);
    
  return 0;
}
