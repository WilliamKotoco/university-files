#include "binary-search.h"
#include<stdlib.h>
#include<stdio.h>

int main()
{
    struct tree *root = NULL, *aux,  *existe = NULL, *nao_existe;
    root = insertion(root, 10);
    aux = insertion(root, 2);
    aux = insertion(root, 40);
    aux = insertion(root, 0);
    existe = search(root, 0);
    nao_existe = search(root, 394);
    printf("%p \n", existe);
    printf("%p \n", nao_existe); // vai mostrar nulo porque não existe
    
    in_order(root); // se imprimir crescente é porque é uma ABB

    aux = delete(root, 10);
    printf("\n");
        in_order(root); // se imprimir crescente é porque é uma ABB

}
