#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
    int qtd, step, i, j,l, p,m;
    scanf("%d", &qtd);
    char words[qtd][50];
    char value[50];
    for (i=0; i < qtd; i++)
        scanf("%s", words[i]);
     /* pegando a menor potencia de dois até o numero qtd/4, formula que usa logaritmo */
    p = (int)log2(qtd/4);
    step = (int)pow(2,p);

    while(step >= 1)
    {

    for(l=0; l<step; l++)
    {
        for (i =  l +step; i< qtd; i=i+step)
        {
            strcpy(value, words[i]);
            j = i;
            while(j-step >= 0 && strcmp(words[j-step], value) > 0)
            {
                strcpy(words[j], words[j-step]);
                j = j - step;
            }
            strcpy(words[j], value);
        }
    }
     for (m = 0; m < qtd; m++)
    {
        printf("%s ", words[m]);
    }
        step = step/2;
        printf("\n");

    }
        
   
    
    return 0;   
}