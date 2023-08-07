/*
Escreva um programa para simular as operações de uma pilha (First in last out - FILO), com 10
posições.

 O primeiro elemento a ser empilhado é o último a ser retirado da pilha.
  Este tipo de
estrutura é comumente utilizado para gerenciar chamadas de funções, por exemplo. O programa
deve ter as operações de inserção e remoção. O processo de remoção não é físico. Uma remoção
deve ser controlada por uma indicação lógica.
*/
#include<stdio.h>
#include<stdlib.h>
int main(){
	int i, opcao, num, vetor[10];
	for (i = 0; i<10; i++){
		printf("Digite um numero: ");
		scanf("%d", &num);
		vetor[i] = num;
	}
	printf("\n Entradas: ");
		for(i = 0; i<10; i++){
		printf("\t %d ", vetor[i]);
	}
	
	while (1){
		printf("\n Digite 1 para remover o ultimo elemento, qualquer outro numero para nao fazer nada: ");
		scanf("%d", &opcao);
		if (opcao == 1){
			printf("\n Elemento %d removido", vetor[9]);
			break;
		}
		else{
			printf("\n Nada foi feito");
			break;
		}
	}

	//	vetor[10] = "\0";
	/* printf("\n Saidas: ");
	for(i = 9; i >= 0; i--){
		printf("\t %d",vetor[i]);
	} */
	return 0;
}





