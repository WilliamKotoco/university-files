#include <stdio.h>
int main()
{
    int a, b;
    int *p;
    a = 10;
    p = &a;
    printf("%p", p);
    printf("\n %d", *p);
    b = 25;
    // muda o valor de a
    *p = b;
    printf("\n %d", a);
}