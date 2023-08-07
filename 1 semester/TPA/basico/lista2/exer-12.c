#include<stdlib.h>
int main(){
	int mesa, qtd, parar = 1, opcao;
	float conta = 0;
	do {
		printf("O que deseja pedir ? ");
		printf("\n[1] Refri ");
		printf("\n [2] Cerveja ");
		printf("\n [3] Pizza ");
		printf("\n [4] Almoco ");
		printf("\n [5] porcao ");
		scanf("%d", &opcao);
		if (opcao == 1){
			conta = conta + 2.5;
		}
		else if (opcao == 2){
			conta = conta + 4;
		}
		else if (opcao == 3 ){
			conta = conta + 47.3;
		}
		else if (opcao == 4){
			conta = conta + 15;
		}
		else{
			conta = conta + 10.5;
		}
		
		printf("Digite 1 para encerrar, 2 para outra coisa ? ");
		scanf("%d", &parar);
	} while(parar != 1);
	
	
	printf("A conta ficou no total de %f reais", conta);
	return 0;
}
