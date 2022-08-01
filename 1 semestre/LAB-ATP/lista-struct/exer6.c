// 6. Fa ̧ca um programa usando struct que controle o consumo de energia dos eletrodom ́es-
// ticos de uma residˆencia. Mais especificamente,

// (a) Criar e ler 10 eletrodom ́esticos de uma casa. Cada eletrodom ́estico dever ́a conter:
// nome (m ́aximo de 15 letras), potencial (real, em kW), e tempo ativo por dia (real,
// em horas).
// (b) Ler um tempo t (em dias), calcular e mostrar o consumo total da residˆencia, e
// os consumos relativos de cada eletrodom ́estico (consumo/consumo total) nesse
// per ́ıodo de tempo. Apresente este  ́ultimo dado em porcentagem.
#define qtd 3 // mudar para 10 depois
#include <stdio.h>
int main()
{
    struct modelo_eletrodomestico
    {
        char nome[16];
        float potencia;
        float tempo_diario;
    };
    struct modelo_eletrodomestico eletrodomesticos[qtd];
    int dias;
    float consumo_total = 0, consumo_maquina[qtd], consumo_relativo;
    for (int i = 0; i < qtd; i++)
    {
        printf("Digite o nome: ");
        scanf(" %[^\n]s", &eletrodomesticos[i].nome);
        printf("\n Digite a potencia: ");
        scanf("%f", &eletrodomesticos[i].potencia);
        printf("\n Quantas horas ativas por dia?: ");
        scanf("%f", &eletrodomesticos[i].tempo_diario);
    }
    printf("Digite os dias para calcular: ");
    scanf("%d", &dias);

    for (int i = 0; i < qtd; i++)
    {
        consumo_maquina[i] = (eletrodomesticos[i].potencia * (dias * eletrodomesticos[i].tempo_diario));
        consumo_total = consumo_total + consumo_maquina[i];
    }
    printf("Consumo total: %f", consumo_total);

    for (int i = 0; i < qtd; i++)
    {
        consumo_relativo = consumo_maquina[i] / consumo_total;
        printf("\n %s teve um consumo relativo de %f%%", eletrodomesticos[i].nome, consumo_relativo * 100);
        consumo_relativo = 0;
    }

    return 0;
}