#include<stdlib.h>
#include<stdio.h>
int main() {
	int kwh, stop;
	float valor, aux;
	do {
	
	printf("digite o kwh: ");
	scanf("%f", &kwh);
	if (kwh < 50){
		valor = kwh;
	}
	else if (kwh > 50 && kwh < 100){
		valor = 50 + (kwh - 50)*1.30;
	}
	else if (kwh> 100 && kwh < 150){
		aux = 50 + (kwh*1.30);
		valor = aux + (kwh-)
	}
	printf("\n Digite 0 para parar, qualquer outra coisa para continuar ");
	scanf("%d", &stop);
}while(stop != 0);
}
