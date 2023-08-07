// Dada uma matriz A com dimensões 2 x 3, conforme indicado abaixo, imprima a matriz transposta de
#include <stdio.h>
int main()
{
    int A[2][3], transposta[3][2];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("Digite o elemento: ");
            scanf("%d", &A[i][j]);
        }
    }

    // fazendo a transposta
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            transposta[i][j] = A[j][i];
            printf("%d ", transposta[i][j]);
        }
        printf("\n ");
    }

    return 0;
}