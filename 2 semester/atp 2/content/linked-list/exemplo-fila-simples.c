#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct queue
{
    char name[40];
    struct queue *next;
};

void fillData(struct queue **header);
void addOnQueue(struct queue **header, struct queue *aux);
void printQueue(struct queue *header);
struct queue *removeQueue(struct queue **header);

int main()

{
    struct queue *header = NULL, *first;
    int op;
    int flag = 0;
    while (flag == 0)
    {
        printf("\n 1 - add\n 2- remove \n 3 - print \n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            fillData(&header);
            break;
        case 2:
            first = removeQueue(&header);
            printf("\n Data: %s ", first->name);
            break;

        case 3:
            printQueue(header);
            break;
        default:
            flag = 1;
        }
    }
    return 0;
}
void fillData(struct queue **header)
{
    struct queue *aux;
    char name[40];
    printf("\n Name: ");
    scanf("%s", name);
    aux = malloc(sizeof(struct queue));
    strcpy(aux->name, name);
    aux->next = NULL;
    addOnQueue(header, aux);
}
void addOnQueue(struct queue **header, struct queue *elem)
{
    struct queue *aux;
    if (*header == NULL)
    {
        *header = elem;
        return;
    }
    else
    {
        aux = (*header);
        while (aux->next != NULL)
            aux = aux->next;
        aux->next = elem;
        return;
    }
}
void printQueue(struct queue *header)
{
    struct queue *aux;
    aux = header;
    while (aux != NULL)
    {
        printf("%s ", aux->name);
        aux = aux->next;
    }
    return;
}
struct queue *removeQueue(struct queue **header)
{
    struct queue *aux;
    if ((*header) == NULL)
        return;
    else
    {
        aux = (*header);
        if (aux->next == NULL)
            (*header) = NULL;
        else
        {
            (*header) = (*header)->next;
            return aux;
        }
    }
}