#include<stdlib.h>
int main(){
	float kw = 0.1, total;
	int gasto, idade;
	
	// vamos, ficcionalmente, definir aposentado como > 65
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
	
	return 0;
}
