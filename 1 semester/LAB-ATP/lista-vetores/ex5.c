/*
Faça um programa que leia um vetor N de 20 elementos (tipo inteiro). Em seguida, inverta o 1o
elemento com o último, o 2o com o penúltimo e assim por diante, até inverter o 10o com o 11o.
 No final, escreva na tela o vetor N assim modificado.
Dica: Utilize uma variável auxiliar para fazer a troca de cada par de valores. */
#include <stdio.h>
#define n 10
int main()
{
    int j = n - 1, N[n], aux;
    for (int i = 0; i < n; i++)
    {
        printf("Digite o elemento: ");
        scanf("%d", &N[i]);
    }
    // invertendo
    printf("\n Vetor: \n");
    for (int i = 0; i < n / 2; i++)
    {
        aux = N[i];
        N[i] = N[j];
        N[j] = aux;
        j--;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", N[i]);
    }
    return 0;
}