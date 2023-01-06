#include <stdio.h>

void printSortedArray(int *array, int qtd);
void shellSort(int *array, int qtd);

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
    shellSort(array, qtd);
    for (int j = 0; j < qtd; j++)
    {
        printf("%d ", array[j]);
    }
}
void shellSort(int *array, int qtd)
{
    int i, j, steps, l, value;
    steps = 1;
    while(steps< qtd/2)
        steps = 3*steps+1; // pegando o  melhor número de pulos possíveis, de acordo com a fórmula de Knuth
    while (steps != 1)
    {
        steps = steps/3; // se reduz à razão 3

        /*
        Abaixo, algoritmo do insertion sort
        */
       for(l=0;l<steps;l++)
       {
        for(i=l+steps; i< qtd; i = i+steps) // ordenando pulando steps
        {
            value = array[i];
            j = i;
            while(j-steps >= 0 && array[j-steps] > value)
            {
                array[j] = array[j-steps];
                j = j-steps;
            }
            array[j] = value;
        }
       }
    }
}
