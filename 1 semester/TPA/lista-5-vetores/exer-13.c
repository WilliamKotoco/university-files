/* 13. Dado um vetor A de tamanho 5, capaz de armazenar números inteiros, escreva um programa
para obter a maior diferença entre dois elementos consecutivos desse vetor. Imprimir a
maior diferençae os índices dos respectivos elementos. */
#include <stdio.h>
#define tamanho 5
int main()
{
    int A[tamanho], vetor_dif[tamanho], i, maior = 0, posicao;
    for (i = 0; i < tamanho; i++)
    {
        printf("Digite um valor: ");
        scanf("%d", &A[i]);
    }
    for (i = 0; i < (tamanho - 1); i++)
    {
        vetor_dif[i] = A[i + 1] - A[i];

        if (maior == 0)
        {
            maior = vetor_dif[i];
        }
        else
        {
            if (vetor_dif[i] > maior)
            {
                maior = vetor_dif[i];
                posicao = i;
            }
        }
    }
    printf("\n A maior diferenca é %d, encontrada nos indices %d e %d", maior, posicao, posicao + 1);
    return 0;
}