/*
a ler um vetor com 500 posições e, em seguida, permitir que o
usuárioescolha algumas operações:
Apresentar elementos em ordem crescente
Apresentar elementos em ordem decrescente
Imprimir todo o vetor
Imprimir as posições de um intervalo especificado pelo usuário
Digite <s> ou <S> para encerrar
*/
#include<stdio.h>
#include<stdlib.h>
#define posicoes 4 // o certo eh 500 mas to so testando
int main(){
	int i, vetor[max];
	for (i=0;i<max;i++){
		vetor[i] = rand() % 500;
			}
	return 0;
}
