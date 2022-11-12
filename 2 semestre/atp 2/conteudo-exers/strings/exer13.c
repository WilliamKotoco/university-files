// Ler uma frase e contar quantos caracteres sao espac¸os em brancos. Lembre-se que ˜
//  uma frase e um conjunto de caracteres (vetor).
#include <stdio.h>
#include <string.h>
int espacos_branco(const char *frase);
int main()
{
    char frase[1000];
    scanf("%[^\n]s", frase);
    printf("ha %d espacos em branco", espacos_branco(frase));
    return 0;
}
int espacos_branco(const char *frase)
{
    int i, contador;
    while (frase[i] != '\0')
    {
        if (frase[i] == ' ')
            contador++;
        i++;
    }
    return contador;
}