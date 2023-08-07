// Escreva um programa para ler uma matriz A(3x4) e que calcule a sua transposta.
// Salve o resultado em uma nova matriz T.
#include <stdio.h>
#define linha 3
#define coluna 4
int main()
{
    int A[linha][coluna], T[coluna][linha];
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            printf("Digite um elemento da matriz: ");
            scanf("%d", &A[i][j]);
            T[j][i] = A[i][j];
        }
    }
    // matriz transposta: as linhas viram colunas, colunas viram linhas
    printf("\n Matriz composta: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", T[i][j])
        }

        printf("\n");
    }
    return 0;
}