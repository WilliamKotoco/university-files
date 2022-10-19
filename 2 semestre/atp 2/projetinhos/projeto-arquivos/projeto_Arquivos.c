#include <stdio.h>
#include <stdlib.h>
// prototipos
void check(FILE *codigos, FILE *palavras);
void modificacao(FILE *linhas, FILE *cod, FILE *palavras);
void adicionar_palavras(int, FILE *, FILE *);
void palavras_anteriores(int, FILE *, FILE *);
void escrever_palavras_restantes(FILE *, FILE *);
void escrever_codigos(FILE *, FILE *);
// A funÃ§Ã£o recebe como parametro o nome de um arquivo e apaga o conteudo prÃ©viamente escrito no mesmo.
void limpa_arquivo(char nome_arquivo[100])
{
    FILE *fpw;
    fpw = fopen(nome_arquivo, "w");
    fclose(fpw);
}

int main()
{
    FILE *linhas, *codigo, *palavras;
    linhas = fopen("linhas.dat", "w");
    codigo = fopen("codigos.dat", "r");
    palavras = fopen("palavras.dat", "r");
    limpa_arquivo("linhas.dat");
    check(codigo, palavras);
    modificacao(linhas, codigo, palavras);
    fclose(linhas);
    fclose(palavras);
    fclose(codigo);
}

void check(FILE *codigos, FILE *palavras)
{
    if (codigos == NULL && palavras == NULL)
    {
        printf("\n Nao existe algum dos arquivos");
        exit(1);
    }
}

void modificacao(FILE *linhas, FILE *codigos, FILE *palavras)
{
    int qtd_palavras, cont = 0, codigos_restantes;
    char string[200];

    while (!feof(palavras) && !(feof(codigos)))
    {
        fscanf(codigos, "%d", &qtd_palavras);
        // printf ("%d ", qtd_palavras);

        if (qtd_palavras > 0) // Se num > 0
            adicionar_palavras(qtd_palavras, palavras, linhas);

        else if (qtd_palavras == 0) // Se num == 0
            fprintf(linhas, "%d ", qtd_palavras);

        else // Se num < 0
            palavras_anteriores(qtd_palavras, palavras, linhas);

        fprintf(linhas, "\n");
    }

    while (!feof(palavras))
    {
        fscanf(palavras, "%s ", string);
        fprintf(linhas, "%s ", string);
        cont++;
        if (cont % 5 == 0)
            fprintf(linhas, "\n");
    }

    while (!feof(codigos))
    {
        fscanf(codigos, "%d ", &codigos_restantes);
        fprintf(linhas, "%d ", codigos_restantes);
    }
}

void adicionar_palavras(int qtd_palavras, FILE *palavras, FILE *linhas)
{
    int i;
    char string[200];
    for (i = 0; i < qtd_palavras; i++)
    {
        fscanf(palavras, "%s ", string);
        fprintf(linhas, "%s ", string);
    }
}

void palavras_anteriores(int qtd_palavras, FILE *palavras, FILE *linhas)
{
    int espacos = 0, i, qnt_aux = qtd_palavras * -1;
    char ch, string[200];

    do
    {
        fseek(palavras, -2, SEEK_CUR);
        fscanf(palavras, "%c", &ch);
        if (ch == ' ')
            espacos++;
    } while (espacos < qnt_aux);

    for (i = 0; i < qnt_aux; i++)
    {
        fscanf(palavras, "%s ", string);
        fprintf(linhas, "%s ", string);
    }
}
