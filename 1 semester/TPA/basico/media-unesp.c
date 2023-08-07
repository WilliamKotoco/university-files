#include <stdio.h>
int main(){
	int faltas;
	float media, p1,p2, T; 
	printf("Digite a primeira nota: ");
	scanf("%f", &p1);
	printf("\nDigite a segunda nota: ");
	scanf("%f", &p2);
	printf("\nDigite a nota do trabalho : ");
	scanf("%f", &T);
	printf("\nDigite a quantidade de faltas: ");
	scanf("%d", &faltas);
	
	media = (p1 + p2 + T)/3;
	/*
	i'd rather kill the one responsible for falling stars at night
	*/
	if (media >= 5 && faltas < 10) 
		printf("Aprovado! Media: %f ", media);
		
	else 
	printf("Reprovado! com media %f",media);
	
}
