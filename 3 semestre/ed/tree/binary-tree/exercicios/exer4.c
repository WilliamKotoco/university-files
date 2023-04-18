// conta somente o número de folhas
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

int number_of_leafs(struct tree *root)
{

    /*
        Basta não incrementar  quando não for folha, retorna apenas o que estava antes
    */
    if (root == NULL) // verifica se é nulo
        return 0;  
    int n1 = number_of_leafs(root->right); //
    int n2 = number_of_leafs(root->left);
    
    if (root->left == NULL && root->right == NULL)
        return (n1+n2 + 1);  // quando for folha, incrementa mais um
    return (n1+n2); 
}
int main()
{
    /*
]
    /*
    Criando manualmente apenas para testar o funcionamento da função 

    */
    struct tree *n1, *n2, *n3, *n4, *n5, *n6, *n7, *n8;
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

    printf("O número de nodes é: %d \n", number_of_leafs(n1));

    n5 = createNode(324);
    n6 = createNode(2349);
    n7 = createNode(39020);
    n8 = createNode(34);

    n4->left = n6;
    n6->right = n7;
    n2->right = n5;
    n4->right = n8;
    printf("O número de nodes é: %d \n", number_of_leafs(n1));

/*
                                    n1
                        n2                      n3
                                                        n4
                                                    n6          n8
                                                        n7

*/

}