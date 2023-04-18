// calcula a altura de uma árvore binária
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

int height(struct tree *root)
{
// altura é a distância entre a raíz e sua folha mais afastada

/*
O algoritmo é semelhante ao de contar o número de nodes, porque o algoritmo que conta
o numero de nodes vai da raíz até todas as folhas (descendo).

Nesse caso, precisamos retornar só o maior número de nodes (que é equivalente a qual lado
desceu mais) incrementando 1 para contar.
*/
    if (root == NULL)
        return 0;
    int n1 = height(root->right);
    int n2 = height(root->left);

    return n1 > n2 ? n1 +1 : n2 + 1;

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
    printf("A altura da árvore é de: %d \n", height(n1));

    n5 = createNode(324);
    n6 = createNode(2349);
    n7 = createNode(39020);
    n4->left = n6;
    n6->right = n7;
    n2->right = n5;
    printf("A altura da árvore é de: %d \n", height(n1));

/*
                                    n1
                        n2                      n3
                                                        n4
                                                    n6
                                                        n7

*/

}