// 10. Considere a seguinte struct:

// Leia os dados de 10 pacientes (vetor de struct). Dado um cpf digitado pelo usu ́ario,
// identificar no vetor a pessoa detentora desse cpf, calcular e mostrar na tela o seu IMC.
// F ́ormula IMC: peso/(alutra × altura)
#include <stdio.h>
#define qtd 10 // mudar para 10 dps
typedef struct
{
    char nome[100];
    char sexo; //’m’: masculino, ’f’: feminino
    float peso;
    float altura;
    char cpf[12]; // apenas numeros

} paciente;
int main()
{
    paciente pacientes[qtd];
    float imc;
    char cpf_busca[12];
    for (int i = 0; i < qtd; i++)
    {
        printf("Digite o nome: ");
        scanf("%s", &pacientes[i].nome);
        setbuf(stdin, NULL);

        printf("\n Digite o sexo: ");
        scanf(" %c", &pacientes[i].sexo);
        printf("\n Digite o peso: ");
        scanf("%f", &pacientes[i].peso);
        printf("\n Digite a altura em cm: ");
        scanf("%d", &pacientes[i].altura);
        printf("\n Digite o cpf: ");
        scanf(" %s", &pacientes[i].cpf);
        setbuf(stdin, NULL);
    }

    printf("\n Digite o CPF para a busca: ");
    scanf(" %s", &cpf_busca);
    for (int i = 0; i < qtd; i++)
    {
        if (cpf_busca == pacientes[i].cpf)
        {
            imc = pacientes[i].peso / (pacientes[i].altura * pacientes[i].altura);
            printf("O imc do %s eh %f", pacientes[i].nome, imc);
        }
    }

    return 0;
}