/* Gere matriz 4 x 4 com valores no intervalo [1, 20]. Escreva um programa que transforme a matriz gerada
numa matriz triangular inferior, ou seja, atribuindo zero a todos os elementos acima da diagonal principal.
Imprima a matriz original e a matriz transformada. */
#include <stdio.h>
#include <stdlib.h>
#define tamanho 4
int main()
{
    int matriz[tamanho][tamanho];
    for (int i = 0; i < tamanho; i++)
    {
        for (int j = 0; j < tamanho; j++)
        {
            matriz[i][j] = rand() % 20;
        }
    }
    printf("Antes da transformação: \n");
    for (int i = 0; i < tamanho; i++)
    {
        for (int j = 0; j < tamanho; j++)
        {
            printf("%d", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n Depois da transformação: \n");
    for (int i = 0; i < tamanho; i++)
    {
        for (int j = 0; j < tamanho; j++)
        {
            if (i < j)
            {
                matriz[i][j] = 0;
            }
            printf(" %d ", matriz[i][j]);
        }
        printf("\n");
    }
    return 0;
}