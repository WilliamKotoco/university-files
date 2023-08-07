#include "heap.h"
#include<stdio.h>
#include <stdlib.h>

int main()
{
    struct tree array[30];
    struct tree element;
    for(int i =0; i < 10; i++) 
    {
        element.num_elements++;
        element.priority = i;
        element.val = rand()%30;
        insert(element, array);
    }

    for (int i =0; i < array->num_elements; i++)
        printf("Priority: %d \t value: %d \n", array[i].priority, array[i].val);
}