/*
N atendentes em paralelo, nenhum pode ficar ocioso se tiver elementos na fila

Id serve como criterio de desempate para dois com o mesmo time,  sendo o menor o que vai primeiro



idea 1: ordenar os elementos em ordem de tempo. Apenas o remover vai ser como o de uma lista

por padrao, os OS vao começar executando o id 0

Para determinar quanto tempo avançar, é necessário pegar a menor carga dos elementos que estão sendo atendidos
fazer uma funcao para tal depois de cada iteracao

Verificar se o ultimo processo da fila pode ser atendido ou não
    - elem->tempo < tempo_total, vai parar de verificar quando essa condicao for falsa ou quando todas os tiverem cheias
        ideia: while(tempo_total > elem->tempo && isAnyFree(os))
pôde ser atendido: joga ele no primeiro livre
não pode: sai do laço

Dar free em quais podem ser removidos... Depois de dar free, aí sim avançar a cabeça
    -> verificar se o tempo atual > carga+tempo_inicial



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
    struct queue *job;
};

void fillElement(struct queue **header);
void addQueue(struct queue **header, struct queue *elem);
void printList(struct queue *header);
int lessWeight(struct queue *header);
void addWork(struct queue *header, struct OS *reception, int num_SC);
void executeWork(struct queue **header, struct OS *reception, int num_SC);

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
        reception[i].job = NULL;
        // zera tudo
    }
    for (i = 0; i < num_elements; i++)
    {
        fillElement(&header);
    }
    printList(header);

   // while (header != NULL) // enquanto tiver elemento na fila
    //{
        
        addWork(header, reception, num_SC);
        execution_time = execution_time + lessWeight(header);
        executeWork(&header, reception, num_SC);
    //}
    for (i = 0; i < num_SC; i++)
    {
        printf("%d ", reception[i].contador);
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
    struct queue *aux, *prev, *aux2, *prev2;
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
                aux2 = prev2 = aux;
                while (aux2->next != NULL && elem->id > aux2->id)
                {
                    prev2 = aux2;
                    aux2 = aux2->next;
                }

                if (aux2->id < elem->id)
                {
                    elem->next = aux2->next;
                    aux2->next = elem;
                    return;
                }
                else
                {
                    (*header) = elem;
                    elem->next = aux2;
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
                aux2 = prev2 = aux;
                while (aux2->next != NULL && elem->id < aux2->id)
                {
                    prev2 = aux2;
                    aux2 = aux2->next;
                }
                if (aux2->id < elem->id)
                {
                    prev2->next = elem;
                    elem->next = aux2;
                    return;
                }
                else
                {
                    elem->next = aux2->next;
                    aux2->next = elem;
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

/*
Essa funcao pega a menor carga entre os que estão sendo atendidos, para poder incrementar no tempo
*/
int lessWeight(struct queue *header)
{
    int less = INT_MAX; // maior inteiro possivel para evitar do aleardo me sacanear nos testes
    struct queue *aux = header;

    while (aux->attending == 1)
    {
        if (aux->weight < less)
            less = aux->weight;
        aux = aux->next;
    }

    return less;
}

// essa funcao vai alocar os serviços para cada OS, sem executar o serviço ainda
void addWork(struct queue *header, struct OS *reception, int num_SC)
{
    int i;
    struct queue *aux = header;
    printf("%d", aux->id);
    while (aux != NULL && aux->time <= execution_time && aux->attending == 0)
    {
        for (i = 0; i < num_SC; i++) // tem que percorrer todos porque talvez o segundo esteja ocupado mas o terceiro nao, nao esta ordenado
        {
            if (reception[i].busy == 0)
            {
                reception[i].busy = 1;
                reception[i].job = aux;
                aux->attending = 1;
                aux->final_time = execution_time + aux->weight;
            }
            aux = aux->next;
        }
    }
}

/*
Função que vai executar os trabalhos que foram alocados:
 1- Verificar qual trabalho, dentro dos ativos, tem o tempo final <= o execution_time
 2- dar free nele e incrementar o contador do atendente


*/
void executeWork(struct queue **header, struct OS *reception, int num_SC)
{
    struct queue *aux;
    int k = 0;

    do
    {
        aux = (*header);
        if (aux->final_time <= execution_time)
        {
            while (reception[k].job != aux)
                k++;

            (*header) = aux->next;
            reception[k].busy = 0;
            reception[k].job = NULL;
            reception[k].contador = (reception[k].job)->final_time;
            free(aux);
        }
    } while (aux->attending == 1 && aux->next != NULL);
}
/*
TESTES:
//:  1- ordenando certo: YES
2 - pegando a menor carga dentre todas: OK
3- pegando a menor carga somente entre as ativas:
FIXME: ele ta dando o mesmo trabalho para todas SC


*/