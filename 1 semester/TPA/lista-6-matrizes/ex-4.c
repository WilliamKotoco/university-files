/* Faça um programa que leia uma matriz 4 x 4, imprima a matriz e retorne a localização (linha e a coluna)
do maior valor. */
#include <stdio.h>
int main()
{
    int matriz[4][4], maior = 0, linha, coluna;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("Digite um valor: ");
            scanf("%d", &matriz[i][j]);
            if (maior == 0)
            {
                maior = matriz[i][j];
            }
            else if (matriz[i][j] > maior)
            {
                maior = matriz[i][j];
                linha = i;
                coluna = j;
            }
        }
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("\t %d ", matriz[i][j]);
        }
        printf("\n ");
    }
    printf("\n");
    printf("O maior valor esta na posicao [%d][%d]", linha, coluna);
    return 0;
}