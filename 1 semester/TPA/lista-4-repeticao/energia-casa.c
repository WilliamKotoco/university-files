#include<stdlib.h>
#include<stdio.h>
int main(){
	float kw = 0.1, total;
	int gasto, idade, stop;
	
	// vamos, ficcionalmente, definir aposentado como > 65
	
	do {
		printf("Digite o gasto em kw: ");
	scanf("%d", &gasto);
	printf("\n Digite a idade: ");
	scanf("%d", &idade);
	total = gasto*kw;
	if (idade > 65){
		total = total - (total*0.15);
		printf("Total com desconto: %f", total);
	}
	else
		printf("total gasto, sem desconto: %f", total);
		
	printf("\n Digite 0 para parar, qualquer outra coisa para continuar ");
	scanf("%d", &stop);
	}while(stop != 0);
	return 0;
}
