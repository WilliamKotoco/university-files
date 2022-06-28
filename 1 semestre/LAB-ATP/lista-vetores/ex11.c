#include <stdio.h>

int main()
{
    char cpf[21], cpfformatado[21];
    int i = 0, j = 0;

    printf("\nDigite um cpf: ");
    scanf(" %[^\n]s", cpf);

    while (cpf[i] != '\0')
    {
        if (i == 2 || i == 5)
        {
            cpfformatado[j] = cpf[i];
            cpfformatado[j + 1] = '.';
            i++;
            j += 2;
        }
        else if (i == 8)
        {
            cpfformatado[j] = cpf[i];
            cpfformatado[j + 1] = '-';
            i++;
            j += 2;
        }
        else
        {
            cpfformatado[j] = cpf[i];
            i++;
            j++;
        }
    }

    printf("\nCpf modificado: %s", cpfformatado);
    return 0;
}
