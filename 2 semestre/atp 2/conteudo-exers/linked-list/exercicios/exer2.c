#include <stdio.h>
#include <stdlib.h>

struct lista
{
    int num;
    struct lista *prox;
};
struct lista *preencher_lista(struct lista *ward);
struct lista *searchElement(struct lista *ward);
struct lista *inserir_lista(struct lista *aux, struct lista *ward);
struct lista *removeElement(struct lista *ward);
struct lista *addNewElement(struct lista *ward);
struct lista *copyingList(struct lista *ward2, struct lista *ward);
struct lista *concatLists(struct lista *ward, struct lista *ward2);
void printList(struct lista *ward);

int main()
{
    int op, sair = 0;
    struct lista *ward, *aux, *ward2;
    ward = NULL;
    ward2 = NULL;
    ward = preencher_lista(ward);

    while (sair == 0)
    {
        printf("\n 1: buscar \n 2: adicionar \n 3: remover \n 4: imprimir \n 5: copiar em outra e imprimir \n 6: concatenar com outra \n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            aux = searchElement(ward);
            if (aux == NULL)
                printf("\n Elemento não existe");
            else
                printf("\n Elemento existe e está em %p ", aux);
            break;
        case 2:
            ward = addNewElement(ward);
            break;
        case 3:
            ward = removeElement(ward);
            break;
        case 4:
            printList(ward);
            break;
        case 5:
            ward2 = copyingList(ward2, ward);
            printList(ward);
            printf("\n");
            printList(ward2);
            break;
        case 6:
        // FIXME: essa parte ainda não ta funcionado
            printf("\n Preenchendo a segunda lista: ");
            ward2 = preencher_lista(ward2);
            concatLists(ward, ward2);
            printList(ward);
            break;
        default:
            sair = 1;
        }
    }
}
struct lista *preencher_lista(struct lista *ward)
{
    struct lista *aux;
    int i = 0, parada = 0, num;
    while (parada == 0)
    {
        printf("\n Digite um número: ");
        scanf("%d", &num);
        aux = malloc(sizeof(struct lista));
        aux->prox = NULL;
        aux->num = num;
        printf("\n Digite 0 se deseja continuar");
        scanf("%d", &parada);
        ward = inserir_lista(aux, ward);
    }
    return ward;
}
struct lista *inserir_lista(struct lista *elem, struct lista *ward)
{
    struct lista *aux, *antes;
    if (ward == NULL)
    {
        ward = elem;
        return elem;
    }
    else
    {
        aux = antes = ward;
        // procurar lugar para colocar o elemento
        while (aux->prox != NULL && elem->num > aux->num)
        {
            antes = aux;
            aux = aux->prox;
        }

        // saiu do while pois achou lugar
        /*
        opcoes:
        1- é o novo header
        2- vem depois do header
        3 - vem no meio da lista (normal)
        4- vem no final da lista, aux->next é nulo


        */
        if (aux == ward)
        {
            if (elem->num < aux->num)
            {
                elem->prox = ward;
                return elem;
            }
            else
            {
                elem->prox = aux->prox;
                aux->prox = elem;
                return ward;
            }
        }
        else
        {
            if (elem->num < aux->num) // insere antes
            {
                elem->prox = aux;
                antes->prox = elem;
                return ward;
                /*

                */
            }
            else // chegou aqui entao aux->prox é nulo e tem que inserir no final
            {
                aux->prox = elem;
                return ward;
            }
        }
    }
}
void printList(struct lista *ward)
{

    struct lista *aux = ward;
    while (aux != NULL)
    {
        printf("%d ", aux->num);
        aux = aux->prox;
    }
}
struct lista *searchElement(struct lista *ward)
{
    struct lista *aux = ward;
    printf("%d", aux->num);
    int num;
    printf("\n Digite o número: ");
    scanf("%d", &num);

    while (aux != NULL && aux->num != num)
    {
        aux = aux->prox;
    }
    return aux;
}
struct lista *addNewElement(struct lista *ward)
{
    int num;
    struct lista *aux;
    aux = malloc(sizeof(struct lista));
    printf("\n Digite o elemento a ser adicionado: ");
    scanf("%d", &num);
    aux->num = num;
    aux->prox = NULL;
    ward = inserir_lista(aux, ward);
    return ward;
}
struct lista *copyingList(struct lista *ward2, struct lista *ward)
{
    // TODO: copiar uma lista na outra
    ward2 = ward;
    struct lista *aux, *auxPrincipal;
    aux = ward2;
    auxPrincipal = ward;
    while (auxPrincipal != NULL)
    {
        aux = malloc(sizeof(struct lista));
        aux->num = auxPrincipal->num;
        aux->prox = auxPrincipal->prox;
        auxPrincipal = auxPrincipal->prox;
    }
    return ward2;
}
struct lista *removeElement(struct lista *ward)
{
    struct lista *aux, *antes;
    int elem;
    printf("\n Digite o elemento: ");
    scanf("%d", &elem);
    if (ward == NULL)
        puts("\n lista vazia");
    else
    {
        aux = antes = ward;
        while (aux != NULL && aux->num != elem)
        {
            antes = aux;
            aux = aux->prox;
        }

        if (aux == ward)
        {
            ward = aux->prox;
            free(aux);
            puts("\n Removido");
        }
        else if (aux == NULL)
            puts("\n Elemento não existe");
        else
        {
            antes = aux->prox;
            free(aux);
            puts("\n Removido");
        }
    }
    return ward;
}
struct lista *concatLists(struct lista *ward, struct lista *ward2)
{
    struct lista *aux;
    printf("%d", ward->num);
    aux = ward2;
    while (aux != NULL)
    {
        ward = inserir_lista(aux, ward);
        aux = aux->prox;
    }
    return ward;
}