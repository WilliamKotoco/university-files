#include <stdio.h>

int main(){
    int letra=0, num;
    FILE *sourcefile, *destinationfile;

    sourcefile = fopen("datas.dat", "r");
	if(sourcefile == NULL)
	{
		printf("Error: Couldn't open source file");
	}
    destinationfile = fopen("esquisito.dat", "w");

    while(!(feof(sourcefile))){
        fscanf(sourcefile, "%d ", &num);
        fprintf(destinationfile, "%d%c", num, ((letra % 26) + 65));
        letra++;
    }
    fclose(sourcefile);
    fclose(destinationfile);
}