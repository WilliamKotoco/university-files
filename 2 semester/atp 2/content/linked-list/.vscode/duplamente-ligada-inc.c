#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct dupla
{
    char nome[40];
    struct dupla *prox; // aponta para o próximo
    struct dupla *prev; // aponta para o anterio
}Ldupla;

int maisProximo(); // retorna 0 se o elemento está mais proximo do final
int naoChegou(); // verifica se ja localizou o ponto correto de insercao, aí colocamos no meio
void insereDupla(Ldupla **head, Ldupla **tail, Ldupla *elem);
void removeDupla(Ldupla **head, Ldupla **tail, Ldupla *elem);
int main()
{



}
void insereDupla(Ldupla **head, Ldupla **tail, Ldupla *elem)
{
    // usando o ponteiro duplo, vamos mudar o endereço que head e tail apontam
    Ldupla *aux;
    if (*head = NULL ) // se nao tiver primeiro elemento
    {
        *head = *tail = elem;
        return;
    }
  
    if (maisProximo(elem, *head, *tail) != 0 ) // ou seja, está perto do começo
    {
        aux = *head;
        while (naoChegou(elem, aux) != 0 && aux->prox != NULL ) //enquanto nao achar o elemento
            aux = aux->prox;
        if (aux == *head)
        {
            if (naoChegou(elem, aux) == 0) // ou seja, ele saiu do while por causa do aux->prox ser nulo
            {
                elem->prox = aux;
                elem->prev = NULL; // elem se torna o primeiro da lista
                aux->prev = elem;
                *head = elem;
            }
            else 
            {
                if (*head == *tail) // se só tiver um elemento na lista
                {  
                    *tail = elem;
                    elem->prox = aux;
                    elem->prev = aux;
                    aux->prox = elem;
                }
            }
        }
       else
        {
            elem->prox = aux;
            elem->prev = aux->prev;
            aux->prev = elem;
            (elem->prev)->prox = elem;
            
        }
            

    }

    else // nesse caso, ele estará perto do final
    {
        aux = *tail;
        // depois termina
    }
}

void removeDupla(Ldupla **head, Ldupla **tail, Ldupla *elem)
{
 Ldupla *aux;
 if (*head == NULL)
    return; // lista vazia, tratar depois
if (maisProximo(elem, *head, *tail)) // vai ser diferente de zero, portanto mais proximo do head
{
    aux = *head;
    while(naoChegou(elem, aux, 1))
        aux = aux->prox;
    if(strcmp(elem->nome, aux->nome) == 0)//encontramos
    {
        if (aux == *head)  // atualizando a cabeca
            *head = aux->prox;
        else
            (aux->prev)->prox = aux->prox;
        if (aux == *tail) // ultimo
            *tail = NULL;
        else
            (aux->prox)->prev = aux->prev;
        free(aux);
    }
    else {
        puts("Nao encontrou");
        return;
        }
}
else
{
 //fazer para mais perto de tail
}
}