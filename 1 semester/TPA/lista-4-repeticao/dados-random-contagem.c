#include<stdio.h>
#include<stdlib.h>
int main (){
	int i, lado, acum1 = 0 , acum2 = 0, acum3 = 0, acum4 = 0, acum5 = 0, acum6 = 0;
	
	srand(time(NULL));
	for (i=0;i<6000; i++){
		lado = 1+ rand() % 6;
		switch (lado){
			case 1: acum1++;break;
			case 2: acum2++;break;
			case 3: acum3++;break;
			case 4: acum4++;break;
			case 5: acum5++;break;
			case 6: acum6++;break;
		}
	}
	printf("\n Quantidade de vezes caída em cada numero do dado: ");
	printf("\n 1: %d ", acum1);
	printf("\n 2: %d ", acum2);
	printf("\n 3: %d ", acum3);
	printf("\n 4: %d ", acum4);
	printf("\n 5: %d ", acum5);
	printf("\n 6: %d ", acum6);



	
	return 0;
}

