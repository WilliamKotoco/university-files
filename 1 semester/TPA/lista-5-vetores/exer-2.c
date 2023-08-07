#include<stdio.h>
#include<stdlib.h>
#define max 10
int main(){
int num[max], i, contador_par,contador_impar ,acum_total, acumulador_par, acumulador_impar;
for (i = 0; i<max; i++){
	num[i] = rand() % 100;
	// checando par ou impar
	if (num[i] % 2 == 0){
		acumulador_par = acumulador_par + num[i];
		contador_par++;
	}
	else{
		acumulador_impar = acumulador_impar + num[i];
		contador_impar++;	
	}
	acum_total = acum_total + num[i];
	}
	printf("\n media dos %d pares existentes: %.2f ", contador_par, (float)acumulador_par/contador_par);
	printf("\n media dos %d impares existentes: %.2f", contador_impar, (float)acumulador_impar/contador_impar);
	printf("\n media de todos os numeros: %.2f", (float)acum_total/max );
	return 0;
}
		

