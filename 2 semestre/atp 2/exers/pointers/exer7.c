#include <stdio.h>
void funcao(int *a, int va, int vb);
int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("\n %d", a);
    printf("\n %d", b);
    printf("\n depois de executar a funcao: ");
    funcao(&a, a, b);
    printf("\n %d", a);
    printf("\n %d", b);
}
void funcao(int *a, int va, int vb)
{
    *a = va + vb;
}
