#include<stdlib.h>
int main(){
	int num;
	printf("digite o num: ");
	scanf("%d", &num);
	// primeiro metodo
	if (num%4 == 0) printf("divisivel")	;
	else printf("nao divisivel");
	
	// segundo metodo
	if((num/4) * 4 == num ) printf("\n divisiel outro metodo");
		return 0;
}
