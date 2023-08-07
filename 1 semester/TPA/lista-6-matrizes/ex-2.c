/* Construa um programa que contém uma matriz 5 x 5. Preencha com 1 a diagonal principal e com 0 os
demais elementos. Escreva ao final a matriz obtida */
#include <stdio.h>
int main()
{
    int matriz[5][5], i, j;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (i == j)
            {
                matriz[i][j] = 1;
            }
            else
            {
                matriz[i][j] = 0;
            }
        }
    }
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf("\t %d ", matriz[i][j]);
        }
        printf("\n");
    }
    return 0;
}