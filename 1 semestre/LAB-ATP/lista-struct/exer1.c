#include <stdio.h>
typedef struct horasmin
{
    int horas;
    int minutos;
} horamin;
int main()
{
    int min;
    horamin horamins;
    printf("Digite o numero em minutos: ");
    scanf("%d", &min);
    horamins.horas = min / 60;
    horamins.minutos = min % 60;
    printf("\n Horas: %d", horamins.horas);
    printf("\n Minutos: %d", horamins.minutos);
    return 0;
}