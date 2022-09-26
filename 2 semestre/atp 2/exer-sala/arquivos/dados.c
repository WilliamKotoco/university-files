#include<stdio.h>
#include<time.h>
int main()
{
        srand(time(NULL));
        int i,k,n=1;
        FILE *fp;
        printf("Digite k \n: ");
        scanf("%d", &k);
        for(i=0;i<k;i++)
                {
                n = n*10;
                }
        // funcao para dar a potencia
              fp = fopen("datas.dat", "w");
              if(ferror(fp)) printf("\n erro");
	    for (i=0; i<n; i++)
	     {
              	fprintf(fp, "%d ",(rand()/2)*2);
	     }			
               fclose(fp);
               return 0;
 }
