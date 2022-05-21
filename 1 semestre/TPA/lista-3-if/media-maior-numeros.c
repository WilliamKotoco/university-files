#include<stdlib.h>
int main(){
	int a,b,c;
	float media;
	
	printf("Digite a: ");
	scanf("%d", &a);
	printf("\nDigite b: ");
	scanf("%d", &b);	
	printf("\nDigite c: ");
	scanf("%d", &c);		

	printf("\n os numeros digitados foram: ");
	printf("\n %d ", a);
	printf("\n %d ", b);
	printf("\n %d ", c);

	media = (a+b+c)/3;
	
	if (a > media || b > media || c > media){
		printf("a media nao e maior que um dos numeros digitados");
	}
	else 
		printf("\n A media  %f e maior que todos os numeros digitados", media);
			return 0;
}
