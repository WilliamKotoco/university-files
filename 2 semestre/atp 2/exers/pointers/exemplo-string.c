#include <stdio.h>
#include <string.h>
int main()
{
    char nome[20], *ch;
    strcpy(nome, "pandora");
    ch = nome + 3;
    printf("%s", ch);

    ch = &nome[3];
    printf("\n %s", ch);
}