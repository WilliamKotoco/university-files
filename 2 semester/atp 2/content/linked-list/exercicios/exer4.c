#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct list
{
    int key;
    char name[20];
    struct list *next;
    struct list *prev;
};
void fillList(struct list *header);
void insert(struct list *elem, struct list **header);
void printlist(struct list *header);

int main()
{
    struct list *header;
    header->next = header->prev = header;
    fillList(header);
    printlist(header);
    return 0;
}
void fillList(struct list *header)
{
    char nome[20];
    int key;
    struct list *aux;
    for (int i = 0; i < 10; i++)
    {
        aux = malloc(sizeof(struct list));
        printf("\n Digite o nome: ");
        scanf("%s", nome);
        printf("\n Digite a chave: ");
        scanf("%d", &key);
        aux->key = key;
        strcpy(aux->name, nome);
        aux->prev = aux->next = aux;
        printf("%p", &header);
        insert(aux, &header);
        printf("%s", header->name);
    }
}
void insert(struct list *elem, struct list **header)
{
    struct list *aux = (*header);
    if (aux == NULL) // lista vazia
    {
        (*header) = elem;
        return;
    }
    else
    {
        if ((*header)->next == (*header)) // só tem um elemento
        {
            // agora basta definir quem vai ser o novo header
            (*header)->next = elem;
            (*header)->prev = elem;
            elem->prev = (*header);
            elem->next = (*header);
            if (elem->key < (*header)->key)
                (*header) = elem;
            return;
        }
        else
        {
            while (aux->next != NULL && aux->key < elem->key)
                aux = aux->next;
            if (aux == *header && aux->key > elem->key)
            {
                aux->prev = aux->next;
                (aux->prev)->next = elem;
                elem->next = (*header);
                elem->prev = aux->prev;
                (*header) = elem;
                return;
            }
            else
            {
                elem->next = aux;
                (aux->prev)->next = elem;
                elem->prev = aux->prev;
                return;
            }
        }
    }
}
void printlist(struct list *header)
{
    struct list *aux;
    aux = header;
    while (aux->next != header)
    {
        printf("\n %s %d ", aux->name, aux->key);
        aux = aux->next;
    }
}