// Faça um programa que leia uma matriz A(4x4), e que imprima na tela a soma dos
// elementos abaixo da diagonal principal (aqui, não incluir a diagonal nos cálculos).
#include <stdio.h>
#define n 4
int main()
{
    int A[i][j];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Digite um elemento da matriz: ");
            scanf("%d", &A[i][j]);
            if (i > j)
            {
                printf("%d" & A[i][j]);
            }
        }
    }
    return 0;
}