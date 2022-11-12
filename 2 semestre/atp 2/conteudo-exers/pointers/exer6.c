#include <stdio.h>
int soma(int *a, int *b, int va, int vb);
int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d ", soma(&a, &b, a, b));
    printf("\n %d", a);
    printf("\n %d", b);
    return 0;
}
int soma(int *a, int *b, int va, int vb)
{
    int x;
    *a = 2 * va;
    *b = 2 * vb;
    x = *a + *b;
    return x;
}