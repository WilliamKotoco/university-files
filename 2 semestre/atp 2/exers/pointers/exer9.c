// Crie um programa que contenha uma matriz de float contendo 3 linhas e 3 colunas.
// Imprima o enderec¸o de cada posic¸ao dessa matriz
#include <stdio.h>
int main()
{
    float matriz[3][3];
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            matriz[i][j] = rand() % 20;
            printf("\n %p", matriz[i][j]);
            printf("\n %f", matriz[i][j]);
        }
    }
}