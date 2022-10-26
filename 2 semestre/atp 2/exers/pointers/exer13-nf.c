// . Elabore uma func¸ao que receba duas strings como parametros e verifique se a segunda ˆ
// string ocorre dentro da primeira. Use aritmetica de ponteiros para acessar os caracteres ´
// das strings.
#include <stdio.h>
#include <string.h>
int comparing(const char *str1, const char *str2);
int main()
{
    int resp;
    char str1[60], str2[30];
    scanf("%s %s", str1, str2);
    resp = comparing(str1, str2);
    return 0;
}
int comparing(const char *str1, const char *str2)
{
    int size_str1 = strlen(str1), i, cont = 0, sizestr2 = strlen(str2);
    for (i = 0; i < size_str1; i++)
    {
        *(str1[i]) == *(str2[i]);
    }
}
