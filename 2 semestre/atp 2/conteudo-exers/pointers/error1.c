#include <stdio.h>
int main()
{
    int a = 0, b = 5, *pa, *pb, aux;
    pa = &a;
    pb = &b;
    aux = *pa;
    // aux está recebendo o conteudo de a, 0
    pa = pb; // pa recebe o endereco de pb
    pb = aux;
    printf("%d, %d ", *pa, *pb);

    // o codigo da segmentation fault porque pb está no endereco 0 (nao existe)

    // para corrigir:
    // *pa = *pb ;
    // *pb = aux;

    return 0;
}