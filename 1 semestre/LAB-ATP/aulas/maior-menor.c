#include<stdlib.h>
int main(){
	
	float A[3][4], maior, menor ,S[3]= {0,0,0};
	int i,j;
	for (i=0;i<3;i++){
		for (j=0;j<4;j++){
		printf("Digite A[%d][%d]: ", i,j);
		scanf("%f", &A[i][j]);
		}
	}
	menor = A[0][0];
	maior = A[0][0];
	for (i=0;i<3;i++){
		for (j=0;j<4;j++){
			if(A[i][j] < menor){
				menor = A[i][j];
			}
			if (A[i][j] > maior){
				maior = A[i][j];
			}
			S[i] = S[i] + A[i][j];
		}
		printf("\n S[%d]: %.2f", i, S[i]);
	}
	// fazer a soma de cada linha e salvar em um vetor chamado A 
	printf("\n Maior: %f \t Menor: %f", maior, menor);
	return 0;

}
