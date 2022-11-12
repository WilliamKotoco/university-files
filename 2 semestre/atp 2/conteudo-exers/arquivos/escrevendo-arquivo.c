#include<stdio.h>
#include<string.h>

int main()
{
	char str[80];
	int i =0;
	FILE *fp;
	if((fp = fopen("test", "w")) == NULL) 
	{
		printf("O arquivo nao pode ser acessado");
		exit(1);
	}
	do 
	{
		printf("Digite uma string");
		scanf("%s", &str);
		strcat(str, "\n");
		fputs(str,fp);
		i++;
	}while(i<10);
	fclose(fp);
	return 0;
}
