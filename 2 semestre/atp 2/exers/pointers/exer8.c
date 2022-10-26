// . Crie um programa que contenha um array de float contendo 10 elementos. Imprima o
// enderec¸o de cada posic¸ao desse array
#include <stdio.h>
int main()
{
    float array[10];
    for (int i = 0; i < 10; i++)
    {
        array[i] = rand() % 20;
        printf(" \n %p", array[i]);
    }
}