/*
Construa um programa para preencher uma matriz 4 x 4 com o produto do valor da linha e da coluna de
cada elemento. Em seguida, imprima na tela a matriz. */
#include <stdio.h>
int main()
{
    int matriz[4][4], i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            matriz[i][j] = i * j;
        }
    }

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("\t %d", matriz[i][j]);
        }
        printf("\n");
    }
    return 0;
}