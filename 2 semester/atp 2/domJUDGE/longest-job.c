
/*

Vou fazer com lista duplamente encadeada só pra facilitar na funcao proximo. Não vou otimizar porque preciso me livrar
logo pra fazer o projeto e estudar

puta merda que codigo horrivel, espero que o aleardo nao leia. Otimizar depois.


8
74 11 
7 20
53 17
78 13
52 11
63 19
89 17
15 20
*/
#include <stdio.h>
#include <stdlib.h>
struct processo
{
    int temp;
    int carga;
    struct processo *next;
    struct processo *prev;
};

struct processo *cadastrarProcesso(struct processo *header, int instante, int carga);
struct processo *executarAtividade(struct processo *header, int *tempo_executando);
struct processo *inserirProcessos(struct processo *programa, struct processo *header);
void imprimirLista(struct processo *header);
struct processo *proximo(struct processo *header, int *tempo_executando);

int main()
{
    struct processo *header, *aux;
    header = NULL;
    int num_programas, instante, carga, i, tempo_executando = 0;
    scanf("%d", &num_programas);
    for (i = 0; i < num_programas; i++)
    {
        scanf("%d %d", &instante, &carga);
        header = cadastrarProcesso(header, instante, carga);
    }
    /*
        Cadastrou e ordenou em ordem de tempo, aí tem que criar uma funcao para ir printando
    */

    //imprimirLista(header);

    for (i = 0; i < num_programas; i++)
    {
        header = executarAtividade(header, &tempo_executando);
    }

    return 0;
}
struct processo *cadastrarProcesso(struct processo *header, int instante, int carga)
{
    struct processo *aux;
    aux = malloc(sizeof(struct processo));
    aux->next = NULL;
    aux->prev = NULL;
    aux->carga = carga;
    aux->temp = instante;
    header = inserirProcessos(aux, header);
    return header;
}
struct processo *inserirProcessos(struct processo *programa, struct processo *header)
{
    struct processo *aux;
    if (header == NULL)
    {
        header = programa;
        return header;
    }
    aux = header;
    while (aux->next != NULL && programa->temp > aux->temp)
    {
        aux = aux->next;
    }

    if (aux == header)
    {
        // tem que fazer essa verificacao pq ele sai do while tanto se o while->next for nulo e tambem se for maior
        if (programa->temp < aux->temp)
        {
            // insere depois do header, se tornando o novo header
            aux->prev = programa;
            programa->next = aux;
            return programa;
            // é o novo header, retorna ele
        }

        else // insere depois)
        {
            programa->next = aux->next;
            aux->next = programa;
            programa->prev = aux;

            return header;
        }
    }
    else
    {
        // vamos ver se ele saiu porque while->next é nulo ou porque é maior
        if (programa->temp < aux->temp)
        {
            (aux->prev)->next = programa;
            programa->prev = aux->prev;
            programa->next = aux;
            aux->prev = programa;
            return header;
        }
        else // maior igual
        {
            programa->next = aux->next;
            programa->prev = aux;
            aux->next = programa;
            return header;
        }
    }
}

void imprimirLista(struct processo *header) // funcao auxiliar
{
    struct processo *aux;
    aux = header;
    while (aux != NULL)
    {
        printf("%d ", aux->temp);
        aux = aux->next;
    }
}

struct processo *executarAtividade(struct processo *header, int *tempo_executando)
{

    // lembrando que já está dentro de um for
    struct processo *aux;
    if (*tempo_executando == 0)
    {
        aux = header;
        *tempo_executando = aux->temp + aux->carga;
        header = aux->next;
        printf("%d ", aux->carga); // imprime a carga da saida que foi executada
        (aux->next)->prev = NULL;
        aux->next = NULL;
        free(aux);
        return header;
    }
    else
    {
        // TODO: reduzir esse codigo zendo tudo dentro do mesmo IF, só olhando a condicao do proximo

        aux = proximo(header, tempo_executando); // recebe o que vai ser executado
        *tempo_executando = *tempo_executando + aux->carga;
        if (aux == header) // se o aux
        {
            header = aux->next;
            printf("%d ", aux->carga);
            if(aux->next != NULL)
                (aux->next)->prev = NULL;
            aux->next = NULL;
            free(aux);
            return header;
        }
        else
        {

            if (aux->next != NULL)
            {
                (aux->next)->prev = aux->prev;
                (aux->prev)->next = aux->next;
            }
            else
            {
                (aux->prev)->next = aux->next;
            }
            printf("%d ", aux->carga);
            free(aux);
            return header;
        }
    }
}
struct processo *proximo(struct processo *header, int *tempo_executando)
{
    struct processo *aux, *escolhido;
    int maior_carga;
    aux = header;
    maior_carga = aux->carga;
    escolhido = aux;
    if (aux->temp >= *tempo_executando)
    {
        //*tempo_executando = *tempo_executando + (aux->temp - *tempo_executando);
        return aux;
    }
    else
    {
        while (aux->next != NULL && aux->temp < *tempo_executando)
        {
            aux = aux->next;

            if (aux->carga > maior_carga)
            {
                maior_carga = aux->carga;
                escolhido = aux;
            }
            else if (aux->carga == maior_carga)
            {
                // o critério de desempate é o menor tempo
                if (aux->carga < escolhido->carga)
                {
                    escolhido = aux;
                }
            }
        }
        return escolhido;
    }
}
