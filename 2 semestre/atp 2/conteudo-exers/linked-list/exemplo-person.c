#include <stdio.h>
#include <stdlib.h>
struct pessoa
{
    int idade;
    char nome[40];
    struct pessoa *next;
};
struct pessoa *criandoNovaPessoa(int idade, char *nome);
void printarPessoas(struct pessoa *);
int main()
{
    struct pessoa *primeira, *segunda;
    int idade;
    char nome[40];
    scanf("%d", &idade);
    scanf(" %s", nome);
    primeira = criandoNovaPessoa(idade, nome);
    segunda = criandoNovaPessoa(14, "joel");
    printarPessoas(primeira);
    printarPessoas(segunda);
    primeira->next = segunda;
    free(primeira);
    free(segunda);
    primeira = NULL;
    segunda = NULL;
}
struct pessoa *criandoNovaPessoa(int idade, char *nome)
{
    printf("\n criando nova pessoa");
    struct pessoa *novaPessoa = NULL; // cria ponteiro para nova pessoa
    novaPessoa = malloc(sizeof(struct pessoa));
    novaPessoa->idade = idade;
    strcpy(novaPessoa->nome, nome);
    novaPessoa->next = NULL; // colocando no final da lista
    return novaPessoa;
}
void printarPessoas(struct pessoa *pessoa)
{
    printf("\n void printar pessoas");
    if (pessoa == NULL)
    {
        printf("Nulo \n");
    }
    printf("\n nome: %s\n", pessoa->nome);
    printf("\n idade: %d\n", pessoa->idade);
}