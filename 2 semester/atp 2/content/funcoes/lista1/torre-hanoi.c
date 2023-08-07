#include <stdio.h>
void hanoi(int n, int o, int a, int d);
int main()
{
    int n;
    scanf("%d", &n);
    hanoi(n, 1, 2, 3);
}
void hanoi(int n, int o, int a, int d)
{
    if (n == 1)
        printf("move disco %d de %d para %d \n", n, o, d);
    else
    {
        hanoi(n - 1, o, d, a);
        printf("move disco %d de %d para %d \n", n, o, d);
        hanoi(n - 1, a, o, d);
    }
}
