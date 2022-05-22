#include<stdlib.h>
#include<stdio.h>
int main(){
	int num, x, i = 0;
	printf("digite o numero: ");
	scanf("%d", &num);
	 while(i < 11){
	 	x = num * i;
	 	printf("\n %d x %d = %d", num,i,x);
	 	i++;
	 }
	
	
	return  0;
}
