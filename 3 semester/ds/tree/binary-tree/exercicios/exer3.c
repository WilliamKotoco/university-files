// conta o número de nós que não sao folhas
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

int numberOfNotLeafs(struct tree *root)
{

    /*
     exer2.c explica o funcionamento de uma função para contar todas as nodes

    Para não contar as folhas, basta também retornar 0 (ou seja, NÃO CONTAR) quando o nó for uma folha
    , o que é verificado dentro do if

    */
    if (root == NULL || (root->left == NULL && root->right == NULL) )
        return 0; // não incrementa, ou seja, não conta
    int n1 = numberOfNotLeafs(root->right); //
    int n2 = numberOfNotLeafs(root->left);
    
    return (n1+n2 +1 ); 
} 
int main()
{
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

    printf("O número de nodes que  não são folhas é: %d \n", numberOfNotLeafs(n1));

    n5 = createNode(324);
    n6 = createNode(2349);
    n7 = createNode(39020);
    n4->left = n6;
    n6->right = n7;
    n2->right = n5;
    printf("O número de nodes que não são folhas é: %d \n", numberOfNotLeafs(n1));

/*
                                    n1
                        n2    
                            n5                  n3
                                            n4
                                         n6
                                                n7

*/

}