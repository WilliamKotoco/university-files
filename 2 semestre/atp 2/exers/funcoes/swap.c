#include <stdio.h>
void swap_ref(int *x, int *y);
void swap_val(int x, int y);
int main()
{
    int x = 10, y = 40;
    swap_val(x, y);
    printf("Chamando por valor, x: %d, y: %d", x, y);
    swap_ref(&x, &y);
    printf("\n Chamando por referencia, x: %d, y: %d", x, y);
}
void swap_val(int x, int y)
{
    int aux;
    aux = x;
    x = y;
    y = aux;
}
void swap_ref(int *x, int *y)
{
    int aux;
    aux = *x;
    *x = *y;
    *y = aux;
}