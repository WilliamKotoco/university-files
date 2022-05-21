#include<stdlib.h>
int main(){
	int sexo;
	printf("Digite [1] para masculino, [2] para feminino: ");
	scanf("%d", &sexo);
	
	switch(sexo){
		case 1: 
			printf("\n masculino"); break;
		case 2: 
			printf("\n feminino"); break;
		default: printf("\n sexo invalido");
	}
	
		
	return 0;
}
