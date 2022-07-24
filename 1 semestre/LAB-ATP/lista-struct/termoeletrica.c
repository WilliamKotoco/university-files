#include <stdio.h>
#define limite 110
int main()
{
    int termoeletricas[5];
    float consumo[5][5], adicional[5], acum_soma = 0, acum_soma_soma = 0,
                                       fornecimento_turbinas[5], soma_turbinas = 0, soma_adicional = 0, nova_cidade[5],
                                       potencia_excedente[5], soma_potencia_excedente = 0, soma_potencia_nova_cidade = 0;

    consumo[0][0] = 7.03;
    consumo[0][1] = 14.87;
    consumo[0][2] = 26.41;
    consumo[0][3] = 9.18;
    consumo[0][4] = 27.05;
    consumo[1][0] = 24.26;
    consumo[1][1] = 21.14;
    consumo[1][2] = 11.89;
    consumo[1][3] = 22.74;
    consumo[1][4] = 31.62;
    consumo[2][0] = 22.4;
    consumo[2][1] = 12;
    consumo[2][2] = 29.8;
    consumo[2][3] = 26.06;
    consumo[2][4] = 27.23;
    consumo[3][0] = 19;
    consumo[3][1] = 16.04;
    consumo[3][2] = 18.81;
    consumo[3][3] = 9.62;
    consumo[3][4] = 13.05;
    consumo[4][0] = 24.66;
    consumo[4][1] = 22.01;
    consumo[4][2] = 26;
    consumo[4][3] = 28.2;
    consumo[4][4] = 28.56;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            acum_soma = acum_soma + consumo[i][j];
        }
        acum_soma_soma = acum_soma_soma + acum_soma;

        printf("\n %f", acum_soma);
        if (acum_soma >= limite)
        {
            termoeletricas[i] = 1;
            adicional[i] = acum_soma - limite;
            fornecimento_turbinas[i] = limite;
            potencia_excedente[i] = 110 - adicional[i];
        }
        else
        {
            termoeletricas[i] = 0;
            adicional[i] = 0;
            fornecimento_turbinas[i] = acum_soma;
            potencia_excedente[i] = 0;
        }
        acum_soma = 0;
    }
    for (int i = 0; i < 5; i++)
    {
        soma_turbinas = soma_turbinas + fornecimento_turbinas[i];
        soma_adicional = soma_adicional + adicional[i];

        soma_potencia_excedente = soma_potencia_excedente + potencia_excedente[i];
    }
    for (int i = 0; i < 5; i++)
    {
        printf("\n cidade  %d", i + 1);
        for (int j = 0; j < 5; j++)
        {
            printf("\t %.2f ", consumo[i][j]);
        }
    }
    printf("\n Termoeletricas ativadas: ");
    for (int i = 0; i < 5; i++)
    {
        if (termoeletricas[i] == 1)
        {
            printf("\n cidade %d precisa de %f", i, adicional[i]);
        }
    }
    printf("\n Potencia necessaria para todas as cidades: %.2f", acum_soma_soma);
    printf("\n Potencia total fornecida apenas pelas turbinas: %2.f", soma_turbinas);
    printf("\n Energia adicional total fornecida pelas termoeletricas: %2.f", soma_adicional);
    printf("\n Potencia total excedente: %2.f", soma_potencia_excedente);

    for (int j = 0; j < 5; j++)
    {
        printf("\n Digite a potencia para cada regiao: ");
        scanf("%f", &nova_cidade[j]);
        soma_potencia_nova_cidade = soma_potencia_nova_cidade + nova_cidade[j];
    }
    if (soma_potencia_excedente - soma_potencia_nova_cidade >= 0)
    {
        printf("Adicionada %2.f na nova cidade ", soma_potencia_excedente - soma_potencia_nova_cidade);
    }
    else
    {
        printf("Ha uma sobrecarga de %2.f na nova cidade ", soma_potencia_excedente - soma_potencia_nova_cidade);
    }

    return 0;
}