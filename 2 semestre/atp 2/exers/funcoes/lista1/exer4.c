//  Faça uma função recursiva que permita somar os elementos de um vetor de
// inteiros.
#include <stdio.h>
int soma_vetores(int *vetor, int tamanho);
int main()
{
    int tamanho = 10;
    int i, vetor[tamanho], soma;
    for (i = 0; i < tamanho; i++)
    {
        printf("digite num \n");
        scanf("%d", &vetor[i]);
    }
    soma = soma_vetores(vetor, tamanho);
    printf("\n %d", soma);
    return 0;
}
int soma_vetores(int *vetor, int tamanho)
{
    int acum = 0;
    if (tamanho == 0)
    {
        return 0;
    }
    else
        return vetor[tamanho - 1] + soma_vetores(vetor, tamanho - 1); // soma o de tras com o tras do de tras ate dar zero
}