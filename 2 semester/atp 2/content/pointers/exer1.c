#include <stdio.h>
int main()
{
    int *p, a;
    float *pf, b;
    char *pc, c;
    a = 15;
    b = 43.35;
    c = 'w';
    printf("%d %f %c", a, b, c);
    p = &a;
    pf = &b;
    pc = &c;
    *p = 34;
    *pf = 3.141414;
    *pc = 'b';
    printf("\n %d %f %c", a, b, c);
}