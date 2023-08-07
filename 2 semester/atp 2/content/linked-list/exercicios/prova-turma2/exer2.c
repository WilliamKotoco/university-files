/*
A 2 valia 3 e vc tinha q fazer o protótipo da função de pop e push de
uma pilha. Essa pilha qndo lia um número X,
deletava todos o números que ela tinha q eram menores
q X. Aí vc tinha q escrever como seria essa função.
*/
#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int x;
    struct stack *next;
};
int main()
{
    struct stack *h, *elem;
    int x;
    h = NULL;
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &x);
        elem = malloc(sizeof(struct stack));
        elem->next = NULL;
        elem->x = x;
        h = push(h, elem);
    }
    h = pop(&h);

    (h, x);
}
struct stack *push(struct stack *h, struct stack *elem)
{
    elem->next = h; // coloca no final
    return elem;
}
struct stack *pop(struct stack *h)
{
    struct stack *aux;
    aux = h;
    h = aux->next;
    if((h->next)->x > (h)->x)
    {
        return h;
    }
    else
        pop(h);
}