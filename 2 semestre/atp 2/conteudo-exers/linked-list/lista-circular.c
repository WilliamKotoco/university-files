#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct circ
{
    char name[40];
    struct circ *next;
};

void addElem(struct circ **header);
void insertOnList(struct circ *elem, struct circ **header);
void printList(struct circ *header);
struct circ *searchElement(struct circ *header, char *elem);
void removeElement(struct circ **header, char *elem);

/*
As funcoes de inserir tem que ser void porque as vezes usam-se com tail tambem apontando para o último elmento, como em um buffer circular
*/

int main()
{
    struct circ *header = NULL, *aux;
    int op, turnoff = 0;
    char elem[40];
    while (turnoff == 0)
    {
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            addElem(&header);
            break;
        case 2:
            scanf("%s", elem);
            aux = searchElement(header, elem);
            if (aux == NULL)
                puts("Elemento não encontrado");
            else
                printf("Elemento encontrado no endereco %p", aux);
            break;
        case 3:
            printList(header);
            break;
        case 4:
            scanf("%s", elem);
            // removeElement(&header, elem);
            break;
        default:
            turnoff = 1;
        }
    }
}
void addElem(struct circ **header)
{
    struct circ *aux;
    aux = malloc(sizeof(struct circ));
    char name[40];
    printf("\n Digite o nome do elemento: ");
    scanf("%s", name);
    aux->next = aux; // na lista circular, colocamos o elemento apontando para ele mesmo a priori
    strcpy(aux->name, name);
    insertOnList(aux, header);
}
void insertOnList(struct circ *elem, struct circ **header)
{
    struct circ *aux = (*header), *antes;
    /*
    1 - novo header
    2- insercao antes do header: pode ser o novo header ou o ultimo
    3 depois do header, no meio da lista
  */
    if (aux == NULL)
    {
        (*header) = elem;
        return;
    }
    else
    {

        if ((*header)->next == (*header)) // caso só tenha um elemento
        {
            elem->next = aux;
            aux->next = elem;
            // um a'ponta para o outro, agora basta verificar se mudou o header ou não
            if (strcmp(elem->name, aux->name) < 0)
                (*header) = elem;
            return;
        }
        else // tem mais de um só elemento
        {
            // andar até achar aonde vai colocar
            while (antes->next != (*header) && strcmp(elem->name, aux->name) < 0)
            {
                // serve tambem aux != (*header)
                antes = aux;
                aux = aux->next;
            }

            // caso o elemento seja o novo header
            if (aux == (*header) && strcmp(elem->name, aux->name) < 0)
            {
                antes = aux->next;
                while (antes->next != aux)
                    antes = antes->next;
                /*
                O elemento vai vir antes do header mas não vai ser o último da lista, e sim o novo header
                                */
                antes->next = elem;
                elem->next = (*header);
                (*header) = elem;
                return;
            }
            else
            {
                elem->next = aux;
                antes->next = elem;
                return;
            }
        }
    }
}

void printList(struct circ *header)
{
    struct circ *aux = header;
    while (aux->next != header)
    {
        printf("%s ", aux->name);

        aux = aux->next;
    }
    // como ele sai no final, printa mais um
    printf("%s ", aux->name);
}
struct circ *searchElement(struct circ *header, char *elem)
{
    struct circ *aux = header->next;
    if (strcmp(elem, aux->name) == 0)
        return aux;
    else
    {
        while(aux != header && strcmp(aux->name, elem) < 0 )
            aux = aux->next;
        if (strcmp(elem, aux->name) == 0)
            return aux;
        else
            return NULL;
    }

}