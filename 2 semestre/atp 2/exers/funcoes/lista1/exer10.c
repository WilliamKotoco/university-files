//  Escreva uma função recursiva que determine quantas vezes um dígito K ocorre
// em um número natural N. Por exemplo, o dígito 2 ocorre 3 vezes em 762021192
#include <stdio.h>
int search_number(int, int, int);
int main()
{
    int n, k, aux = 0;
    scanf("%d %d", &n, &k);
    printf("\n %d", search_number(k, n, aux)); // busca k em n
}
int search_number(int k, int n, int aux)
{
    if (n % 10 == 0)
        return aux;
    else
    {
        if (k == n % 10)
            aux++;
        return search_number(k, n / 10, aux);
    }
}