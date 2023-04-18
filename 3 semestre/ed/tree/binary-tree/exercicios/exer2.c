// contar o número de nós em uma árvore binária 
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

int number_of_nodes(struct tree *root)
{

    /*
     O backtracking é feito por meio da recursao.
     A árvore vai descendo até encontrar uma folha (árvore sem nós) e depois vai "subindo" 
     com os return (que retornam sempre +1 ao valor q era anteriormente)
    */
    if (root == NULL) // verifica se é nulo
        return 0;  // não incrementa, ou seja, não conta
    int n1 = number_of_nodes(root->right); //
    int n2 = number_of_nodes(root->left);
    
    return (n1+n2 + 1);  // Incrementa +1 no node e 
}
int main()
{
    /*
]
    /*
    Criando manualmente apenas para testar o funcionamento da função de contar nodes
    visto que o número de nós independe da arquitetura da arvore
    */
    struct tree *n1, *n2, *n3, *n4, *n5, *n6, *n7;
    n1 = createNode(2);
    n2 = createNode(234);
    n3 = createNode(194);
    n4 = createNode(1905);
    n1->left = n2;
    n1->right = n3;
    n3->left = n4;

    printf("O número de nodes é: %d \n", number_of_nodes(n1));

    n5 = createNode(324);
    n6 = createNode(2349);
    n7 = createNode(39020);
    n4->left = n6;
    n6->right = n7;
    n2->right = n5;
    printf("O número de nodes é: %d \n", number_of_nodes(n1));

/*
                                    n1
                        n2                      n3
                                                        n4
                                                    n6
                                                        n7

*/

}