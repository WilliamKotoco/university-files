// preencher 5 carros e 5 consumos (sem usar struct) e depois ver qual carro tem o menor consumo
// e ver quantos litros cada um consome a cada 1000km
#include <stdio.h>
#include <string.h>
const char *mais_economico(char *str, int *consumo);
int main()
{
    int i, j, consumo[5];
    char carros[5][40];
    for (i = 0; i < 5; i++)
    {

        printf("\n Digite o nome do carro: ");
        scanf("%s", carros[i]);
        printf("\n Digite o consumo: ");
        scanf("%d", &consumo[i]);
    }
    printf("o mais economico e o %s", mais_economico(carros, consumo));
    // qtd_consumo(carros, consumo);
}
const char *mais_economico(char *str, int *consumo)
{
    int i, menor_consumo, indice;
    for (i = 0; i < 5; i++)
    {
        if (i == 0)
            menor_consumo = consumo[i];
        else
        {
            if (consumo[i] < menor_consumo)
            {
                menor_consumo = consumo[i];
                indice = i;
            }
        }
    }
    return str[indice];
}
