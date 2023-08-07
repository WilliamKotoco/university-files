#include <stdio.h>
#include <stdlib.h>
#define N 15
void mergeSort(int *vet, int left, int right, int *aux);
void quicksort(int *vet, int low, int high);
void troca(int *a, int *b);
int main()
{
    int vet[16] = {3, 4, 9, 2, 5, 8, 2, 1, 7, 4, 6, 2, 9, 8, 5, 1};
    int *aux = malloc(15 * sizeof(int));
    mergeSort(vet, 0, 15, aux);
    for (int i = 0; i < 15; i++)
        printf("%d ", vet[i]);
    quicksort(vet, 0, 5);
    printf("\n");
    for (int i = 0; i < 15; i++)
        printf("%d ", vet[i]);
}
void mergeSort(int *vet, int left, int right, int *aux)
{
    if (right <= left)
        return;
    int mid, ptr_left, ptr_right, k = 0;
    mid = (right + left) / 2;
    mergeSort(vet, left, mid, aux);
    mergeSort(vet, mid + 1, right, aux);
    ptr_left = left;
    ptr_right = mid + 1;
    while (ptr_left <= mid && ptr_right <= right)
    {
        if (vet[ptr_left] > vet[ptr_right])
        {
            aux[k] = vet[ptr_left];
            ptr_left++;
        }
        else
        {
            aux[k] = vet[ptr_right];

            ptr_right++;
        }
        k++;
    }

    if (ptr_left > mid)
    {
        while (ptr_right <= right)
        {
            aux[k] = vet[ptr_right];
            ptr_right++;
            k++;
        }
    }
    else
    {
        while (ptr_left <= mid)
        {
            aux[k] = vet[ptr_left];
            ptr_left++;
            k++;
        }
    }

    for (k = left; k < right; k++)
        vet[k] = aux[k - left];
}
void quicksort(int *vet, int low, int high)
{
    if (high < low)
        return;
    int pivo = 0; // o certo seria fazer mediana de 3, mas puta preguiça.
    int i, bigger;
    troca(&vet[pivo], &vet[high]);
    bigger = low;
    for (i = bigger; i < high; i++)
    {
        if (vet[i] > vet[high])
        {
            troca(&vet[i], &vet[bigger]);
            bigger++;
        }
    }
    troca(&vet[bigger], &vet[high]);
    quicksort(vet, low, bigger-1);
    quicksort(vet, high, bigger+1);
}
void troca(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}
