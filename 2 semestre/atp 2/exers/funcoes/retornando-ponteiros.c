#include <stdio.h>
char *pointer(char c, char *s);

int main()
{
    char *p, ch;
    char palavra[50];
    scanf("%s", &palavra);
    ch = getchar();
    *p = pointer(ch, palavra);
    if (*p)
    {
        printf("\n Encontrou %s , no %p", p, p);
    }
    return 0;
}
char *pointer(char c, char *s)
{
    while (c != *s)
        s++;
    return (s);
}