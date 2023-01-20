#include<stdio.h>
#include<stdlib.h>
#define N 50
void printSortedArray(int *vet);
void quicksort(int *vet, int low, int high);
int mediana(int *vet, int low, int mid, int high);
void troca(int *a, int *b);

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
    if ((vet[low] <= vet[mid] && vet[high] >= vet[mid]) || (vet[low] >= vet[mid] && vet[mid] >= vet[high]))
        return mid;
    if ((vet[mid] <= vet[low] && vet[high] >= vet[low]) || (vet[mid] >= vet[low] && vet[low] >= vet[high]))
        return low;
    if ((vet[mid] <= vet[high] && vet[low] >= vet[high]) || (vet[mid] >= vet[high] && vet[low] <= vet[high]))
        return high;
return -1;

}
void troca(int *a, int *b)
{
    int aux;
    aux = *a;
    *b = aux;
    *a = *b;

}