#include <stdio.h>
#include <stdlib.h>
struct lista
{
    int id;
    struct lista *prox;
    int pulos;
    int operacao;
};

struct lista *addTail(struct lista **ward, int, int, int);
// retorna a tail
void remover(struct lista **ward, struct lista *elem);
void coloca(struct lista **ward, struct lista *tail);
int main()
{
    struct lista *ward, *tail, *aux;
    ward = NULL;
    int i, N, pulos, op;
    scanf("%d", &N);

    // passa o i como id, nao pode ter id zero
    // entao nesse caso especial começa com 1
    for (i = 1; i <= N; i++)
    {
        scanf("%d %d", &pulos, &op);
        tail = addTail(&ward, i, pulos, op);
    }
    aux = tail;
    pulos = ward->pulos;
    tail = NULL;
    while (ward != ward->prox)
    {

        for (i = 0; i < pulos; i++)
        {
            aux = aux->prox;
        }
        if (aux->operacao != 0) // nao é pra remover, entao é pra colocar
            coloca(&ward, tail);
        else if (tail = NULL)
        {
            free(tail);
        }

        remover(&ward, aux);
        pulos = aux->pulos;
        tail = aux;
    }
    printf("\n %d\n ", ward->id);
    return 0;
}
struct lista *addTail(struct lista **ward, int id, int pulos, int operacao)
{

    static struct lista *tail = NULL;
    // cria um elemento fantasma
    struct lista *elem;
    elem = malloc(sizeof(struct lista));
    elem->id = id;
    elem->pulos = pulos;
    elem->operacao = operacao;
    if ((*ward) == NULL)
    {
        elem->prox = elem; // na lista circular, quando nao tem prox o elemento dve sempre apontar pra ele mesmo, aleardo explicou em sala n sei o porquê
        (*ward) = elem;
    }
    else
    // cololca depois do final, sendo o novo final
    {
        tail->prox = elem;
        elem->prox = (*ward);
    }
    tail = elem;
    return tail;
}
void coloca(struct lista **ward, struct lista *tail)
{

    struct lista *aux = (*ward), *aux2 = (*ward);
    tail->operacao = 0;
    // reinsere com a opcao zero, nao tem o porquê reinsirir com a opcao de reinsir
    while (aux->prox != (*ward) && (tail->id > (aux->prox)->id))
    {
        aux = aux->prox;
        // enquanto nao apontar para o comeco (ou seja ser o fim) e o id for menor que o ultimo
    }
    if (tail->id < (*ward)->id)
    {
        // nesse caso entao o elemento a ser reinserido é o novo header
        (*ward) = tail;
    }

    // o proximo elemento dele se torna o ultimo

    aux2 = aux->prox;
    aux->prox = tail;
    tail->prox = aux2;
}
void remover(struct lista **ward, struct lista *elem)
{
    struct lista *aux = elem;

    aux = aux->prox;
    while (aux->prox != elem)
    {
        aux = aux->prox;
        // encontra o elmento
    }

    aux->prox = elem->prox;
    // o proximo aponta para o proximo do elemento que vai ser removido
    if ((*ward) == elem)
    {
        // passa o começo (header) pra frente se o elemento a ser removido for o header
        (*ward) = (*ward)->prox;
    }
    return;
}
