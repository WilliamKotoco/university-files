#include <stdio.h>
#include <stdlib.h>

void modificacao(FILE *linhas, FILE *cod, FILE *palavras);
long int ler_tamanho(FILE *palavras);
void check(FILE *cod, FILE *palavras);

int main()
{
    FILE *linhas, *cod, *palavras;
    linhas = fopen("linhas.dat", "w");
    cod = fopen("codigos.dat", "r");
    palavras = fopen("palavras.dat", "r");
    check(cod, palavras);
    modificacao(linhas, cod, palavras);
    fclose(linhas);
    fclose(cod);
    fclose(palavras);
    return 0;
}
void modificacao(FILE *linhas, FILE *cod, FILE *palavras)
{
    int qtd_palavras, i, num_caracteres;
    long int tamanho = ler_tamanho(palavras);
    char string[tamanho];

    printf("\n %d", tamanho);

    while (!(feof(palavras)) && !(feof(cod)))
    // os dois arquivos devem ser lidos até o final
    {
        fscanf(cod, "%d", &qtd_palavras);

        // o fscanf lê até encontrar um espaço em branco. A cada chamada, o fscanf avança para o prox espaço em branco.
        if (qtd_palavras > 0)
        {
            for (i = 0; i < qtd_palavras; i++)
            {
                fscanf(palavras, "%s", string);
                fprintf(linhas, "%s ", string);
            }
        }
        else if (qtd_palavras == 0)
        {
            fprintf(linhas, "%d", qtd_palavras);
        }
        else
        {
        }
        fprintf(linhas, "\n");
        if (feof(palavras) && !(feof(cod)))
        {
            while (!feof(cod))
            {
                fscanf(cod, "%d", &qtd_palavras);
                fprintf(linhas, "%d ", qtd_palavras);
            }
        }

        if (feof(cod) && !feof(palavras))
        {
            while (!(feof(palavras)))
            {
                for (int i = 0; i < 5; i++)
                {
                    fscanf(palavras, "%s", string);
                    fprintf(linhas, "%s ", string);
                    if (feof(palavras))
                    {
                        break;
                    }
                }
                fprintf(linhas, "\n ");
            }
        }
    }
}

long int ler_tamanho(FILE *palavras)
{

    // a funcao le o tamanho do arquivos palavras
    long int tamanho;
    fseek(palavras, 0, SEEK_END);
    tamanho = ftell(palavras);
    rewind(palavras);
    return tamanho;
}
void check(FILE *cod, FILE *palavras)
{
    if (cod == NULL)
    {
        printf("\n Nao existe o cod");
        exit(1);
    }
    else if (palavras == NULL)
    {
        printf("\n Nao existe o palavras");
        exit(1);
    }
}