#include<stdlib.h>
int main(){
	int num;
	printf("Digite o numero: ");
	scanf("%d", &num);
	if (num > 0)
		printf("\n e positivo");
	else if(num<0)
		printf("\n e negativo");
	else
		printf("o numero eh 0");
	
	return 0;
}
