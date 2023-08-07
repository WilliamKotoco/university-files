// exclude even nodes

#include <stdio.h>
#include <stdlib.h>
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

void printTree(struct tree *root)
{
    if (root != NULL)
    {
        printf("%d ", root->value);
        printTree(root->left);
        printTree(root->right);
    }
}

struct tree *removeEvenNodes(struct tree *root)
{
     if(root == NULL)
        return root;
    root->left = removeEvenNodes(root->left);
    root->right = removeEvenNodes(root->right);
    
    if (root->value %2 == 0)
    {
        struct tree *temp = root;
        root = root->left;
        free (temp);
    }
    return root;

    

}



int main()
{
    /*
]
    /*
        Criando manualmente apenas para testar o funcionamento da função

    */
    struct tree *n1, *n2, *n3, *n4, *n5, *n6, *n7;
    int *firstOdd;
    n1 = createNode(3);
    n2 = createNode(234);
    n3 = createNode(194);
    n4 = createNode(1905);
    n1->left = n2;
    n1->right = n3;
    n3->left = n4;

    n5 = createNode(324);
    n6 = createNode(234924);
    n7 = createNode(9);
    n4->left = n6;
    n6->right = n7;
    n2->right = n5;
    printTree(n1);
    printf("\n");
    n1 = removeEvenNodes(n1);
    printTree(n1);

    /*
                                        n1
                            n2                      n3
                                                            n4
                                                        n6
                                                            n7

    */
}