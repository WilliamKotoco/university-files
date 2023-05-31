#include<stdio.h>
#include<stdlib.h>
struct node
{
    int id;
    int value;
    struct node *next;
};

struct graphy{
int number_of_nodes;
struct node *vertices; // array of vertices
};



struct node *create(int id, int value)
{
    struct node *node =  malloc(sizeof(struct node));
    node->id = id;
    node->value = value;
    node->next = NULL;
    return node;
}
/*
referece is the node used to move in the adjacents list

add after the last adjacent from a graphy
*/
void addNode (struct node *reference, int id, int val)
{
struct node *new = create(id, val);
while(reference->next != NULL)
    reference = reference->next;
reference->next = new;
}

void printGraphy(struct graphy *reference)
{
    int i;
    for (i=0;i < reference->number_of_nodes; i++ )
    {
        printf("%d", (reference->vertices+i)->value);
    }
}

void readGraphy(struct graphy *graphy, const char *filename)
{
    FILE *fp;
    int bsize = 20;
    int i,origin,destiny,value;
    char buffer[bsize];
    fp = fopen(filename, "r");

    // first line is the number of nodes
    fgets(buffer, bsize, fp);
    sscanf(buffer, "%d", &graphy->number_of_nodes);
    graphy->vertices = malloc(graphy->number_of_nodes * sizeof(struct node));

    for (i=0; i < graphy->number_of_nodes; i++)
    {
        (graphy->vertices + i)->id = i;
        (graphy->vertices + i )->value = -1;
        (graphy->vertices+i)->next = NULL;
    }

    while(!feof(fp))
    {
        fgets(buffer, bsize, fp);
        sscanf(buffer, "%d %d %d", &origin, &destiny, &value);
        printf("%d %d %d \n", origin, destiny, value);
        addNode ((graphy->vertices + origin), destiny, value);
    }
    
    fclose(fp);
    return;

}

int main()
{
    struct graphy *graphy = malloc(sizeof(struct graphy));
    graphy->number_of_nodes  = 0;
    graphy->vertices = NULL;

    readGraphy(graphy, "digrafo.txt");
    printGraphy(graphy);
}

