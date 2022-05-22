#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
	int i = 1, termo, t1 = 0,t2 = 1;
	
	while (i<=15){	
	termo = t1 + t2;
	t1 = t2;
	t2 = termo;

	printf("\n %d", t1);
		i++;
	}
	
	return 0;
}
