// Faça um programa para ler duas matrizes A(3x3) e B(3x3), e que some em uma
// terceira matriz C o resultado de A + B
#include <stdio.h>
#define n 3;
int main()
{
    int A[n][n], B[n][n], C[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Digite o valor de N: ");
            scanf("%d", &A[i][j]);
            printf("\n Digite o valor de B: ");
            scanf("%d", &B[i][j]);
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    printf("\n Matriz C");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d", &C[i][j]);
        }
        printf("\n")
    }

    return 0;
}
