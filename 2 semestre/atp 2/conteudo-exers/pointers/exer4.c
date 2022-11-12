#include <stdio.h>
void swap_ref(int *x, int *y);
int main()
{
    int x, y;
    printf("Digite dois numeros: ");
    scanf("%d %d", &x, &y);
    swap_ref(&x, &y);
    printf("\n Chamando por referencia, x: %d, y: %d", x, y);
}

void swap_ref(int *x, int *y)
{
    int aux;
    aux = *x;
    *x = *y;
    *y = aux;
}