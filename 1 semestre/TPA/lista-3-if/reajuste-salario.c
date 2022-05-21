#include<stdlib.h>
int main() {
	float sal, newsal;
	printf("Digite o salario: ");
	scanf("%f", &sal);
	if (sal < 500){
		newsal = sal + (sal * 0.15);
		printf("\n sera rejustado em 15%");
	}
	else if(sal > 500 && sal < 1001){
		printf("\n sera reajustado em 10% ");
		newsal = sal + (sal*0.1);
	}
	else{
		printf("\n sera reajustado em 5%");
		newsal = sal + (sal*0.05);
	}
	printf("\n novo salario: %f ", newsal);
	return 0;
}
