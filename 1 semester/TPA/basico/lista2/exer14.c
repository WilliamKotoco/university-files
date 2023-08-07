#include<stdlib.h>
int main(){
	int salario, porcentagem;
	float aumento;

	printf("\nDigite o salario: ");
	scanf("%d", &salario);
	printf("\nDigite a porcentagem de aumento: ");
	scanf("%d", &porcentagem);
	
	aumento = salario + (salario * porcentagem/100);
	printf("O aumento foi de %f ", aumento);
	
	
	
	return 0;
	}
