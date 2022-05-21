#include<stdlib.h>
int main(){
	int codigo;
	printf("Digite o codigo: ");
	scanf("%d", &codigo);
	switch (codigo){
		case 1: printf("\n sul");break;
		case 2: printf("\n norte");break;
		case 3: printf("\n leste");break;
		case 4: printf("\n oeste"); break;
		case 5:
		case 6: printf("\n nordeste");break;
		case 7 ... 9: printf("\n sudeste");break;
		case 10:
		case 11: printf("\n centro oeste");break;
		case 12 ... 15: printf("\n nordeste");break;
		default: printf("\n importado"); break;
	}
	return 0;
}
