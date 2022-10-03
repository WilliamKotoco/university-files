#include <stdio.h>
void trocar_valores(int *x, int *y);
int main()
{
    int x, y;
    printf("Digite dois numeros: ");
    scanf("%d %d", &x, &y);
    trocar_valores(&x, &y);
    printf("%d %d", x, y);
}
void trocar_valores(int *x, int *y)
{
    int aux;
    if (*x < *y)
    {
        aux = *y;
        *y = *x;
        *x = aux;
    }
}
