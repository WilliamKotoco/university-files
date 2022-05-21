#include<stdlib.h>
int main(){
	int a,b,c;
	printf("digite a: ");
	scanf("%d", &a);
	printf("\ndigite b: ");
	scanf("%d", &b);
	printf("\ndigite c: ");
	scanf("%d", &c);

	if (a > b && a > c){
		if (c>b) printf("ordem: %d  %d  %d", a,c,b);	
		else printf("ordem: %d  %d  %d", a,b,c);
		}
	else if(b > a && b > c ){
		if (a>c) printf("ordem: %d  %d  %d", b,a,c);
		else printf("ordem: %d  %d  %d", b,c,a);
 	}
	else if(c>a && c>b){
		if (a>b) printf("ordem: %d  %d  %d", c,a,b);
		else printf("ordem: %d  %d  %d", c,b,a);
	}

	return 0;
}
