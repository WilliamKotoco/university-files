/*
Escreva um programa em linguagem C para gerar, aleatoriamente, 10 números inteiros. Os
valores devem ser armazenados um vetor com 11 posições. Em seguida, o programa deve
solicitar duas entradas, um elemento e um índice. O índice deve ser um valor entre 0 e 9. O
elemento informado deve ser inserido na posição especificada, deslocando todos os elementos
seguintes. Imprimir o resultado. */
#include <stdio.h>
int main()
{
    int i, vetor[11], elemento, indice;
    for (i = 0; i < 10; i++)
    {
        vetor[i] = rand() % 100;
    }
    for (i = 0; i < 11; i++)
    {
        printf("\n %d", vetor[i]);
    }
    printf("\nDigite um indice (0 a 9): ");
    scanf("%d", &indice);
    printf("Digite um elemento: ");
    scanf("%d", &elemento);
    vetor[indice] = elemento;

    for (i = 1; i < 12 - indice; i++)
    {
        vetor[indice + i] = vetor[indice + i + 1];
    }
    printf("\n =================================================================================");
    for (i = 0; i < 11; i++)
    {
        printf("\n %d", vetor[i]);
    }
    return 0;
}