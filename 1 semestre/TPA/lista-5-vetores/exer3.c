#include<stdio.h>
#include<stdlib.h>
int main(){
	int i = 0,k, num, AB[10], A[5], B[5], aux[5];
	do {
		printf("digite um numero: ");
		scanf("%d", &num);
		AB[i] = num;
		i++;
		}while(i < 10 && num > 0);
		
		
	for (k=0;k<5;k++){
		A[k] = AB[k];
		B[k] = AB[k+5];
	}		
	printf("\n Valores antes de serem trocados: ");
	printf("\n Vetor A: ");
	for (k=0; k<5; k++){
		printf("\t %d", A[k]);
	}
	printf("\n Vetor B: ");
	for (k=0; k<5; k++){
		printf("\t %d", B[k]);
		aux[k] =A[k];
	}
	printf("\n =====================================");
	printf("\n Trocando os valores:");
	for (k=0, i = 0; k<5, i < 5; k++, i++){
		A[4-i] = B[0+ i];
		B[0+i] = aux[4-i];
	}
		printf("\n Vetor A: ");

	for (k=0; k<5; k++){
		printf("\t %d", A[k]);
	}
	printf("\n Vetor B: ");
	for (k=0; k<5; k++){
		printf("\t %d", B[k]);
	}
	return 0;
}
