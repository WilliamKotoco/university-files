#include<stdlib.h>

int main (){
	int num;
	printf("Digite um numero: ");
	scanf("%d", &num);
	
	if (num > 20 && num < 100)
	printf("\n numero dentro do intervalo definido");
	else
	printf("\n numero fora do intervalo");
	return 0;
}
