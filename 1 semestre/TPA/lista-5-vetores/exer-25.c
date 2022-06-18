/*
Elaborar um programa para armazenar a série de Fibonacci, em um vetor fib, até o décimo
quinto termo. A série é formada pela sequência 1, 1, 2, 3, 5, 8, 13, 21, 34, ..., etc. Esta série é
caracterizada pela soma de um termo posterior com o seu anterior subsequente. Apresentar
o resultado armazenado em fib. */
#include <stdio.h>
int main()
{
    int fib[15], i = 1, termo, t1 = 0, t2 = 1;

    for (i = 1; i < 15; i++)
    {
        termo = t1 + t2;
        t1 = t2;
        t2 = termo;
        fib[i] = t1;
        printf("fibo %d: %d\n", i, fib[i]);
    }

    return 0;
}