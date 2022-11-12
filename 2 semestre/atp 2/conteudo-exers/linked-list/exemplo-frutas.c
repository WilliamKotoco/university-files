// o codigo supoe que as frutas ja estao cadastradas, nao vai ter que usar malloc
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct fruta
{
    char nome[40];
    int cor;
    int sabor;
    float peso;
    struct fruta *prox; // ponteiro para a proxima fruta
} Fruta;
struct fruta *leArquivo(struct fruta *head);
struct fruta *preencheFruta(char *);
struct fruta *insereLista(struct fruta *, struct fruta *);
int main()
{
    char fruta[40];
    int op;
    Fruta *cadastro, *novafruta;
    cadastro = NULL; // inicializa vazio o ponteiro
    cadastro = leArquivo(cadastro);
    scanf("%s", &op);
    switch (op)
    {
    case 1:
        scanf("%s", fruta);
        novafruta = preencheFruta(fruta);
        cadastro = insereLista(cadastro, novafruta);
    }
}
