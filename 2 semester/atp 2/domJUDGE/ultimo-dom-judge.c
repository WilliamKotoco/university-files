#include <stdio.h>
int bsearch(int *array, int N, long int target);
int reversebsearch(int *array, int N, long int target);

int main()
{
    int i, N, numSearchings, place;
    long int target;
    scanf("%d", &N);
    int array[N];
    for (i = 0; i < N; i++)
    {
        scanf("%d", &array[i]);
    }
    scanf("%d", &numSearchings);
    for (i = 0; i < numSearchings; i++)
    {
        scanf("%ld", &target);
        place = bsearch(array, N, target);
        if (place != -1)
            printf("%d ", place);
        else{
            place = reversebsearch(array, N, target);
            printf("%d ", place);

        }
    }

    return 0;
}

int bsearch(int *array, int N, long int target)
{
    int min = 0;
    int max = N/ 2 - 1;
    int mid = (min + max)/2;
    if (array[min] == target)
        return min;
    else if (array[max] == target)
        return max;
    while (target != array[mid] && min < max)
    {
        if (target > array[mid])
            min = mid +1;
        else 
            max = mid -1 ;
        mid = (min + max) / 2;
    }
    if(target == array[mid])
        return mid;    
    return -1;
}
int reversebsearch(int *array, int N, long int target)
{
    int min = N/2;
    int max = N-1;
    int mid = (min + max)/2;
    if (array[min] == target)
        return min;
    else if (array[max] == target)
        return max;
    while (target != array[mid] && min < max)
    {
        if (target < array[mid])
            min = mid +1;
        else
            max = mid -1;
        mid = (min + max) / 2;
    }
      if(target == array[mid])
        return mid;
    return -1;
}