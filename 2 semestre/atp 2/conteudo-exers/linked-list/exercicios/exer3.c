#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct siteList
{
    char link[200];
    struct siteList *next;
};
void printList(struct siteList *header);
struct siteList *fillList(struct siteList *header);
struct siteList *searchSite(struct siteList *header);
struct siteList *inserir_lista(struct siteList *site, struct siteList *header);

int main()
{
    struct siteList *header;
    header = NULL;
    header = fillList(header);
    printList(header);
    header = searchSite(header);
    printList(header);
    return 0;
}
struct siteList *fillList(struct siteList *header)
{
    struct siteList *aux;
    int parada = 0;
    char link[200];
    while (parada == 0)
    {
        printf("\n Digite o link ");
        scanf("%s", link);
        aux = malloc(sizeof(struct siteList));
        aux->next = NULL;
        strcpy(aux->link, link);
        printf("\n Digite 0 se deseja continuar");
        scanf("%d", &parada);
        header = inserir_lista(aux, header);
    }
    return header;
}
struct siteList *inserir_lista(struct siteList *site, struct siteList *header)
{
    /*
    inserir no final
    */
    struct siteList *aux;
    if (header == NULL)
        return site;
    else
    {
        aux = header;
        while (aux->next != NULL)
            aux = aux->next;
        // saiu do while entao achamos o local
        aux->next = site;
    }
    return header;
}

void printList(struct siteList *header)
{

    struct siteList *aux = header;
    while (aux != NULL)
    {
        printf("%s ", aux->link);
        aux = aux->next;
    }
}
struct siteList *searchSite(struct siteList *header)
{
    struct siteList *aux, *antes;
    char link[200];
    printf("\n Digite o link: ");
    scanf("%s", link);
    aux = antes = header;
    while (aux != NULL && strcmp(aux->link, link))
    {
        antes = aux;
        aux = aux->next;
    }
    if (aux == NULL)
        puts("\n nao encontrou");
    else if (aux == header)
        puts("\n  O elemento já está no topo");
    else
    {
        antes->next = aux->next;
        // tira o aux da lista, mas não elimina ele
        aux->next = header;
        header = aux;
        printf("\n %s \n", header->link);
    }
    return header;
}
