#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i = 0;
	char number[200];
	char letra = 'A';
	FILE *sourcefile, *destinationfile;
	sourcefile = fopen("datas.dat", "r");
	if(sourcefile== NULL)
	{
		printf("Arquivo nao existe \n");
	}
	destinationfile = fopen("esquisito.dat", "w");
	while(!feof(sourcefile))
	{
		fscanf(sourcefile, "%s", &number);
		if(number[i] == ' ')
		{
			fprintf(destinationfile, "%d", letra);
			letra = (letra+1- 'A')%26 + 'A';
		}
		else
		{
			fprintf(destinationfile, "%s", number);
		}
		i++;
	}
	fclose(sourcefile);
	fclose(destinationfile);
	return 0;

}
