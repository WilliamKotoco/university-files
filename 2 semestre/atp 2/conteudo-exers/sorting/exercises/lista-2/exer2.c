#include <stdio.h>
void insertion_bsearch(int *vet);
int bsearch(int *vet, int left, int right, int elem);

int main()
{
    int vet[16] = {3, 4, 9, 2, 5, 8, 2, 1, 7, 4, 6, 2, 9, 8, 5, 1};
    insertion_bsearch(vet);
    for (int i = 0; i < 16; i++)
        printf("%d ", vet[i]);
    return 0;
}
void insertion_bsearch(int *vet)
{
    int i, j, aux, search;
    for (i = 1; i < 16; i++)
    {
        j = i - 1;
        aux = vet[i];
        search = bsearch(vet, 0, j, vet[i]);

        while (j >= search)
        {
            vet[j + 1] = vet[j];
            j--;
        }
        vet[j + 1] = aux;
    }
}
int bsearch(int *vet, int left, int right, int elem)
{
    if (right <= left)
    {
        if(elem > vet[left])
            return left+1;
        return left;
    }
    int mid =  (left + right) / 2;
    if (elem == vet[mid])
        return mid + 1;
    if(elem > vet[mid])
        return bsearch(vet, mid+1, right, elem);
    else
        return bsearch(vet, left, mid-1, elem);

}