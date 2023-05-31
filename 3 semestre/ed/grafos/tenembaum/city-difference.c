#include<stdio.h>
#include<stdlib.h>
#include <string.h>
struct node
{
    char name[40]; // city name
    struct node **adjacents; // array of pointers to adjacent cities
    int number_of_neighbours;
};

/**
 * Join node n1 next to n2, being its sucessor.
*/
void join(struct node *n1, struct node *n2)
{
    (n1)->number_of_neighbours++;
n1->adjacents = realloc(n1->adjacents, n1->number_of_neighbours * sizeof(struct node)); // increments the number of neighbours
n1->adjacents[n1->number_of_neighbours - 1] = n2;
}

void createNode(struct node **n1)
{
*n1 = malloc(sizeof(struct node));
(*n1)->adjacents = malloc(sizeof(struct node *)); // allocating the adjacents

char name[40];
printf("Digite o nome da cidade: ");
scanf("%s", name);
strcpy((*n1)->name, name);
(*n1)->number_of_neighbours = 0;
}

int distanceBetweenCities(struct node *origin, struct node *destination)
{
    int i = 0;
    struct node *aux = origin;
    int distance = 0;
    while (strcmp(aux->name, destination->name) && i < aux->number_of_neighbours)
    {
        distance++;
        aux = aux->adjacents[i];
        if (aux->number_of_neighbours == 0)
        {
            /*
            if it's an end, try another adjacent
            */
            aux = origin;
            distance = 0;
            i++;
        }
    }
    return distance;
    
}

int main()
{
    struct node *n1, *n2, *n3;
    createNode(&n1);
    createNode(&n2);
    createNode(&n3);
    join(n1,n2);
    join(n2,n3);
    printf("%d ", distanceBetweenCities(n1, n3));
  //  printf("%s", n1->name);
    // printf("%s", n1->adjacents[0]->name);
}