#include<stdio.h>

void printSortedArray(int *array, int qtd);
void insertionSort(int *array, int qtd);

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
    insertionSort(array, qtd);
    for (int j = 0; j < qtd; j++)
    {
        printf("%d ", array[j]);
    }
}
void insertionSort(int *array, int qtd)
{
    int i, j, aux;
    for (i = 1; i < qtd; i++)
    {
        aux = array[i];
        j = i;
        while(j>0 && array[j-1] > aux)
        {
            array[j] = array[j-1];
            j--;
        }
        array[j] = aux;
    }
}
