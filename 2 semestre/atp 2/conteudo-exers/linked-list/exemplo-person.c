#include <stdio.h>
#include <stdlib.h>
struct pessoa
{
    int idade;
    char nome[40];
    struct pessoa *next;
};
struct pessoa *criandoNovaPessoa(int idade, char *nome);
int main()
{
    int idade;
    char nome[40];
    scanf("%d", &idade);
    scanf("%s", nome);
    criandoNovaPessoa(idade, nome);
}
struct pessoa *criandoNovaPessoa(int idade, char *nome);
{
    struct pessoa *novaPessoa = NULL; // cria ponteiro para nova pessoa
    novaPessoa = malloc(sizeof(struct pessoa));
    novaPessoa->idade = idade;
    novaPessoa->nome = nome;
    return novaPessoa;
}