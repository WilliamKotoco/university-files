// Escreva um algoritmo que leia uma string cpf[21] apenas com valores numéricos de um CPF(ex: 36813486211)
// .Em seguida, formate essa string com pontos e traço, salvando seu conteúdo em uma nova string
// cpfformatado[21] (ex: digitou-se 36813486211, então a formatação final deverá ser: 368.134.862-11).
#include <stdio.h>
#include <string.h>
int main()
{
    char cpf[21], cpfformatado[21];
    printf("Digite o CPF, sem formatacao: ");
    scanf("%s", &cpf);
    for (int i = 0; i < strlen(cpf) + 2; i++)
    {
        cpfformatado[i] = cpf[i];
        if (i % 3 == 0 && i != 0)
        {
            cpfformatado[i] = " . ";
        }
    }
    printf("CPF formatado: %s", cpfformatado);
    // ver pilha acho que ajudaria
    return 0;
}
