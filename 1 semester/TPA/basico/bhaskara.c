#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
	float a,b,c, delta,x1,x2;
	printf("Digite a, b,c: ");
	scanf("%f %f %f", &a,&b,&c);
	delta = b*b - 4*a*c;
	if (delta == 0){
		x2 = 0;
		x1 = (-b + sqrt(delta))/2*a;
	}
	else if (delta < 0){
		x1 = 0;
		x2 = 0;
		printf("Nao existem raizes reais ");
	}
	else {
		x1 = (-b + sqrt(delta))/2*a;
		x2 = (-b - sqrt(delta))/2*a;
	}
			printf("\n x1: %f\t x2: %f", x1,x2);
	return 0;
}
