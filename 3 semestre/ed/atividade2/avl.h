#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int chave;
    struct no *esq;
    struct no *dir;
    int altura;
} no;

void in_order(no *raiz);
void pre_order(no *raiz);
int alturaNo(no *no);
int fatorBalanecamento(no *no);
no *rotacaoEsquerda(no *raiz);
no * rotacaoDireita(no *raiz);
no * rotacaoEsquerdaDireita(no *raiz);
no * rotacaoDireitaEsquerda(no *raiz);
no *inserir(no *raiz, int chave);
no *remover(no *raiz, int chave);
no *balancear(no *raiz);