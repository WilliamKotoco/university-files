// Construa um programa para ler dados e armazenar em duas matrizes inteiras, nomeadas como A e B. As
// dimensões das matrizes são 3x3. Armazenar em uma matriz R o resultado da multiplicação de A por B
#include <stdio.h>
#define ordem 3
int main()
{
    int A[ordem][ordem], B[ordem][ordem], result[ordem][ordem], multiplicacao = 0, k = 0;
    for (int i = 0; i < ordem; i++)
    {
        for (int j = 0; j < ordem; j++)
        {
            printf("Digite o  elemento de A: ");
            scanf("%d", &A[i][j]);
            printf("Digite o elemento de B: ");
            scanf("%d", &B[i][j]);
        }
    }

    for (int i = 0; i < ordem; i++)
    {
        for (int j = 0; j < ordem; j++)
        {
            while (k != ordem)
            {
                multiplicacao = multiplicacao + (A[i][j] * B[j][i]);
                k++;
            }
            result[i][j] = multiplicacao;
            multiplicacao = 0;
        }
    }
    // mostrar a matriz resultante:

    for (int i = 0; i < ordem; i++)
    {
        for (int j = 0; j < ordem; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}