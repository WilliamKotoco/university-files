#include <stdio.h>

void printSortedArray(int *array, int qtd);
void bubbleSort(int *array, int qtd);

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
    bubbleSort(array, qtd);
    for (int j = 0; j < qtd; j++)
    {
        printf("%d ", array[j]);
    }
}
void bubbleSort(int *array, int qtd)
{
    int i, j, aux, trocou = 1;
    j = qtd;
    while (trocou)
    {
        // inicializa
        aux = array[0];
        trocou = 0;
        for (i = 1; i < j; i++)
        {
            if (array[i] < aux)
            {
                array[i - 1] = array[i];
                trocou = 1;
            }
            else
            {
                array[i - 1] = aux;
                aux = array[i];
            }
        }

        array[i-1] = aux; // ultimo elemento
        j--;
    }
}
