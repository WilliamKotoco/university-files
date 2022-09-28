#include<stdio.h>
int main()
{
	char caracteres;
	FILE *fp;
	fp = fopen("arquivos.txt", "w");
	do
	{
	printf("\n Digite um caractere: ");
	scanf("%c ", &caracteres);
	putc(caracteres,fp);
	}while(caracteres != 'O');
	fclose(fp);
	return 0;
}

