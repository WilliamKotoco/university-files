#include<stdlib.h>
#include<stdio.h>
int main(){
float dist, preco;
int opcao;

printf("quantos km de viagem: ");
scanf("%f", &dist);
printf("\n [1] para gasolina \t [2] para alcool e [3] para diesel: ");
scanf("%d", &opcao);

switch(opcao){
	case 1: 
		preco = dist*7.79;
		printf("com gasolina:  %f", preco);
		break;
	case 2:
		preco = dist*2.68;
		printf("com alcool:  %f", preco);
		break;
	case 3:
		preco = dist*2.64;
		printf("com diesel:  %f", preco);
		break;
	default: printf("valor invalido"); break;
}
	return 0;
}
