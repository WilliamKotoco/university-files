// 9. Crie um programa que leia um vetor com os dados de 10 carros (uma struct): marca
// (m ́aximo de 20 caracteres), ano, e pre ̧co. No programa principal, leia um valor p e
// mostre as informa ̧c ̃oes de todos os carros com pre ̧co menor ou igual que p. O programa
// deve repetir esse processo at ́e que seja digitado o valor p = 0, quando o mesmo dever ́a
// ser encerrado.
#include <stdio.h>
#define qtd 3 // mudar para 10 dps
int main()
{
    struct modelo_carro
    {
        char marca[40];
        int ano;
        float preco;
    };
    struct modelo_carro carros[qtd];
    float p;
    for (int i = 0; i < qtd; i++)
    {
        printf("Digite a marca: ");
        scanf("%s", &carros[i].marca);
        printf("\n Digite o ano: ");
        scanf("%d", &carros[i].ano);
        printf("\n Digite o preco: ");
        scanf("%f", &carros[i].preco);
    }
    do
    {
        printf("\n Digite o preco para filtrar: ");
        scanf("%f", &p);
        for (int i = 0; i < qtd; i++)
        {
            if (carros[i].preco <= p)
            {
                printf("\n %s", carros[i].marca);
                printf("\n %d ", carros[i].ano);
                printf("\n %f", carros[i].preco);
                printf("\n");
            }
        }

    } while (p != 0);
    return 0;
}