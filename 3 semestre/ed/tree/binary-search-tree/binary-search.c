#include "binary-search.h"
#include <stdio.h>
#include <stdlib.h>
struct tree
{
    int value;
    struct tree *right;
    struct tree *left;
};
struct tree *insertion(struct tree *root, int value)
{
    if (root == NULL)
    {
        root = malloc(sizeof(struct tree));
        root->value = value;
        root->right = NULL;
        root->left = NULL;
        return root;
    }
    else if (value > root->value)
        root->right = insertion(root->right, value);
    else if (value < root->value)
        root->left = insertion(root->left, value);
    else
        printf("\n Valor já existe.");
    return root;
}

struct tree *search(struct tree *root, int value)
{
    if (!root) // se for nulo já retorna
        return root;
    if (root->value == value)
        return root;
    else if (value > root->value)
        return search(root->right, value);
    else
        return search(root->left, value);
    return NULL; // caso não encontre
}

void in_order(struct tree *root)
{
    if (root == NULL)
        return;
    in_order(root->left);
    printf("%d ", root->value);

    in_order(root->right);
}

struct tree *delete(struct tree *root, int value)
{

    /*
    Não da para usar a função já pronta de buscar por conta de que
    precisa-se acessar as raízes por meio da recursão
    */
    if (!root) // caso básico
        return NULL;
    if (value > root->value)
    {
        root->right = delete (root->right, value);
        return root;
    }

    else if (value < root->value)
    {
        root->left = delete (root->left, value);
        return root;
    }

    // nesse ponto estamos no exato nó que queremos deletar


    if (!root->left && !root->right) // ambos sem filhos, sendo folha
    {
        free(root);
        return NULL;
    }

    /*
    Da free em um dos filhos e retorna para
    o root->left ou para o root->right acima um dos novos filhos
    da raiz
    */
    else if (!root->left && root->right) // tem à direita
    {
        struct tree *tmp = root->right;
        free(root);
        return tmp;
    }
    else if (!root->right && root->left) // tem à esquerda
    {
        struct tree *tmp = root->left;
        free(root);
        return tmp;
    }
    /*
    O caso abaixo é para caso tenha-se dois filhos

    Pode-se fazer substituindo o node eliminado pello maior valor da sub-arvore
    à esquerda ou pelo menor valor da subárvore à direita.
    */

   else if (root->right && root->left) // tem os dois filhos
   {
    struct tree *aux = root->left;
    while (aux->right)
        aux = aux->right;  //pegar o maior valor da subárvore à esquerda

    root->value = aux->value; // troca o valor
    aux->value = value; 
    root->left = delete(root->left, value);
    return root;
    
   }

}