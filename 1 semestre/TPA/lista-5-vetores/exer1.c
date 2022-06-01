#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define x 2
#define y 4
int main (){
	int i,v[] = {2,6,8,3,10,9,1,21,33,14};
	printf(" \n a) %d", v[x+1]);
	printf("\n b) %d", v[x+2]);
	printf("\n c) %d", v[x+3]);
	printf("\n d) %d", v[y*1]);
	printf("\n e) %d", v[x*3]);
	printf("\n f) %d", v[x*2]);
	printf("\n g) %d", v[x*5]);
	printf("\n h) %d", v[v[x+y]]);
	printf("\n i) %d", v[x+y]);
	//printf("\n j) %d", v[8 - V[2]]);
	// nao sei se foi erro de digitacao ou se foi de proposito xD
	printf("\n j) ERRO");
	printf("\n k) %d", v[v[4]]);
	printf("\n l) %d", v[v[v[7]]]);
	printf("\n m) %d", v[v[1]*v[4]]);
	printf('\n n) %d', v[x+4]);
	
	return 0;
}
