// FACA um programa que receba do usuario um arquivo texto e mostre na tela quantas ´
 //linhas esse arquivo possui.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char string[80], ch;
	int qtd_linhas = 0;
	FILE *fp;
	fp = fopen("arquivo.txt", "w");
	do
	{
	printf("\n Digite: ");
	scanf(" %[^\n]s", &string);
	fprintf(fp, "\n %s ", string);
	}while(strcmp("fim", string) != 0);
	fflush(fp);
	fclose(fp);

	fp = fopen("arquivo.txt", "r");
	if (fp == NULL)
	{
		printf("\n Arquivo não abre");
		exit(1);
	}
	while (ch != EOF) 
	{ 
		ch = getc(fp);
		if (ch == '\n')
		{	
			qtd_linhas++;
		}
	}
  printf("\n tem tudo isso de linha %d ", qtd_linhas);
	fclose(fp);
	return 0;


}
