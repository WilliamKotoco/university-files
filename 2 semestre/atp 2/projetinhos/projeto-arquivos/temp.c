#include <stdio.h>

void modificacao(FILE *linhas, FILE *cod, FILE *palavras);
long int ler_tamanho(FILE *palavras);
int qtd_caracteres(FILE *palavras, int qtd_palavras);
int main()
{
    FILE *linhas, *cod, *palavras;
    linhas = fopen("linhas.dat", "w");
    cod = fopen("codigos.dat", "r");
    palavras = fopen("palavras.dat", "r");
    modificacao(linhas, cod, palavras);
    fclose(linhas);
    fclose(cod);
    fclose(palavras);
    return 0;
}
void modificacao(FILE *linhas, FILE *cod, FILE *palavras)
{
    int N, qtd_palavras, contador, acum = 0;
    long int tamanho = ler_tamanho(palavras);
    char string[tamanho];
    // verificacao para ter CERTEZA que nao vai alocar menos dependendo do codigo
    printf("\n %d", tamanho);
    while (!(feof(palavras)) && !(feof(cod)))
    // os dois arquivos devem ser lidos até o final
    {

        fscanf(cod, "%d", &qtd_palavras);

        // o fscanf lê até encontrar um espaço em branco. A cada chamada, o fscanf avança para o prox espaço em branco.
        printf("\n %d", qtd_palavras);

        N = qtd_caracteres(palavras, qtd_palavras);
        acum = acum + N;
        printf("\n %d", N);
        fgets(string, N + 1, palavras);

        printf("\n %s", string);

        fprintf(linhas, "%s \n", string);
        fseek(palavras, acum, SEEK_CUR);
    }
    printf("\n teste");
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
int qtd_caracteres(FILE *palavras, int qtd_palavras)
{
    // conta quantos caracteres tem nas N proximas palavras
    int qtd_espacos = 0, qtd_caracteres = 0;
    char ch;
    do
    {
        ch = getc(palavras);
        if (ch == ' ')
        {
            qtd_espacos++;
        }
        qtd_caracteres++;
    } while (qtd_espacos < qtd_palavras);
    fseek(palavras, -qtd_caracteres, SEEK_CUR);
    return qtd_caracteres;
}