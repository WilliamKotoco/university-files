/*Escreva um programa que leia dois vetores A e B com 10 posições. Em seguida, o programa
deve realizar a multiplicação entre os elementos (com o mesmo índice) contidos nos vetores.
O resultado deve ser armazenado em um vetor C. Mostre o vetor resultante. */
#include <stdio.h>
#define max 10 // alterar pra 10 depois
int main()
{
    int A[max], B[max], C[max];
    for (int i = 0; i < max; i++)
    {
        printf("Digite um valor para A: ");
        scanf("%d", &A[i]);
        printf("\n Digite um valor para B: ");
        scanf("%d", &B[i]);
    }
    for (int i = 0; i < max; i++)
    {
        C[i] = A[i] * B[i];
        printf("\nC%d = %d", i, C[i]);
    }
    return 0;
}