/*
manipulacao de uma lista que tem palavras minusulcas

inserir, remover e mostrar o conteudo que foi removido

como são só 100 palavras, da pra fazer por lista simples numa boa
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct lista
{
    char palavra[100];
    struct lista *next;
};
void imprimirLista(struct lista *header);
struct lista *cadastrarPalavra(struct lista *header, char *palavra);
struct lista *inserir(struct lista *palavra, struct lista *header);
struct lista *remover(char *palavar, struct lista *header);
int buscar(char *palavra, struct lista *header);
// retorna 0 se nao encontrou

int main()
{
    struct lista *palavra, *header;
    char word[100];

    header = NULL;

    int n, i, op; // numero inicial de palavras na lista
    int m;        // numero de operacoes a serem realizadas na lista
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++)
    {
        scanf(" %s", word);
        // aqui vao mandar n palavras para armazenar na lista
        header = cadastrarPalavra(header, word);
    }

    for (i = 0; i < m; i++)
    {
        printf("\n ");
        scanf("%d %s", &op, word);

        switch (op)
        {
        case 0:
            header = remover(word, header);
            break;
        case 1:
            header = cadastrarPalavra(header, word);
            break;
        }
    }

    return 0;
}
struct lista *cadastrarPalavra(struct lista *header, char *palavra)
{

    struct lista *aux;
    aux = malloc(sizeof(struct lista));
    aux->next = NULL; // to só criando, na hora de inserir na lista que vai organizar
    strcpy(aux->palavra, palavra);
    if (buscar(palavra, header) == 1)
    {
        return header; // retorna direto e nem deixa inserir
    }

    else
        header = inserir(aux, header);
    return header;
}
struct lista *inserir(struct lista *palavra, struct lista *header)
{

    // vai inserir na lista e retornar a nova posicao do header
    struct lista *aux, *prev;
    if (header == NULL)
    {
        header = palavra;
        return header; // se o header for nulo, a palavra se torna o novo header
    }
    aux = prev = header;
    while (aux->next != NULL && strcmp(palavra->palavra, aux->palavra) > 0) // enquanto ainda estiver proximo e a palavra for maior
    {
        prev = aux;
        aux = aux->next; // anda a fila pra frente
    }

    // saiu do while, entao achou um lugar
    if (aux == header)
    

    {
        if (strcmp(palavra->palavra, aux->palavra) > 0) // se vier depois do header
        {
            palavra->next = aux->next;
            header->next = palavra;
            return header;
        }
        else if (strcmp(palavra->palavra, aux->palavra) < 0) // se vier antes do header
        {
            palavra->next = header;
            return palavra; // o header se torna a nova palavra, so retornar
        }
    }
    if (strcmp(palavra->palavra, aux->palavra) > 0)
    {
        aux->next = palavra; // coloca a palavra depois do aux
    }
    else if (strcmp(palavra->palavra, aux->palavra) < 0) // entao ele saiu do while porque o aux->next é nulo, coloca no final
    {
        palavra->next = aux;
        prev->next = palavra;
    }

    return header;
}
struct lista *remover(char *palavar, struct lista *header)
{
    struct lista *aux = header, *prev = header;
    // buscar pela fruta:
    if (header == NULL)
    {
        return header;
    }

    while (aux->next != NULL && strcmp(palavar, aux->palavra) > 0)
    {
        prev = aux;
        aux = aux->next;
    }
    if (strcmp(aux->palavra, palavar) == 0)
    {
        if (aux != header)
            prev->next = aux->next; // "pula" o elemento na fila
        else
        {
           header = aux->next;
        }
        free(aux);
        imprimirLista(header);

    }
    else if(strcmp(aux->palavra, palavar) != 0)
    {
        imprimirLista(header);
    }
    return header;
}
int buscar(char *palavra, struct lista *header)
{

    struct lista *aux = header, *prev = header;
    if (aux == NULL) // se a lista vier vazia
        return 0;
    while (aux->next != NULL && strcmp(aux->palavra, palavra) > 0)
    {
        prev = aux;
        aux = aux->next;
    }
    if (strcmp(aux->palavra, palavra) == 0)
        return 1;
    else
        return 0;
}
void imprimirLista(struct lista *header)
{
    struct lista *aux = header;
    printf("\n");
    if (aux == NULL)
    {
        printf("NULL");
    }
    while (aux != NULL)
    {
        printf("%s ", aux->palavra);
        aux = aux->next;
    }
}
/*
Ele não ta cadastrando o primeiro elemento
*/