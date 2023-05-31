#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#define queue_size 100

struct queue
{
    int A[queue_size];
    int start, end;
};
struct node
{
    int id;
    int value;
    struct node *next;
};

struct graphy
{
    int id;
    int number_of_nodes;
    struct node *vertices; // array of vertices
};

/**
 * Creates a new node and returns it
 * @param id
 * @param val
 * @return a new node duh
 */
struct node *createNode(int id, int val)
{
    struct node *new = malloc(sizeof(struct node));
    new->id = id;
    new->value = val;
    new->next = NULL;
    return new;
}
/**
 * add a new node in the node's adjacent lists
 * @param node
 * @param id
 * @param val
 */
void addNode(struct node *node, int id, int val)
{
    struct node *new = createNode(id, val);
    if (node == NULL)
        return;
    // searchs for the last node in the adjacents list
    while (node->next != NULL)
    {
        node = node->next;
    }
    node->next = new;
}

/**
 * Creates a new graphy and returns it
 * @return
 */
struct graphy *create()
{
    struct graphy *graphy = malloc(sizeof(struct graphy));
    graphy->vertices = NULL;
    graphy->number_of_nodes = 0;

    return graphy;
}

/**
 * Reads the file containing the graphy values
 * stores those values in the adjacency matrix
 * @param filenaeme
 * @param  matrix
 */
void readFile(const char *filenaeme, int ***matrix)
{
    FILE *fp;
    int buffer_size = 20;
    int number_of_nodes, origem, destination, value, i, j;

    fp = fopen(filenaeme, "r");
    char buffer[buffer_size];
    fgets(buffer, buffer_size, fp);
    sscanf(buffer, "%d", &number_of_nodes);

    (*matrix) = malloc(number_of_nodes * sizeof(int *));
    for (i = 0; i < number_of_nodes; i++)
    {
        (*matrix)[i] = malloc(number_of_nodes * sizeof(int));
        for (j = 0; j < number_of_nodes; j++)
        {
            (*matrix)[i][j] = 0;
        }
    }

    while (!feof(fp))
    {
        fgets(buffer, buffer_size, fp);
        sscanf(buffer, "%d %d %d", &origem, &destination, &value);

        (*matrix)[origem][destination] = value; // the weights
    }

    fclose(fp);
}

/**
 * prints the nodes
 */
void printNode(struct node *node)
{
    while (node != NULL)
    {
        printf("-> (%d, val: %d)", node->id, node->value);
        node = node->next;
    }
}
/**
 * prints the graphy
 * @param graphy
 */
void printGraphy(struct graphy *G)
{
    int i;
    printf("\n Lista de adjacências \n \n");
    for (i = 0; i < G->number_of_nodes; i++)
    {
        printf(" (%d) ", (G->vertices + i)->id);
        printNode(G->vertices + i);
        printf("\n");
    }
}

/**
 * Creates an empty queue
 * @param q
 */
void createQueue(struct queue **q)
{
    (*q)->end = 0;
    (*q)->start = 0;
}
/**
 * Checks if an queue is empty
 * @param q
 * @return
 */
bool empty(struct queue *q)
{
    if (q->start == q->end)
        return true;
    return false;
}
/**
 * checks if an queue is full
 * @param q
 * @return
 */
bool isFull(struct queue *q)
{
    if (q->start == ((q->end + 1) % queue_size))
        return true;
    return false;
}
/**
 * insert an element in the queue and returns true.
 * If the element could not be inserted, returns false.
 * @param q
 * @param element
 * @return
 */
bool insert(struct queue *q, int element)
{
    if (isFull(q))
        return false;
    q->end = (q->end + 1) % queue_size;
    q->A[q->end] = element;
    return true;
}

/**
 * remove an element from the queue and returns true.
 * If couldn't be removed, returns false.
 * @param q
 * @param element
 * @return
 */
bool remover(struct queue *q, int *element)
{
    if (empty(q))
        return false;
    (q)->start = (q->start + 1) % queue_size;
    *element = q->A[q->start];

    return true;
}

// COMEÇA AQUI
int main()
{
    int **matrix;
    int distance[5];
    int i, j, initial_vertix = 0;

    struct queue *queue = malloc(sizeof(struct queue));

    readFile("digrafo.txt", &matrix);
  
    for (j = 0; j < 5; j++)
    {
        distance[j] = INT_MAX;
    }

    distance[initial_vertix] = 0; // node to itself is zero

    createQueue(&queue);
    insert(queue, initial_vertix);
    while (!empty(queue))
    {
        remover(queue, &i);
        for (j = 0; j < 5; j++)
        {
            if (matrix[i][j] != 0 && distance[j] >= INT_MAX)
            {
                distance[j] = distance[i] + matrix[i][j];
                insert(queue, j);
            }
        }

    }


        for (i = 0; i < 5; i++)
        {
           printf("distance[%d]: %d \n", i, distance[i]);
        }
}
