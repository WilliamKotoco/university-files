#include<stdlib.h>
#include<stdio.h>
int main() {
	float preco;
	int quantidade;
	char nome[40] ;
	printf("Digite o nome do produto: ");
	scanf("%s", &nome);
	printf("\nDigite o preco do produto: ");
	scanf("%f", &preco);
	printf("\n Digite a quantidade comprada: ");
	scanf("%d", &quantidade);
	
	 if(quantidade >10 && quantidade < 20)
	 {
		preco = preco - (preco*0.1);
	
	}
	else if(quantidade > 20 && quantidade < 51 )
	{
		preco = preco - (preco*0.2);
	}
	else if(quantidade > 50)
	{
		preco = preco - (preco*0.25);
	}
	printf("\nComprado: %s", nome);
	printf("\nTotal: %f ", preco);
	
	return 0;
}
