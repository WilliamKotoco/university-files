// procurar um elemento em um vetor de n elementos. Retornar -1 se não existe, se existir retornar o indice
#include <stdio.h>
int search_element(int *vetor, int elemento, int tamanho);
int main()
{
	const int tamanho = 10;
	int vetor[tamanho], i, elemento;
	for (i = 0; i < tamanho; i++)
	{
		vetor[i] = rand() % 10;
		printf(" %d  ", vetor[i]);
	}
	printf("\n");
	scanf("%d", &elemento);
	printf("%d", search_element(vetor, elemento, tamanho));
	return 0;
}
int search_element(int *vetor, int elemento, int tamanho)
{
	// para procurar, comparar o elemento com um indice e depois com o indice seguinte ate esgotar tudo
	if (tamanho == 0)
		return -1;
	else
	{
		if (vetor[tamanho] == elemento)
			return tamanho;
		else
		{
			return search_element(vetor, elemento, tamanho - 1);
		}
	}
}
