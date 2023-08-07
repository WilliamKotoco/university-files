#include<stdlib.h>
#define idade 90
int main(){
//	const int idade;
//	printf("Digite a idade: ");
//	scanf("%d", &idade);
	
	if (idade > 18 && idade < 70){
		printf("\n pode dirigir");
	}
	else if (idade > 18 && idade > 70){
		printf("Pode aposentar");
	}
	else{
		printf("pode fazer nada");
	}
		return 0;
}
