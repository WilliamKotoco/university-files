#include<stdlib.h>
int main(){
	
	int codigo;
	printf("digite o codigo: ");
	scanf("%d", &codigo);
	switch(codigo){
		case 1: printf("nao perecivel"); break;
		case 2 ... 3: printf("perecivel"); break;
		case 5:
		case 6: printf("vestuario");break;
		case 7: printf("Higiene pessoal");break;
		case 8 ... 13: printf("limpeza e domestico");break;
		default: printf("invalido");
	}
	
	return 0;
}
