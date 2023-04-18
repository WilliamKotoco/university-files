// Buscar um número ímpar em uma árvore não ordenada
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

    int findFirstOdd(struct tree *root)
    {
        if (root == NULL)   // Se chegar em uma folha, retorna -1
            return -1;
        if (root->value % 2 == 1)
            return root->value; // retorna o número se for ímpar


        int leftNumber = findFirstOdd(root->left);
        if(leftNumber != -1)
            return leftNumber;
        
        return findFirstOdd(root->right); // se não achou na esquerda, vai tentar pela direita
        

        /*
        É mais fácil visualizar desenhando mesmo, por código é muito difícil
        */
     
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

    printf("O primeiro ímpar encontrado é o: %d", findFirstOdd(n1));

    n5 = createNode(324);
    n6 = createNode(2349);
    n7 = createNode(39020);
    n4->left = n6;
    n6->right = n7;
    n2->right = n5;

/*
                                    n1
                        n2                      n3
                                                        n4
                                                    n6
                                                        n7

*/

}