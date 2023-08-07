#include<stdlib.h>
int main() {
float peso, altura, imc;
printf("digite o peso em kg: ");
scanf("%f", &peso);
printf("\n digite a altura: ");
scanf("%f", &altura);

imc = peso/(altura*altura);
printf("\n imc %f ", imc);

return 0;
}
