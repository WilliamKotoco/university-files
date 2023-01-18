#include<stdio.h>
#include<stdlib.h>
#define N 50
void sorting(int *array);
int binarySearch(int *array, int elem);


int main()
{
    int array[N];
for (int i = 0; i < N; i++)
    array[i] = 2*i + 4;
sorting(array);

    printf("Elemento %d encontrado em %d", 4, binarySearch(array, 4));
    return 0;


}
void sorting(int *array)
{
    int i, j, aux;
    for (i = 1; i < N; i++)
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
int binarySearch(int *array, int elem)
{
    int min = 0, max = N -1 , mid = (min + max)/2;
    if (elem == array[mid])
        return mid;
    if (elem == array[min])
        return min;
    if (elem == array[max])
        return max;
    while (elem != array[mid] && min < max)
    {
        if (elem > array[mid])
            min = mid;
        else 
            max = mid;
        mid = (min + max)/2;
    }
    if (elem == array[mid])
        return mid;
    else 
        return -1;
}