#include<stdlib.h>
int main(){
	int n1, n2,n3, nreal,n4;
	
	// 9 xi
	printf("Digite um numero: ");
	scanf("%d", &n1);
	printf("\n%d anterior, %d sucessor", n1-1, n1+1);
	
	// 9 xii
	printf("\nDigite um numero: ");
	scanf("%d", &n2);
	printf("Digite um numero: ");
	scanf("%d", &n3);
	printf("foram digitados %d e %d", n2,n3);
	
	// 9 xiii
	printf("\nSoma %d", n2 + n3);
	printf("\nSubtracao %d", n2 - n3);
	printf("\nMultiplicacao %d", n2*n3);
	printf("\ndivisao %d", n2/n3);
	// xiv
	printf("\nDigite um numero real: ");
	scanf("%d", &nreal);
	printf("\n a metade do num eh %d ", (nreal/2));
	
	// 9xv
	printf("\n a media pondereada é %d", ((n1*1)+(n2*2)+(n3*3)+(nreal*4))/4);
	
	// 9 xvi
	printf("\n o %d acrescido de 10 porcento é %f", n1, n1 + (n1*0.1));
	
	printf("\n Digite um numero de 3 digitos ");
	scanf("%d", &n4);
	printf("\nPrimeiro digito: %d", n4/100);
	printf("\nSegundo digito: %d", ((n4 % 100) % 100)/10);
	printf("\nTerceiro digito: %d", ((n4 % 100) % 100) % 10);
	
	
	return 0;
}
