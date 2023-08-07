/* Faça um programa que leia uma matriz 5 x 5, bem como um valor X. O programa deverá fazer uma busca
desse valor na matriz e, ao final, escrever a localização (linha e coluna) ou uma mensagem de “não
encontrado”. */
#include <stdio.h>
#define ordem 3 // mudar dps
int main()
{
    int matriz[ordem][ordem], i, j, valor, linha, coluna;
    for (i = 0; i < ordem; i++)
    {
        for (j = 0; j < ordem; j++)
        {
            printf("Digite um valor: ");
            scanf("%d", &matriz[i][j]);
        }
    }
    printf("\n Digite um valor");
    scanf("%d", &valor);

    for (int i = 0; i < ordem; i++)
    {
        for (j = 0; j < ordem; j++)
        {
            if (matriz[i][j] == valor)
            {
                linha = i;
                coluna = j;
            }
        }
    }
    printf("O valor esta na posicao: [%d][%d]\n", linha, coluna);
    return 0;
}