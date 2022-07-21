// Dada a matriz B (100 x 200), escrever um programa para calcular a soma dos elementos da quadragésima
// coluna e a soma dos valores da trigésima linha
#define linhas 100
#define colunas 200
#include <stdio.h>
int main()
{
    int B[linhas][colunas], soma = 0, soma2 = 0, k = 0, l = 0;
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            printf("Digite o elemento: ");
            scanf("%d", &B[i][j]);
        }
    }
    // agora para ler e realizad as operacoes
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            if (i == 29)
            {
                while (k != colunas)
                {
                    soma = soma + B[i][j];
                    k++;
                }
            }
            if (j == 39)
            {
                while (l != linhas)
                {
                    soma2 = soma2 + B[l][j];
                    l++;
                }
            }
        }
    }
    printf("\n Soma: %d ", soma);
    printf("\n Soma 2: %d ", soma2);

    return 0;
}