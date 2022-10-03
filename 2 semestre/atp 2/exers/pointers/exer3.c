#include <stdio.h>
int main()
{
    int a, b, *pa, *pb;
    printf("Digite duas variaveis inteiras: ");
    scanf("%d %d", &a, &b);
    pa = &a;
    pb = &b;
    if (pa > pb)
    {
        printf("pa tem o maior endereco (%p), cujo conteudo eh %d", pa, *pa);
    }
    else
    {
        printf("pb tem o maior endereco (%p), cujo conteudo eh %d", pb, *pb);
    }
}