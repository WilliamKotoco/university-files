// verify if a tree is bst or not
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct tree
{
    int value;
    struct tree *left;
    struct tree *right;
};

struct tree *createNode(int value)
{
    struct tree *node = malloc(sizeof(struct tree));
    node->value = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

struct tree *is_bst(struct tree *node, int *flag)
{

}

int main()
{
    int flag;
    /*
]
    /*
    Criando manualmente apenas para testar o funcionamento da função
    */
    struct tree *n1, *n2, *n3, *n4, *n5, *n6, *n7;
    n1 = createNode(2);
    n2 = createNode(234);
    n3 = createNode(194);
    n4 = createNode(1905);
    n1->left = n2;
    n1->right = n3;
    n3->left = n4;
    /*
        n1
    n2          n3
                    n4

    */
    n1 = is_bst_(n1, &flag);
result:
        printf("Não é bst");
    return 0;
}