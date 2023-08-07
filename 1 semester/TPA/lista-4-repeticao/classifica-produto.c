#include<stdio.h>
#include<stdlib.h>
int main(){
	int codigo, stop;
	do {	
	printf("digite o codigo: ");
	scanf("%d", &codigo);
	switch(codigo){
		case 1: printf("\nnao perecivel"); break;
		case 2 ... 3: printf("\nperecivel"); break;
		case 5:
		case 6: printf("\nvestuario");break;
		case 7: printf("\nHigiene pessoal");break;
		case 8 ... 13: printf("\nlimpeza e domestico");break;
		default: printf("\ninvalido");
	}
	printf("\ndigite 0 para parar, qualquer outra coisa para continuar: ");
	scanf("%d", &stop);
	
} while(stop !=0);
return 0;
}
