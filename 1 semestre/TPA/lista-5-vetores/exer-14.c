/* 14 Faça um programa que leia um vetor X capaz de armazenar cinco números inteiros. Em
seguida, o programa deve dividir todos os elementos contidos em X pelo maior valor do
vetor. Mostre o vetor antes e após os cálculos */
#include <stdio.h>
#include <stdlib.h>
#define max 5
int main()
{
    int i, maior = 0;
    float X[max];
    for (i = 0; i < max; i++)
    {
        printf("Digite um valor: ");
        scanf("%f", &X[i]);
        if (maior == 0)
        {
            maior = X[i];
        }
        else
        {
            if (X[i] > maior)
            {
                maior = X[i];
            }
        }
    }
    printf("\n Antes do calculo: ");
    for (i = 0; i < max; i++)
    {
        printf("\n Indice %d: %0.2f", i, X[i]);
    }
    printf("\n Apos os calculos: ");
    for (i = 0; i < max; i++)
    {
        printf("\n Indice %d: %0.2f", i, (X[i] / maior));
    }
    return 0;
}