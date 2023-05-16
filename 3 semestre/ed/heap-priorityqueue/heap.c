#include "heap.h"
#include<stdio.h>
#include <stdlib.h>
void exchange(struct tree *elem1, struct tree *elem2)
{
    struct tree aux = *elem1;
    *elem1 = *elem2;
    *elem2 = aux;
}
void insert(struct tree elem, struct tree *array)
{
array->num_elements++;
array[array->num_elements] = elem;
/*
check if the new insertion didn't destroyed the priority order
*/
evaluateHeap(array, array->num_elements); // array and the index
}

void goingUp(struct tree *array, int key)
{
    /**
     * if the father has less priority than the element, so we exchange them 
     * going up a level.
    */
    if (key > 0 && array[PARENT(key)].priority < array[key].priority)
    {
        exchange(&array[PARENT(key)], &array[key]);
        goingUp(array, PARENT(key)); // we check again the same K after exchaning.
    }
}

void removers(struct tree *array)
{
    struct tree aux = array[0]; // copies the first elmeent
    exchange(&array[array->num_elements], &array[0]); // exchanges the first with the last bc its easier to remove
    array->num_elements--;
    goingDown(array, 0); 
}

void goningDown(struct tree *array, int key)
{
    int most_priority_son_index;
    if(LEFT_SON(key) < array->num_elements)
    {
        most_priority_son_index = LEFT_SON(key); // just a guess

        if (RIGHT_SON(key) < array->num_elements && array[RIGHT_SON(key)].priority > array[LEFT_SON(key)].priority)
             most_priority_son_index = RIGHT_SON(key); // right_son has more priority

        if(array[key].priority < array[most_priority_son_index].priority)
        {
            exchange(&array[key], &array[most_priority_son_index]);
            goingDown(array, most_priority_son_index);
        }

    }
}

void buildHeapFromArray(struct tree *array) //supossing array is any array.
{
 int k, mid;
 mid = (array->num_elements-1)/2;
 for (k = mid; k >= 0; k--)
 {
    goingDown(array, k);
 }
}
