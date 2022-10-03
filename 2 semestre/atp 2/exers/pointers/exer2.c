#include <stdio.h>
int main()
{
    int a, b, *pa, *pb;
    pa = &a;
    pb = &b;
    if (pa > pb)
    {
        printf("pa e maior: %p\n", pa);
    }
    else
    {
        printf("pb e maior: %p\n", pb);
    }
}