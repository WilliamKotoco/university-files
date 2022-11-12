// Crie um programa que contenha um array contendo 5 elementos inteiros. Leia esse array
// do teclado e imprima o enderec¸o das posic¸oes contendo valores pares.
#include <stdio.h>
int main()
{
    int array[5];
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &array[i]);
        if (array[i] % 2 == 0)
        {
            printf("%p \n ", array[i]);
        }
    }
}