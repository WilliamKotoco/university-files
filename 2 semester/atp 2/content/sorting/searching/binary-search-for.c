#include<stdio.h>
#include<stdlib.h>
#define N 50
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

int binarySearch(int *array, int elem)
{
 int min = 0, max = N -1 , mid = (min + max)/2;
 if (array[min] == elem)
    return min;
else if (array[max] == elem)
    return max;
    while (min < max)
    {
        if (elem == array[mid])
            return mid;
       else if (elem > array[mid])
            min = mid+1;
        else 
            max = mid-1;
        mid = (min + max)/2;
    }
    return -1;
}
