#include <stdio.h>
#include <string.h>
#define qtd 10
int main()
{
    int i, idade, mais_velho, mais_novo;
    char nome[40], older[40], newer[40];
    for (i = 0; i < qtd; i++)
    {
        scanf("%s %d", nome, &idade);
        if (i == 0)
        {
            mais_velho = idade;
            mais_novo = idade;
        }
        else
        {
            if (idade > mais_velho)
            {
                mais_velho = idade;
                strcpy(older, nome);
            }
            else if (idade < mais_novo)
            {
                mais_novo = idade;
                strcpy(newer, nome);
            }
        }
    }
    printf("\n O mais novo eh %s com %d anos", newer, mais_novo);
    printf("\n O mais velho eh %s com %d anos", older, mais_velho);
    return 0;
}