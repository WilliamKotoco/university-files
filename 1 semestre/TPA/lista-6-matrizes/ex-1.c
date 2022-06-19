/*Construa um programa para ler uma matriz 4 x 4, conte e escreva quantos valores maiores que 10 ela
possui. */
#include <stdio.h>
int main()
{
    int matriz[4][4], i, j, contador = 0;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("Digite o valor: ");
            scanf("%d", &matriz[i][j]);
            if (matriz[i][j] > 10)
                contador++;
        }
    }
    printf("Ha %d numeros > 10 ", contador);
    return 0;
}