    /*
Implementa as funções tanto da árvore dinâmica quanto da árvore estática.
*/
#include "arvores.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

dynamic_tree *inserirTree(dynamic_tree *root, int value)
{
    /*
    Insere ordenando a partir do pai: os menores à esquerda, os maiores à direita
    */
    if (root == NULL)
    {
        dynamic_tree *aux = malloc(sizeof(dynamic_tree));
        aux->value = value;
        aux->left = aux->right = NULL;
        return aux;
    }
    if (value < root->value)
        root->left = inserirTree(root->left, value);
    else
        root->right = inserirTree(root->right, value);

    return root;
}

void percursos(dynamic_tree *root, int flag)
{
    if (root != NULL)
    {

        switch (flag)
        {
        case 1: // pre_ordem
            printf("%d ", root->value);
            percursos(root->left, flag);
            percursos(root->right, flag);
            break;
        case 2: // in_ordem
            percursos(root->left, flag);
            printf("%d ", root->value);
            percursos(root->right, flag);
            break;
        case 3: // pos_ordem
            percursos(root->left, flag);
            percursos(root->right, flag);
            printf("%d ", root->value);
            break;
        }
    }
}

void static_inserirDireita(int parent, int value, static_tree tree)
{
    if (tree == NULL)
        return;
    if (tree[parent] == 0)
    {
        puts("Não tem o nó pai");
        return;
    }
    int index = 2 * parent + 2;
    tree[index] = value;
}

void static_inserirEsquerda(int parent, int value, static_tree tree)
{
    if (tree == NULL)
        return;
    if (tree[parent] == 0)
    {
        puts("Não tem o nó pai");
        return;
    }
    int index = 2 * parent + 1;
    tree[index] = value;
}

void static_percursos(static_tree tree, int flag, int index)
{
    if (index < 15)
    {
        switch (flag)
        {
        case 1:
            printf("%d ", tree[index]);
            static_percursos(tree, flag, 2 * index + 1);
            static_percursos(tree, flag, 2 * index + 2);
            break;
        case 2:
            static_percursos(tree, flag, 2 * index + 1);
            printf("%d ", tree[index]);
            static_percursos(tree, flag, 2 * index + 2);
            break;
        case 3:
            static_percursos(tree, flag, 2 * index + 1);
            static_percursos(tree, flag, 2 * index + 2);
            printf("%d ", tree[index]);

            break;
        }
    }
}
