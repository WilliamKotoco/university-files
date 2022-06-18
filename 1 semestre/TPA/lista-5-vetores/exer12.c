/*
12. Dado um vetor VIN de 10 elementos inteiros, criar um vetor VAI de 30 elementos, sendo que
VAI[0], VAI[1] e VAI[2] recebe o valor de VIN[0] e assim por diante. Escrever um programa
que leia VIN e imprima VAI.
*/
#include <stdio.h>
int main()
{
    int vin[10], vai[30], i;

    for (i = 0; i < 10; i++)
    {
        printf("Digite o valor de VIN[i], com i sendo %d:  ", i);
        scanf("%d", &vin[i]);
        vai[3 * i] = vin[i];
        vai[3 * i + 1] = vin[i];
        vai[3 * i + 2] = vin[i];
    }
    for (i = 0; i < 30; i++)
    {
        printf("\n VAI %d tem o valor de %d\n", i, vai[i]);
    }
    return 0;
}
