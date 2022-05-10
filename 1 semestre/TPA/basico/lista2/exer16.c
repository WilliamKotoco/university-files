#include<stdlib.h>
int main(){
	int  salarioBruto, horas;
	float salarioLiquido, valorHoras;
	
	
	printf("Digite o salario bruto: ");
	scanf("%d", &salarioBruto);
	printf("\n Digite a quantidade de horas extras : ");
	scanf("%d", &horas);
	printf("\n Digite o valor de cada hora extra: ");
	scanf("%f", &valorHoras);
	
	salarioLiquido = (salarioBruto + (horas * valorHoras)) - 8/100;
	printf("O salário liquido eh: %f", salarioLiquido);
	return 0;
}
