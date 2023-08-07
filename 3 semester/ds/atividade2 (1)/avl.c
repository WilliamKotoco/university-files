#include <stdio.h>
#include <stdlib.h>
#include "avl.h"
#define MAX(a,b) (((a)>(b))?(a):(b))

/*
 * Percurso em preflag ordem. O primeiro elemento é a raíz.
 */
void pre_order(no *raiz)
{
    if(!raiz)
        return NULL;
    printf("%d ", raiz->chave);
    pre_order(raiz->esq);
    pre_order(raiz->dir);
}
/*
 * Percurso em ordem. Como é uma árvore binária de busca, deve imprimir crescente, e o elemento
 * do meio deve ser a raíz.
 */
void in_order(no *raiz)
{
    if (raiz == NULL)
        return;
    in_order(raiz->esq);
    printf("%d ", raiz->chave);

    in_order(raiz->dir);
}
/*
 * Calcula  altura total da árvore
 */
int alturaNo(no *no){
    if(!no){
        return -1;
    }

    return no->altura;
}
/*
 * Calcula o vator de balanceamento fazendo altura direita - altura esquerda
 */
int fatorBalanecamento(no *no){
    if(!no){
        return 0;
    }

    return (alturaNo(no->esq) - alturaNo(no->dir));
}
/*
 * Rotação simples esquerda para balancear a árvore.
 */
no *rotacaoEsquerda(no *raiz){

    no *aux1, *aux2;
    aux1 = raiz->dir; //nova raiz
    aux2 = aux1->esq;

    aux1->esq = raiz; //troca
    raiz->dir = aux2;
    raiz->altura = MAX(alturaNo(raiz->esq), alturaNo(raiz->dir)) + 1; //recalcula alturas
    aux1->altura = MAX(alturaNo(aux1->esq), alturaNo(aux1->dir)) + 1;

    return aux1; //nova raiz
}

/*
 * Rotação simples direita para balancear a árvore.
 */
no * rotacaoDireita(no *raiz){


    no *aux1, *aux2;
    aux1 = raiz->esq;
    aux2 = aux1->dir;

    aux1->dir = raiz;
    raiz->esq = aux2;

    raiz->altura = MAX(alturaNo(raiz->esq), alturaNo(raiz->dir)) + 1; //recalcula alturas
    aux1->altura = MAX(alturaNo(aux1->esq), alturaNo(aux1->dir)) + 1;

    return aux1;
}


/*
 * Utiliza a rotação dupla direita para balancear a árvore.
 */
no * rotacaoEsquerdaDireita(no *raiz){
    raiz->esq = rotacaoEsquerda(raiz->esq);
    return rotacaoDireita(raiz);
}


/*
 * Utiliza a rotação dupla esquerda para balancear a árvore.
 */
no * rotacaoDireitaEsquerda(no *raiz){
    raiz->dir = rotacaoDireita(raiz->dir);
    return rotacaoEsquerda(raiz);
}

/*
 * Cria e insere a raíz na posição adequada, e depois balanceia a árvore.
 */
no *inserir(no *raiz, int chave){
    if(!raiz){
        no *novo = malloc(sizeof(no));

        novo->chave = chave;
        novo->esq = novo->dir = NULL;
        novo->altura = 0;

        return novo;
    }

    if(raiz->chave > chave){
        raiz->esq = inserir(raiz->esq, chave);
    } else{
        raiz->dir = inserir(raiz->dir, chave);
    }

    raiz->altura = MAX(alturaNo(raiz->esq), alturaNo(raiz->dir)) + 1;

    raiz = balancear(raiz);

    return raiz;
}


/*
 * Remove o nó pela chave e depois chama a função de balancear a árvore
 */
no *remover(no *raiz, int chave){
    if(!raiz){
        return NULL;
    }

    if(raiz->chave == chave){ //encontrou
        if(!raiz->esq && !raiz->dir){
            free(raiz);

            return NULL;
        } else if(raiz->esq && raiz->dir){
            no *aux = raiz->esq;

            while(aux->dir){
                aux = aux->dir;
            }

            raiz->chave = aux->chave;
            aux->chave = chave;

            raiz->esq = remover(raiz->esq, chave);
            return raiz;
        } else{
            no *aux;

            if(raiz->esq){
                aux = raiz->esq;
            } else{
                aux = raiz->dir;
            }

            free(raiz);
            return aux;
        }
    } else{ //buscando elemento
        if(raiz->chave > chave){
            raiz->esq = remover(raiz->esq, chave);
        } else{
            raiz->dir = remover(raiz->dir, chave);
        }
    }

    raiz->altura = MAX(alturaNo(raiz->esq), alturaNo(raiz->dir)) + 1;

    raiz = balancear(raiz);

    return raiz;
}

/*
 * Balanceia a árvore verificando qual rotação deve ser utilizada de acordo com o fator
 * de balanceamento.
 */
no *balancear(no *raiz){
    int fb = fatorBalanecamento(raiz);

    if(fb < -1 && fatorBalanecamento(raiz->dir) <= 0){
        raiz = rotacaoEsquerda(raiz);
    } else if(fb > 1 && fatorBalanecamento(raiz->esq) >= 0){
        raiz = rotacaoDireita(raiz);
    } else if(fb > 1 && fatorBalanecamento(raiz->esq) < 0){
        raiz = rotacaoEsquerdaDireita(raiz);
    } else if(fb < -1 && fatorBalanecamento(raiz->dir) > 0){
        raiz = rotacaoDireitaEsquerda(raiz);
    }

    return raiz;
}