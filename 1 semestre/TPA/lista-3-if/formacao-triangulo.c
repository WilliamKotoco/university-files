#include<stdlib.h>
int main (){
	float a,b,c;
	
	printf("digite a: ");
	scanf("%f", &a);
	printf("\n digite b: ");
	scanf("%f", &b);
	printf("\n digite c: ");
	scanf("%f", &c);
	
	if (a > b+c || b > a+c || c > b+a){
		printf("o que a foda mano, nem e um triangulo");
	}
	else{
		if(a == b == c){
			printf("triangulo equilatero");
		}
		else if ( (a == b && a != c )|| (b == c && c != a) || (a == c && c!=b )){
			printf("triangulo isocseles");
		}
		else
			printf("triangulo escanelo");	
		}
	return 0;
}
