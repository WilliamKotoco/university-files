/*
Implementar as duas árvores e imprimir com os percursos
*/
#include "arvores.h"
#include <stdlib.h>
#include <stdio.h>
int main()
{
    static_tree static_tree = calloc(num, sizeof(int));
    static_tree[0] = 8; // é o root.
    static_inserirEsquerda(0, 4, static_tree);
    static_inserirDireita(0, 12, static_tree);
    static_inserirEsquerda(1, 2, static_tree);
    static_inserirDireita(1, 6, static_tree);
    static_inserirEsquerda(2, 10, static_tree);
    static_inserirDireita(2, 14, static_tree);
    static_inserirEsquerda(3, 1, static_tree);
    static_inserirDireita(3, 3, static_tree);
    static_inserirEsquerda(4, 5, static_tree);
    static_inserirDireita(4, 7, static_tree);
    static_inserirEsquerda(5, 9, static_tree);
    static_inserirDireita(5, 11, static_tree);
    static_inserirEsquerda(6, 13, static_tree);
    static_inserirDireita(6, 15, static_tree);

    dynamic_tree *root = inserirTree(NULL, 8);
    root = inserirTree(root, 4);
    root = inserirTree(root, 12);
    root = inserirTree(root, 6);
    root = inserirTree(root, 2);
    root = inserirTree(root, 14);
    root = inserirTree(root, 10);
    root = inserirTree(root, 1);
    root = inserirTree(root, 3);
    root = inserirTree(root, 5);
    root = inserirTree(root, 7);
    root = inserirTree(root, 9);
    root = inserirTree(root, 11);
    root = inserirTree(root, 13);
    root = inserirTree(root, 15);

    puts("********************************************************");
    puts("Estáticos: ");
    puts("Percurso em pré-ordem");
    static_percursos(static_tree, 1, 0);
    puts("\nPercurso in-ordem ");
    static_percursos(static_tree, 2, 0);
    puts("\nPercurso pós-ordem");
    static_percursos(static_tree, 3, 0);
    puts("");
    puts("");
    puts("Dinâmicos: ");
    puts("Percurso em pré-ordem");
    percursos(root, 1);
    puts("\nPercurso in-ordem ");
    percursos(root, 2);
    puts("\nPercurso pós-ordem");
    percursos(root, 3);
    puts("");
    puts("********************************************************");
}
