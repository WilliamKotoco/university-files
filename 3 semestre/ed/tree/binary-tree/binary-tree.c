#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct tree
{
    char word[40];
    struct tree *right;
    struct tree *left;
};

int main()
{
    char word[40];
    struct tree *raiz = createTree(); // cria a raíz da árvore.
   

        
    }
struct tree *createTree()
{
    char word[40];
    struct tree *node = malloc(sizeof(struct tree));
    node->left = NULL;
    node->right = NULL;
    printf("Digite a primeira palavra: ");
    scanf("%s", word);
    strcpy(node->word, word);
    return node;
}

/*
Entra em uma função que vai verificar se deve inserir à direita ou à esquerda,
aí chama a respectiva função para inserir. Verifica vendo se o node anterior aponta para algo a esquerda.
*/
struct tree *insertInTree(struct tree *node, struct tree *root)
{
    if (node->left == NULL)
    {
        node = insertLeft(node, root);
        return node;
    }

   node = insertRight(node, root);
    return node;
 
}

struct tree *insertLeft(struct tree *node, struct tree *father)
{
    while()
}