// Buscar o maior número de uma árvore.
#define MAX(a,b) (((a)>(b))?(a):(b))

#include<stdio.h>
#include<stdlib.h>
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

    int findBiggest(struct tree *root)
    {
        if (root == NULL)
            return 0;
        int biggestLeft = findBiggest(root->left); // acumula os maiores da esquerda
        int biggestRight = findBiggest(root->right); // acumula os maiores da direita


        /*
        Retorna qual maior: o valor do node atual, o maior das esquerdas ou o maior das direitas
        
    */
        return MAX(root->value, MAX(biggestLeft, biggestRight)); 
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
    n1 = createNode(2);
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
        printf("O maior encontrado é %d", findBiggest(n1));


/*
                                    n1
                        n2                      n3
                                                        n4
                                                    n6
                                                        n7

*/

}