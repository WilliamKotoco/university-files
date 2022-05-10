#include<stdlib.h>
int main(){
	int a,b,c,d,e,f;
	float x;
	printf("Digite a: ");
	scanf("%d", &a);
	printf("\nDigite b: ");
	scanf("%d", &b);
	printf("\nDigite c: ");
	scanf("%d", &c);
	printf("\nDigite d: ");
	scanf("%d", &d);
	printf("\nDigite e: ");
	scanf("%d", &e);
	printf("\nDigite f: ");
	scanf("%d", &f);
	
	x =(a+ (b/c))/(d - 2* (e/f)) + 4*a;
	printf("x eh %f ", x);	
	 
	return 0;
}
