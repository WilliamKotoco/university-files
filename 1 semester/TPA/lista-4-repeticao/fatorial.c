#include<stdio.h>
#include<stdlib.h>
int main(){
	int num, fat = 1, i;
	printf("digite o numero: ");
	scanf("%d", &num);
	i = num;
	while (1<num){
		fat = fat * num;
		num --;
	}
	printf("fatorial de %d eh %d ", i, fat);
	
	return 0;
}
