#include<stdio.h>
#include<stdlib.h>
#define N 50
int binarySearch(int *array, int elem, int left, int right);


int main()
{
    int array[N];
for (int i = 0; i < N; i++)
    array[i] = 2*i + 4;
sorting(array);

    printf("Elemento %d encontrado em %d", 4, binarySearch(array, 4, 0, N-1));
    return 0;


}

int binarySearch(int *array, int elem, int left, int right)
{
    int mid = left + (right - left)/2;
    if (left > right)
        return -1;
    if (array[mid] == elem)
        return mid;
    else if (array[mid] > elem )
        binarySearch(array, elem, left, mid -1);
    else
        binarySearch(array, elem, mid+1, right);

}
