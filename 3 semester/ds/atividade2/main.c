#include <stdio.h>
#include "avl.h"
/*
 * Função para testar o funcionamento do projeto para uma árvore desbalanceada á direita
 */
void imprimir(no *raiz, int nivel)
{
    int i;
    if (raiz) {
        imprimir(raiz->dir, nivel + 1);
        printf("\n ");
        for (i = 0; i < nivel; i++) {
            printf("\t");
        }
        printf("%d", raiz->chave);
        imprimir(raiz->esq, nivel + 1);
    }

}
/*
 * Testa em uma árvore normal, mas desbalanceada para direita
 */
void teste1()
{
    no  *raiz = NULL;
    raiz = inserir(raiz, 3);
    raiz = inserir(raiz, 2);
    raiz = inserir(raiz, 8);
    raiz = inserir(raiz, 7);
    raiz = inserir(raiz, 10);
    printf("Imprimindo teste 1: \n");
    remover(raiz, 3);
    imprimir(raiz,1);
    printf("\n");

}

/*
 * Testa em uma árvore normal, mas desbalanceada para esquerda
 */
void teste2()
{
    no  *raiz = NULL;
    raiz = inserir(raiz, 5);
    raiz = inserir(raiz, 3);
    raiz = inserir(raiz, 2);
    raiz = inserir(raiz, 1);
    raiz = inserir(raiz, 10);
    printf("Imprimindo teste 2: \n");
    imprimir(raiz, 1);
    printf("\n");

}
/*
 * Testa em uma árvore que só tem filhos a direita
 */
void teste3()
{   no  *raiz = NULL;
    raiz = inserir(raiz, 5);
    raiz = inserir(raiz, 6);
    raiz = inserir(raiz, 7);
    raiz = inserir(raiz, 8);
    raiz = inserir(raiz, 10);
    printf("Imprimindo teste 3: \n");
    imprimir(raiz, 1);
    printf("\n");

}
/*
 * Testa em uma árvore que só tem filhos a esquerda
 */
void teste4()
{
    no  *raiz = NULL;
    raiz = inserir(raiz, 5);
    raiz = inserir(raiz, 4);
    raiz = inserir(raiz, 3);
    raiz = inserir(raiz, 2);
    raiz = inserir(raiz, 1);
   //remover(raiz, 5); 
    printf("Imprimindo teste 4: \n");
    imprimir(raiz, 1);
    printf("\n");
}







int main() {
    teste1();
    teste2();
    teste3();
    teste4();
    return 0;
}
