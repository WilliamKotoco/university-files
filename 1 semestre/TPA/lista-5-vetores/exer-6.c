/* Escreva um programa para simular as operações de uma fila (FIFO), ou seja, o primeiro elemento
a entrar na fila é o primeiro a ser retirado da fila. O programa deve permitir uma fila com 10
posições. Uma lista FIFO é comumente utilizada para gerenciar processos em que a ordem de
chegada é a que deve ser utilizada para o atendimento, por exemplo, como ocorre em uma fila de
impressão. O programa deve ter as operações de inserção e remoção. O processo de remoção não é
físico. Uma remoção deve ser controlada por uma indicação lógica. */
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
			printf("\n Elemento %d removido", vetor[0]);
			break;
		}
		else{
			printf("\n Nada foi feito");
			break;
		}
	}
	
	return 0;	
}
