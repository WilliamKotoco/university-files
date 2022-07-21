// . Construa um programa para ler 32 elementos do tipo inteiro. Os valores devem ser armazenados em duas
// matrizes. Cada matriz deve armazenar metade dos valores lidos. Em seguida, o programa deve realizar a
// soma dos elementos contidos nas matrizes e apresentar os resultados. Cada soma é o resultado obtido a
// partir de duas posições equivalentes nas matrizes, por exemplo: A[1][1] + B[1][1]
#include <stdio.h>
#define metade 3
#define elementos 6
int main()
{
    int A[metade][metade], B[metade][metade], result[metade];
    for (int i = 0; i < metade; i++)
    {
        for (int j = 0; j < metade; j++)
        {
            printf("Digite o elemento da matriz A: ");
            scanf("%d", &A[i][j]);
            printf("Digite o elemento da matriz B: ");
            scanf("%d", &B[i][j]);
            result[i] = A[i][j] + B[i][j];
        }
    }
    printf("\n Mostrando os elementos: ");
    for (int i = 0; i < metade; i++)
    {
        printf(" %d ", result[i]);

        printf("\n");
    }
    return 0;
}