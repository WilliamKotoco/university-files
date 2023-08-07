// 5. Utilizando struct, fazer um programa que permita a entrada de nome, endere ̧co e
// celular (apenas n ́umeros, sem DDD) de 5 pessoas. Imprimir os dados de cada uma das
// pessoas cadastradas. Utilize o seguinte formato de sa ́ıda de dados:
// Fulano | Rua dos Toddynhos 185, Jd Yakult | 995674235
// Goku | Rua do Kamisama 555, Planeta Vegeta | 992636789
// e assim sucessivamente.
#include <stdio.h>
#define qtd 5 // mudar para 5 depois
int main()
{
    struct modelo_pessoa
    {
        char nome[40];
        char endereco[120];
        char numero[10];
    };
    struct modelo_pessoa pessoas[qtd];

    for (int i = 0; i < qtd; i++)
    {
        printf("Digite o nome: ");
        scanf(" %[^\n]s", &pessoas[i].nome);
        setbuf(stdin, NULL);
        printf("\n Digite o endereco: ");
        scanf(" %[^\n]s", &pessoas[i].endereco);
        setbuf(stdin, NULL);

        printf("\n Digite o numero: ");
        scanf(" %[^\n]s", &pessoas[i].numero);
        setbuf(stdin, NULL);
    }

    // para mostrar agora
    for (int i = 0; i < qtd; i++)
    {
        printf("\n %s \t | %s  \t | %s", pessoas[i].nome, pessoas[i].endereco, pessoas[i].numero);
    }

    return 0;
}