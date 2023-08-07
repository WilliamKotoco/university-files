#include <stdio.h>
#include <stdlib.h>
void printSortedArray(int *array, int qtd);
void mergeSort(int *array, int left, int right, int *aux);


int main()
{
    int qtd;
    scanf("%d", &qtd);
    int array[qtd];
    for (int i = 0; i < qtd; i++)
    {
        array[i] = rand() % 100;
    }
    printSortedArray(array, qtd);
    return 0;
}
void printSortedArray(int *array, int qtd)
{
    int aux[qtd];
    mergeSort(array, 0, qtd - 1, aux);
    for (int j = 0; j < qtd; j++)
    {
       printf("%d ", array[j]);
    }
}
void mergeSort(int *array, int left, int right, int *aux)
{
    int mid, ptr_left, ptr_right, k = 0;
    if (right <= left)
        return;
    mid = (left + right)/2;
    mergeSort(array, left, mid, aux);
    mergeSort(array, mid+1, right, aux);
    ptr_left = left;
    ptr_right = mid+1;
    while (ptr_left <= mid && ptr_right <= right)
    {
        if(array[ptr_left] < array[ptr_right])
        {
            aux[k] = array[ptr_left];
            ptr_left++;
        }
        else
        {
            aux[k] = array[ptr_right];
            ptr_right++;
        }
        k++;
    }

    if(ptr_left > mid)
    {
        while(ptr_right <= right)
        {
            aux[k] = array[ptr_right];
            ptr_right++;
            k++;
        }
    }
    else
    {
         while(ptr_left <= mid)
        {
            aux[k] = array[ptr_left];
            ptr_left++;
            k++;
        }
    }

    for(k=left; k<=right; k++)
        array[k] = aux[k-left];
}
