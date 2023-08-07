/*
Construa um programa para gerar automaticamente números entre 0 e 99 de uma cartela de bingo.
Sabendo que cada cartela deverá conter 5 linhas de 5 números, gere estes dados de modo que não tenha
números repetidos dentro das cartelas. O programa deve exibir na tela a cartela gerada.
*/
#include <stdio.h>
#define tamanho 5
int main()
{
    int i, j, k, cartela[tamanho][tamanho], auxiliar[25], numero, posicao, flag = 0;
    for (i = 0; i < tamanho; i++)
    {
        for (j = 0; j < tamanho; j++)
        {
            if (posicao == 0)
            { // armazena o primeiro valor
                numero = rand() % 100;
                cartela[i][j] = numero;
                auxiliar[posicao] = numero;
                posicao++;
            }
            else
            {
                do
                // enquanto a flag for igual a 1, ele vai sortear outro número até que não seja
                {
                    flag = 0;
                    numero = rand() % 100;
                    for (k = 0; k < posicao; k++)
                    {
                        if (auxiliar[k] == numero)
                        {
                            flag = 1;
                        }
                    }
                } while (flag == 1);
                auxiliar[posicao] = numero;
                posicao++;
                cartela[i][j] = numero;
            }
        }
    }
    for (i = 0; i < tamanho; i++)
    {
        for (j = 0; j < tamanho; j++)
        {
            printf(" %d ", cartela[i][j]);
        }
        printf("\n");
    }
    return 0;
}
