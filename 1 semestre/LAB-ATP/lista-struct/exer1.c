#include<stdio.h>
typdef struct horasmin{
    int horas;
    int minutos;
}
int main(){
    int min;
    horamin horamin;
    printf("Digite o numero em minutos: ");
    scanf("%d", &min);
    horamin.horas = min/60;
    horamin.minutos = min % 60;
    printf("\n Horas: %d", horamin.horas);
    printf("\n Minutos: %d", horamin.minutos);
    return 0;
}