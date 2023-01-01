#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int age;
    int instant;
    struct queue *next;
};
void add_aux(struct queue **header, struct queue **tail, int age, int instant);
void add(struct queue **header, struct queue **tail, int age, int instant);
void removequeue(struct queue **header, struct queue **tail);
void printQueue(struct queue *header);

int main()
{
    int i, qtd, age, instant, totalTime, current_time = 3, currentAge, flag;
    struct queue *header = NULL, *aux_header = NULL, *tail = NULL, *aux_tail = NULL;
    scanf("%d", &qtd);
    for (i = 0; i < qtd; i++)
    {
        scanf("%d %d", &age, &instant);
        add_aux(&aux_header, &aux_tail, age, instant);
    }
    totalTime = aux_header->instant;
    currentAge = aux_header->age;
    add(&header, &tail, aux_header->age, aux_header->instant);
    removequeue(&aux_header, &aux_tail);
    flag = 1;
    while (header != NULL || aux_header != NULL)
    {
        if (current_time >= 3)
        {
            current_time = 0;
            if (header == NULL)
            {
                add(&header, &tail, aux_header->age, aux_header->instant);
                totalTime = aux_header->instant;
                removequeue(&aux_header, &aux_tail);
                flag = 1;
            }

            currentAge = header->age;
            removequeue(&header, &tail);
        }

        while (aux_header != NULL && totalTime >= aux_header->instant)
        {
            add(&header, &tail, aux_header->age, aux_header->instant);
            removequeue(&aux_header, &aux_tail);
            flag = 1;
        }
        if (flag != 0)
        {
            printf("%d ", currentAge);
            printQueue(header);
        }
        current_time++;
        totalTime++;
        flag = 0;
    }

    return 0;
}

void add_aux(struct queue **header, struct queue **tail, int age, int instant)
{
    struct queue *element, *aux, *prev;
    element = malloc(sizeof(struct queue));
    element->age = age;
    element->instant = instant;

    if ((*header) == NULL)
    {
        (*header) = element;
        (*tail) = element;
        (*header)->next = NULL;
        return;
    }

    // idoso
    if (element->instant < (*header)->instant || (element->instant == (*header)->instant && element->age > 59 && element->age > (*header)->age))
    {
        element->next = (*header);
        (*header) = element;
        return;
    }

    // nao idoso
    if (element->instant > (*tail)->instant)
    {
        element->next = NULL;
        (*tail)->next = element;
        (*tail) = element;
        return;
    }

    aux = (*header)->next;
    prev = (*header);
    while (aux != NULL)
    {
        if (element->instant < aux->instant || (element->instant == aux->instant && element->age > 59 && element->age > aux->age))
        {
            prev->next = element;
            element->next = aux;
            return;
        }
        prev = aux;
        aux = aux->next;
    }

    if (element->instant == (*header)->instant && ((*header)->next == NULL || ((*header)->next)->instant != element->instant))
    {
        element->next = (*header)->next;
        (*header)->next = element;
        return;
    }

    aux = (*header)->next;
    while (aux != NULL)
    {
        if (element->instant == aux->instant && (aux->next == NULL || (aux->next)->instant != element->instant))
        {
            element->next = aux->next;
            aux->next = element;
            if (element->next == NULL)
                (*tail) = element;
            return;
        }
        aux = aux->next;
    }
}

void add(struct queue **header, struct queue **tail, int age, int instant)
{
    struct queue *element, *aux, *prev;
    element = malloc(sizeof(struct queue));
    element->age = age;
    element->instant = instant;
    if ((*header) == NULL)
    {
        (*header) = element;
        (*tail) = element;
        element->next = NULL;
        return;
    }
    if (element->age > 59) // idoso, prioridade
    {
        if (element->age > (*header)->age)
        {
            element->next = (*header);
            (*header) = element;
            return;
        }
        aux = (*header)->next;
        prev = (*header);
        while (aux != NULL)
        {
            if (element->age > aux->age)
            {
                prev->next = element;
                element->next = aux;
                return;
            }
            prev = aux;
            aux = aux->next;
        }
    }
    (*tail)->next = element;
    element->next = NULL;
    (*tail) = element;
}

void removequeue(struct queue **header, struct queue **tail)
{
    if ((*header) == NULL)
        return;
    if ((*header)->next == NULL)
    {
        free((*header));
        (*tail) = NULL;
        (*header) = NULL;
        return;
    }
    if ((*header)->next == (*tail))
    {
        free((*header));
        (*header) = (*tail);
        return;
    }
    struct queue *aux = (*header);
    (*header) = aux->next;
    free(aux);
}

void printQueue(struct queue *header)
{
    while (header != NULL)
    {
        printf("%d ", header->age);
        header = header->next;
    }

    printf("\n");
}
