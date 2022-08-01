// Crie uma struct (cliente banco) que contenha os seguintes dados banc ́arios de um
// cliente: nome (string), agˆencia (inteiro), conta (inteiro), e saldo (real). Em seguida:
// (a) Leia os dados de um cliente, gravando-os em uma vari ́avel struct. Leia tamb ́em a
// opera ̧c ̃ao banc ́aria desejada pelo cliente, isto  ́e: (1) para saque, (2) para dep ́osito.
// (b) Imprimir na tela o valor atualizado ap ́os o saque (caso selecione (1)), ou o valor
// agregado final na conta ap ́os o dep ́osito (caso selecione (2)).
#include <stdio.h>
int main()
{
    struct cliente_banco
    {
        char nome[40];
        int agencia, conta;
        float saldo;
    };
    struct cliente_banco cliente;
    float valor, valor_total;
    int opcao;
    printf("Digite o nome: ");
    scanf("%s", &cliente.nome);
    printf("\n Digite a agencia: ");
    scanf("%d", &cliente.agencia);
    printf("\n Digite o numero da conta: ");
    scanf("%d", &cliente.conta);
    printf("\n Digite o saldo bancario: ");
    scanf("%f", &cliente.saldo);

    printf("\n Digite [1] para saque \n [2] para deposito\n ");
    scanf("%d", &opcao);
    printf("Digite o valor: ");
    scanf("%f", &valor);
    switch (opcao)
    {
    case 1:
        valor_total = cliente.saldo - valor;
        break;
    case 2:
        valor_total = cliente.saldo + valor;
        break;
    }
    printf("Saldo apos operacao: %2.f ", valor_total);

    return 0;
}
