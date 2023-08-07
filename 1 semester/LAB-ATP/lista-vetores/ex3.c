/*
Faça um programa para ler um vetor de 10 elementos (float ou double). Após carregar o vetor, determinar e imprimir na tela:
(a) O maior elemento do vetor.
(b) O menor elemento do vetor.
*/
#include <stdio.h>
#define max 10
int main()
{
    int vetor[max], maior = 0, menor = 0;
    for (int i = 0; i < max; i++)
    {
        printf("Digite o elemento do vetor: ");
        scanf("%d", &vetor[i]);
        if (maior == 0 && menor == 0)
        {
            maior = vetor[i];
            menor = vetor[i];
        }
        else
        {
            if (vetor[i] > maior)
            {
                maior = vetor[i];
            }
            if (vetor[i] < menor)
            {
                menor = vetor[i];
            }
        }
    }
    printf("\n Maior vetor: %d", maior);
    printf("\n Menor vetor: %d", menor);
    return 0;
}
