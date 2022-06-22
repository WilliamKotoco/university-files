/*
Faça um programa que gere números aleatórios entre 0 e 100 para preencher as posições de duas matrizes
com dimensões 4 x 4. As matrizes devem ser nomeadas como A e B. Uma matriz C deve receber, em
cada posição, o maior elemento nas posições correspondentes de A e B. Apresente as matrizes. */
#include <stdio.h>
#define tamanho 4
int main()
{
    int A[tamanho][tamanho], B[tamanho][tamanho], C[tamanho][tamanho];
    // matriz A
    for (int i = 0; i < tamanho; i++)
    {
        for (int j = 0; j < tamanho; j++)
        {
            A[i][j] = rand() % 100;
            B[i][j] = rand() % 100;
            if (A[i][j] > B[i][j])
            {
                C[i][j] = A[i][j];
            }
            else
            {
                C[i][j] = B[i][j];
            }
        }
    }
    printf("\n A\t B\t C");
    for (int i = 0; i < tamanho; i++)
    {
        for (int j = 0; j < tamanho; j++)
        {
            printf("\n%d \t %d \t %d", A[i][j], B[i][j], C[i][j]);
        }
        printf("\n");
    }
    return 0;
}