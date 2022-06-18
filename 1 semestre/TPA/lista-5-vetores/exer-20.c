/*
Seja A e B dois vetores contendo 10 elementos inteiros. Fazer um programa para:
a. ler A e B.
b. Calcular a soma dos elementos de A.
c. Calcular a soma dos elementos de B.
d. Obter o vetor C, que é a soma dos vetores A e B.
e. Obter o vetor D, subtraindo B de A. */
#include <stdlib.h>
#include <stdio.h>
#define max 4 // trocar pra 10 depois
int main()
{
    int A[max], B[max], C[max], D[max], soma_A = 0, soma_B = 0;
    for (int i = 0; i < max; i++)
    {
        printf("\n Digite elemtno para A: ");
        scanf("%d", &A[i]);
        printf("\n Digite elemtno para B: ");
        scanf("%d", &B[i]);
        soma_A = soma_A + A[i];
        soma_B = soma_B + B[i];
        C[i] = A[i] + B[i];
        D[i] = B[i] - A[i];
    }
    printf("\n Soma dos elementos de A: %d", soma_A);
    printf("\n Soma dos elementos de B: %d", soma_B);
    printf("\n C \t\t D");

    for (int i = 0; i < max; i++)
    {
        printf("\n %d \t\t %d", C[i], D[i]);
    }

    return 0;
}