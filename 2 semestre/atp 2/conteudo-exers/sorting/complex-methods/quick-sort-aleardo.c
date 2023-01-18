#include<stdio.h>
#define N 50
void printSortedArray(int *vet);
int main()
{
    int vet[N];
    for (int i = 0; i < N; i++)
        vet[i] = 223*i + 234234 %100;
    
    printSortedArray(vet);

    return 0;
}
void printSortedArray(int *vet)
{
    quicksort(vet,0, N-1);
    for (int i = 0; i < N; i++)
        printf("%d ", vet[i]);
}
void quicksort(int *vet, int low, int high)
{
    int i, pivo, bigger;
    if (low < high)
    {
        pivo = mediana(vet, low, (low+high)/2, high);
        troca (&vet[pivo], &vet[high]);
        bigger = low;
        for (i = bigger; i < high; i++)
        {
            if (vet[i] < vet[high])
            {
                troca(&vet[i], &vet[bigger]);
                bigger++;
            }
        }
        // troca o pivo com o elemento maior que o pivo que esteja na posicao mais baixa do q o pivo
        troca (&vet[bigger], &vet[i]);
        quicksort(vet, low, bigger-1);
        quicksort(vet, bigger+1, high);
    }
    else
        return;
}
int mediana(int *vet, int low, int mid, int high)
{
    // TODO: pensar maneira mais eficiente
    int array[3];
    int aux, j;
    array[0] = vet[low];
    array[1] = vet[mid];
    array[2] = vet[high];
     for ( int i = 1; i < 3; i++)
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
    if (array[2] == vet[mid])
        return mid;
    if (array[2] == vet[low])
        return low;
    if (array[2] == vet[high])
        return high;

}
void troca(int *a, int *b)
{
    int aux;
    aux = *a;
    *b = aux;
    *a = *b;

}