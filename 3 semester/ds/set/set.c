#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct intSet
{
    int *elem;
    int size;
};

struct intSet *create_set(struct intSet *set)
{
    set = malloc(sizeof(struct intSet));
    set->size = 1;
    set->elem = malloc(sizeof(int));
    set->elem[0] = 0;

    return set;
}
int alreadyInSet(struct intSet *set, int elem)
{
   for (int i = 0; i < set->size; i++) 
   {
    if(set->elem[i] == elem)
        return 1;
   }
   return 0;
}
struct intSet *add_set(struct intSet *set, int elem)
{
  int i;
    if(alreadyInSet(set, elem))
    {puts("existe"); 
    return set;
    }
    set->size++;
    set->elem = realloc(set->elem, set->size * sizeof(int));
    set->elem[set->size-1] = elem;

    return set;
}

int *uniao(struct intSet *set1, struct intSet *set2)
{
    int count = 0, k, *tmp, *array;
    tmp = calloc(set1->size, sizeof(int));
    for(k=0; k < set1->size; k++)
    {
        if(alreadyInSet(set2, set1->elem[k]))
        {
            tmp[k] = set1->elem[k];
            count++;
        }
    }
    array = malloc(count * sizeof(int));
        puts("infos: ");
        printf("%d %d \n", set1->size, set2->size);
        printf("%d \n", count);
        printf("%d \n", tmp[3]);
        puts("fim infos");
    for(int i =1; i < count; i++)
        array[i] = tmp[i];
    free(tmp);
    return array;

}
int main()
{
    struct intSet *elem = NULL;
    struct intSet *elem2 = NULL;
    int *uniaoArray = NULL;
    elem = create_set(elem);
    elem2 = create_set(elem2);

    elem = add_set(elem, 1);
    elem = add_set(elem, 3);
    elem = add_set(elem, 3);
    elem = add_set(elem, 44);
    elem2 = add_set(elem2, 5);
    elem2 = add_set(elem2, 3);
    elem2 = add_set(elem2, 44);
    elem2  = add_set(elem2, 9);


    uniaoArray = uniao(elem, elem2);
    for(int i= 0; i < sizeof(uniaoArray)/sizeof(uniaoArray[0]) + 2; i++)
        printf("%d ", uniaoArray[i]);


    puts("mostrando elementos de cada set: ");
  for (int i = 0; i < elem->size; i++)
        printf("%d \n", elem->elem[i]);
    puts("");
    for(int i = 0; i < elem2->size; i++)
    {
        printf("%d \n", elem2->elem[i]);

    }
        
}