#include <stdio.h>
#include <string.h>
int isPalindromo(char *palavras, int i, int j);
int main()
{
    int i, j, tamanho_palavra, tamanho_palindromo, l = 0, maior_tamanho = 0;

    char palavras[2000];
    scanf("%s", palavras);
    tamanho_palavra = strlen(palavras);
    for (i = 0; i < tamanho_palavra; i++)
    {
        for (j = tamanho_palavra - 1; j >= 0; j--)
        {
            if (palavras[i] == palavras[j])
            {
                if (isPalindromo(palavras, i, j) == 1)
                {
                    tamanho_palindromo = j - i + 1;
                    if (tamanho_palindromo > maior_tamanho)
                        maior_tamanho = tamanho_palindromo;
                }
            }
        }
    }
    printf("%d\n", maior_tamanho);
    return 0;
}
int isPalindromo(char *palavras, int i, int j)
{
    if (i > j)
        return 1;
    if (palavras[i] == palavras[j])
    {
        return isPalindromo(palavras, i + 1, j - 1);
    }
    return 0;
}