// o algoritmo kmp é o algoritmo util para verificar se uma string esta
// dentro da outra. É o modo mais otimizado, existe dentro da funcao str str

void prefixos(char *p, int *pi)
{
    int k = 0, m, q;
    m = strlen(p);
    pi[0] = 0;
    for (q = 0; q < m; q++)
    {
        while (k > 0 && p[k] != p[q])
            k = pi[k - 1];
        if (p[k] == p[q])
            k++;
        p[q] = k;
    }
}
char *KMP(char *T, char *P, int *pi)
{
    int i, q = 0, n = strlen(T), m = strlen(P), Resp;
    prefixos(P, pi);
    for (i = 0; i < n; i++)
    {
        while (q > 0 && p[q] != T[i])
            q = pi[q - 1];
        if (p[q] == T[i])
            q++;
        if (q == m)
        {
            Resp = i - m + 1;
            q = pi[q - 1];
        }
    }
}