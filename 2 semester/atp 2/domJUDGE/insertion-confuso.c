#include<stdio.h>
#include<stdlib.h>
int main()
{
 int qtd;
 int i, j, m,n,k;
 double aux1,aux2;
 scanf("%d %d", &qtd, &k);
 double vet[qtd];
 for (int a = 0; a < qtd; a++)
 {
    scanf("%lf", &vet[a]);
 }
 for (i=1; i <= k; i++)
 {
    aux1 = vet[i];
    j = i;
    while(j>0 && vet[j-1] > aux1)
    {
        vet[j] = vet[j-1];
        j--;
    }
    vet[j] = aux1;
 }



 for(m = k+1; m < qtd; m++)
 {
    aux2 = vet[m];
    n = m;
    while (n > 0 && vet[n-1] < aux2)
    {
        vet[n] = vet[n-1];
        n--;
    }
    vet[n] = aux2;
 }
 

 for (int e =0; e < qtd; e++)
 {
    printf("%.3lf ", vet[e]);
 }

     return 0;
} 