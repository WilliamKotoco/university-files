/*
a ler um vetor com 500 posi��es e, em seguida, permitir que o
usu�rioescolha algumas opera��es:
Apresentar elementos em ordem crescente
Apresentar elementos em ordem decrescente
Imprimir todo o vetor
Imprimir as posi��es de um intervalo especificado pelo usu�rio
Digite <s> ou <S> para encerrar
*/
#include <stdio.h>
#include <stdlib.h>
#define posicoes 4 // o certo eh 500 mas to so testando
int main()
{
	int i, j, aux, vetor[posicoes], opcao, indice;
	for (i = 0; i < posicoes; i++)
	{
		vetor[i] = rand() % 500;
	}
	do
	{
		printf("\n Selecione uma opcao: ");
		printf("\n [0] para organizar em ordem crescente");
		printf("\n [1] para organizar em order descrescente");
		printf("\n [2] para imprimir o vetor ");
		printf("\n [3] para digitar um intervalo e imprimir o valor desse intervalo");
		printf("\n [4] para parar \n");

		scanf("%d", &opcao);
		if (opcao < 0 || opcao > 4)
		{
			printf("\n opção inválida!");
		}
		else
		{
			switch (opcao)
			{
			case 0:
				for (i = 0; i < posicoes; i++)
				{
					for (j = i + 1; j < posicoes; j++)
					{
						if (vetor[j] > vetor[i])
						{
							aux = vetor[i];
							vetor[i] = vetor[j];
							vetor[j] = aux;
						}
					}
				}
				printf("Organizado com sucesso!");
				break;
			case 1:
				for (i = 0; i < posicoes; i++)
				{
					for (j = i + 1; j < posicoes; j++)
					{
						if (vetor[j] < vetor[i])
						{
							aux = vetor[i];
							vetor[i] = vetor[j];
							vetor[j] = aux;
						}
					}
				}
				printf("Organizado com sucesso!"); break;
			case 2:
				for (i = 0; i < posicoes; i++)
				{
					printf("\n vetor[%d]", vetor[i]);
				}
				break;
			case 3:
				printf("Digite um indice: ");
				scanf("%d", &indice);
				printf("vetor[%d] eh %d", indice, vetor[indice]);
				break;
			}
		}
	} while (opcao != 4);

	return 0;
}
