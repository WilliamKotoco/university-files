/*
N atendentes em paralelo, nenhum pode ficar ocioso se tiver elementos na fila

Id serve como criterio de desempate para dois com o mesmo time,  sendo o menor o que vai primeiro



idea 1: ordenar os elementos em ordem de tempo. Apenas o remover vai ser como o de uma lista

por padrao, os OS vao começar executando o id 0

Para determinar quanto tempo avançar, é necessário pegar a menor carga dos elementos que estão sendo atendidos
fazer uma funcao para tal depois de cada iteracao

Dar free em quais podem ser removidos... Depois de dar free, aí sim avançar a cabeça
    -> verificar se o tempo atual > carga+tempo_inicial

Verificar se o ultimo processo da fila pode ser atendido ou não
    - elem->tempo < tempo_total, vai parar de verificar quando essa condicao for falsa ou quando todas os tiverem cheias
        ideia: while(tempo_total > elem->tempo && isAnyFree(os))
pôde ser atendido: joga ele no primeiro livre
não pode: sai do laço

repete esse ciclo

*/
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int id;
    int time;
    int weight;     // tempo que demora  para ser  executado
    int attending;  // 0 para nao, 1 para sim
    int final_time; // só vai mudar quando estiver sendo atendido, 0 por padrao
    struct queue *next;
};
struct OS
{
    int busy; // 0 nao, 1 sim
    int contador;
};

void fillElement(struct queue **header);
void addQueue(struct queue **header, struct queue *elem);
void printList(struct queue *header);
int lessWeight(struct queue *header);
void addWork(struct queue *header, struct OS *reception, int num_SC);

int execution_time = 0;
int main()
{
    struct queue *header = NULL;
    int num_elements, num_SC, i; // SC = SERVICE CENTER
    scanf("%d %d", &num_elements, &num_SC);
    struct OS reception[num_SC];

    for (i = 0; i < num_SC; i++)
    {
        reception[i].busy = 0;
        reception[i].contador = 0;
        // zera tudo
    }
    for (i = 0; i < num_elements; i++)
    {
        fillElement(&header);
    }


    while (header != NULL) // enquanto tiver elemento na fila
    {
        execution_time = execution_time + lessWeight(header);
        // addWork(header, reception, num_SC);
    }

    return 0;
}
void fillElement(struct queue **header)
{
    struct queue *aux;
    aux = malloc(sizeof(struct queue));
    scanf("%d %d %d", &aux->id, &aux->time, &aux->weight);
    aux->next = NULL;
    aux->attending = 0;
    aux->final_time = 0;
    addQueue(header, aux);
}
void addQueue(struct queue **header, struct queue *elem)
{

    // FIXME: falta ordenar caso tempos iguais, usar o id como criterio de desempate
    struct queue *aux, *prev;
    if ((*header) == NULL)
    {
        (*header) = elem;
        return;
    }
    else
    {
        aux = prev = (*header);
        while (aux->next != NULL && elem->time > aux->time)
        {
            prev = aux;
            aux = aux->next;
        }
        if (aux == (*header))
        {
            if (aux->time < elem->time)
            {
                elem->next = aux->next;
                aux->next = elem;
                return;
            }
            else if (aux->time > elem->time)
            {
                (*header) = elem;
                elem->next = aux;
                return;
            }
            else
            {
                if (aux->id < elem->id)
                {
                    elem->next = aux->next;
                    aux->next = elem;
                    return;
                }
                else
                {
                    (*header) = elem;
                    elem->next = aux;
                    return;
                }
            }
        }
        else
        {
            if (aux->time < elem->time)
            {
                elem->next = aux->next;
                aux->next = elem;
                return;
            }
            else if (aux->time > elem->time)
            {
                prev->next = elem;
                elem->next = aux;
                return;
            }
            else
            {
                if (aux->id < elem->id)
                {
                    prev->next = elem;
                    elem->next = aux;
                    return;
                }
                else
                {
                    elem->next = aux->next;
                    aux->next = elem;
                    return;
                }
            }
        }
    }
}

void printList(struct queue *header)
{
    struct queue *aux = header;
    while (aux != NULL)
    {
        printf("\n %d", aux->id);
        aux = aux->next;
    }
}

int lessWeight(struct queue *header)
{
    int less = INT_MAX; // maior inteiro possivel para evitar do aleardo me sacanear nos testes
    struct queue *aux = header;
    if (execution_time == 0)
    {
        while (aux != NULL)
        {
            if (aux->weight < less)
                less = aux->weight;
            aux = aux->next;
        }
    }
    else
    {
        while (aux != NULL)
        {
            if (aux->weight < less && aux->attending == 1)
                less = aux->weight;
            aux = aux->next;
        }
    }
    return less;
}

/*
TESTES:
 1- ordenando certo: ok
2 - pegando a menor carga dentre todas: OK
3- pegando a menor carga somente entre as ativas:


*/