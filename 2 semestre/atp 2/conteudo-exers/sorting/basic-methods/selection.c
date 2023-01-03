#include<stdio.h>

void printSortedArray(int *array, int qtd);
void selectionSort(int *array, int qtd);

int main()
{
    int qtd;
    scanf("%d", &qtd);
    int array[qtd];
    for (int i = 0; i < qtd; i++)
    {
        scanf("%d", &array[i]);
    }
    printSortedArray(array, qtd);
    return 0;
}
void printSortedArray(int *array, int qtd)
{
    selectionSort(array, qtd);
    for (int j = 0; j < qtd; j++)
    {
        printf("%d ", array[j]);
    }
}
void selectionSort(int *array, int qtd)
{
    int i,j, least, aux;
    for (i = 0; i < qtd-1; i++)
    {
        least = i;
        // agora percorre tudo para ver qual é o  menor
        for(j=i+1; j < qtd; j++)
        {
            if (array[j] < array[least])
                least = j;
        }
        if (least != i) // para não ter que trocar  no mesmo lugar
        {
            aux = array[i];
            array[i] = array[least];
            array[least] = aux;
        }
    }
}
