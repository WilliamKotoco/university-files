// Construir um programa em linguagem C para controlar o saldo banc�rio de 20 clientes. Alguns dados
// importantes s�o: n�mero da conta; data de abertura da conta; cliente; saldo; e, limite especial.
// Complementar o controle das informa��es com outros dados comumente vinculados aos dados de um
// cliente/conta. Os dados pessoais de um cliente (nome, sobrenome, sexo e outros) devem ser armazenados
// em um registro cliente. Os dados de cada conta devem ser armazenados em um registro conta. Cada conta
// est� associada a um cliente. O programa deve permitir ler todos dados. Calcular e imprimir o saldo m�dio
// das mulheres, o saldo m�dio dos homens, o maior e o menor saldo entre homens e mulheres, cliente mais
// antigo, cliente com o maior limite especial, clientes com saldos negativos e listar os clientes por saldo
// banc�rio (ordem crescente).
#include <stdio.h>
#define num_clientes 3 // alterar pra 20

int main()
{
    typedef struct dados_cliente
    {
        char nome[40];
        char sobrenome[40];
        char sexo;
    } cliente;

    typedef struct conta_cliente
    {
        cliente dados;
        char numero[20];
        int dia, mes, ano;
        float saldo, limite_especial;
    } dados_bancarios;

    int i, j, mais_antigo, cont_m, cont_f, indice_limite, aux;
    dados_bancarios contas[i];
    float saldo_total_mulheres, saldo_total_homens, maior_saldo_h, maior_saldo_m,
        menor_saldo_h, menor_saldo_m, menor_ano, menor_mes, maior_limite,
        saldos[num_clientes];
    for (i = 0; i < num_clientes; i++)
    {
        printf("Preenchendo os dados pessoais ");
        printf("\n Digite o nome: ");
        scanf(" %[^\n]s", contas[i].dados.nome);
        setbuf(stdin, NULL);
        printf("\n Digite o sobrenome: ");
        scanf(" %[^\n]s", contas[i].dados.sobrenome);
        setbuf(stdin, NULL);
        printf("\n [M] para masculino e [F] para feminino: ");
        scanf(" %c", &contas[i].dados.sexo);
        setbuf(stdin, NULL);
        printf("\n Preenchendo dados da conta: ");
        printf("\n  Numero da conta: ");
        scanf(" %[^\n]s", &contas[i].numero);
        setbuf(stdin, NULL);
        printf("\n Digite o dia mes e ano, separando por espaco: ");
        scanf(" %d %d %d", &contas[i].dia, &contas[i].mes, &contas[i].ano);
        setbuf(stdin, NULL);
        printf("\n Digite o saldo: ");
        scanf(" %f", &contas[i].saldo);
        setbuf(stdin, NULL);
        printf("\n Digite o limite: ");
        scanf(" %f", &contas[i].limite_especial);
        setbuf(stdin, NULL);

        saldos[i] = contas[i].saldo;
    }
    // ordenando os saldos
    for (i = 0; i < num_clientes; i++)
    {
        for (j = i + 1; j < num_clientes; j++)
        {
            if (saldos[j] < saldos[i])
            {
                aux = saldos[i];
                saldos[i] = saldos[j];
                saldos[j] = aux;
            }
        }
    }

    // outro for para analisar os dados, para ficar bonitinho
    printf("\n Clientes com saldos negativos: ");
    for (i = 0; i < num_clientes; i++)
    {
        if (contas[i].saldo < 0)
        {
            printf("\n %s %s ", contas[i].dados.nome, contas[i].dados.sobrenome);
        }
        if (i == 0)
        {
            maior_saldo_h = 0;
            maior_saldo_m = 0;
            menor_saldo_h = 0;
            menor_saldo_m = 0;
            menor_ano = 0;
            maior_limite = 0;
        }

        if (contas[i].limite_especial > maior_limite)
        {
            maior_limite = contas[i].limite_especial;
            indice_limite = i;
        }
        if (contas[i].ano <= menor_ano)
        {
            menor_ano = contas[i].ano;
            if (contas[i].mes < menor_mes)
            {
                menor_mes = contas[i].mes;
                mais_antigo = i;
            }
        }
        if (contas[i].dados.sexo == "F" || contas[i].dados.sexo == "f")
        {
            cont_f++;
            saldo_total_mulheres = saldo_total_mulheres + contas[i].saldo;
            if (contas[i].saldo > maior_saldo_m)
            {
                maior_saldo_m = contas[i].saldo;
            }
            if (contas[i].saldo < menor_saldo_m)
            {
                menor_saldo_m = contas[i].saldo;
            }
        }
        if (contas[i].dados.sexo == "M" || contas[i].dados.sexo == "m")
        {
            cont_m++;
            saldo_total_homens = saldo_total_homens + contas[i].saldo;
            if (contas[i].saldo > maior_saldo_h)
            {
                maior_saldo_h = contas[i].saldo;
            }
            if (contas[i].saldo < menor_saldo_m)
            {
                menor_saldo_m = contas[i].saldo;
            }
        }
        printf("\n Salario medio dos homens: %f", saldo_total_homens / cont_m);
        printf("\n Salario medio das mulheres: %f", saldo_total_mulheres / cont_f);
        printf("\n O maior saldo entre os homens: %f ", maior_saldo_h);
        printf("\n O menor saldo entre os homens: %f ", menor_saldo_h);
        printf("\n O maior saldo entre as mulheres: %f ", maior_saldo_m);
        printf("\n O menor saldo entre as mulheres: %f ", menor_saldo_m);
        printf("\n O cliente mais velho eh: %s %s", contas[mais_antigo].dados.nome, contas[mais_antigo].dados.sobrenome);
        printf("\n O cliente com maior limite especial eh %s %s", contas[indice_limite].dados.nome, contas[indice_limite].dados.sobrenome);
        return 0;
    }
}
