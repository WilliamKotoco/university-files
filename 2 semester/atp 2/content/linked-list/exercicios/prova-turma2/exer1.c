/*
Era pra vc ordenar uma lista duplamente encadeada estruturada
estaticamente (um vetor, no final). Era uma lista de frutas em ordem alfabética.
 Ele pedia pra mostrar o vetor a cada iteração de uma função.
 Q era remover frutas e incluir frutas. O tamanho era 10.
 E tmb falar a posição do ponteiro cauda e cabeça.
*/
#include <stdio.h>
#include <string.h>
struct list
{
    char name[40];
    int prox;
    int prev;
};
void initiate(struct list fruits[]);
void insertinList(int *h, int *t, char *nome, struct list fruits[]);

int main()

{
    struct list fruits[10];
    initiate(fruits);
    int h = -1, t = -1;
    char nome[40];
    for (int i = 0; i < 10; i++)
    {
        printf("\n nome: ");
        scanf("%s", nome);
        insertinList(&h, &t, nome, fruits);
    }
}
void initiate(struct list fruits[])
{
    int i;
    for (i = 0; i < 10; i++)
    {
        fruits[i].prox = -1;
        fruits[i].prev = -1;
    }
}
void insertinList(int *h, int *t, char *nome, struct list fruits[])
{
    int i = 1, j;
    while (fruits[i].prox != -1 && i < 10)
        i++; // pega o primeiro lugar disponivel
    if (i == 10)
        return; // significa que a lista está cheia
    j = *h;
    strcpy(fruits[i].name, nome);
    while (fruits[j].prox > 0 && strcmp(fruits[j].name, nome)) // 0 indica o final da fila, -1 lugares nulos
    {
        j = fruits[j].prox;
    }
    /*
    opcoes: a fruta é o novo header
    a fruta vem depois do header
    a fruta vem no meio
    a fruta vem no final
    */
    if (j == *h)
    {
        if ((strcmp(fruits[j].name, nome) < 0))
        {
            // entao é depios do header
            fruits[i].prox = fruits[j].prox;
            fruits[i].prev = j;
            return;
        }
        else if (fruits[j].prox == 0)
        {
            (*h) = (*t) = i; // é o unico elemento
        }
        else
        {
            fruits[j].prox = -1;
            fruits[j].prev = i;
            (*h) = i;
            return;
        }
    }
    else
    {
        if (fruits[j].prox == 0) // indica que o proximo é o final da fila
        {
                if(strcmp(fruits[j].name, nome) < 0)
                {

                }
        }
    }

}