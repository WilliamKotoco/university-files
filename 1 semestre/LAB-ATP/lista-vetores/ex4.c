/*
Escreva um programa que leia um vetor u de 10 elementos (float ou double) e que
copie seu conteúdo para um segundo vetor, v.
*/
#include <stdio.h>
#define max 10
int main()
{
    float u[max], v[max];

    for (int i = 0; i < max; i++)
    {
        printf("Digite o valor: ");
        scanf("%f", &u[i]);
    }
    printf("\n Vetor original: ");
    for (int i = 0; i < max; i++)
    {
        printf("\n %2.f ", u[i]);
    }
    printf("\n Vetor copiado: ");
    for (int i = 0; i < max; i++)
    {
        v[i] = u[i];
        printf("\n %2.f ", v[i]);
    }
    return 0;
}
