/* Faça um programa que leia um vetor A capaz de armazenar 10 valores. Em seguida, um
vetor B deve receber os valores A, excluindo-se números nulos e negativos. Apresente os
vetores. */
#include <stdio.h>
#define max 4 // mudar para 10 depois
int main()
{
    int A[max], B[max], i;
    for (int i = 0; i < max; i++)
    {
        printf("Digite um valor: ");
        scanf("%d", &A[i]);
        if (A[i] > 0)
        {
            B[i] = A[i];
        }
    }
    printf("\n A \t \t B");
    for (i = 0; i < max; i++)
    {
        printf("\n %d \t\t %d", A[i], B[i]);
    }
    return 0;
}
