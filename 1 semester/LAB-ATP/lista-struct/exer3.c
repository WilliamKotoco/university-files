//3. Crie uma struct capaz de armazenar datas com trˆes campos do tipo inteiro (dia, mˆes
//e ano). Em seguida, fa ¸ca um programa que leia cada um dos campos de uma struct do
//tipo acima e que imprima na tela a seguinte formata ¸c ~ao de data:
// dia/mˆes por extenso/ano (Exemplo: 10/julho/2022).
#include <stdio.h>
int main(){
	struct data{
		int dia, mes, ano;
	};
	;
	struct data dia;
	printf("Digite o dia mes e o ano, separando por espaco: ");
	scanf("%d %d %d", &dia.dia, &dia.mes, &dia.ano);
	printf("O dia digitado: \n");
	switch(dia.mes){
		case 1: printf(" %d janeiro %d", dia.dia,  dia.ano); break; 
		case 2: printf(" %d fevereiro %d", dia.dia,  dia.ano); break; 
		case 3:printf(" %d marco  %d", dia.dia,  dia.ano); break; 
		case 4:printf(" %d abril  %d", dia.dia, dia.ano); break; 
		case 5:printf(" %d maio %d", dia.dia, dia.ano); break; 
		case 6:printf(" %d junho %d", dia.dia,  dia.ano); break; 
		case 7: printf(" %d julho %d", dia.dia, dia.ano); break; 
		case 8:printf(" %d agosto %d", dia.dia, dia.ano); break; 
		case 9:printf(" %d  setembro %d", dia.dia,  dia.ano); break; 
		case 10:printf(" %d outubro %d", dia.dia,  dia.ano); break; 
		case 11:printf(" %d novembro %d", dia.dia, dia.ano); break; 
		case 12:printf(" %d dezembro %d", dia.dia, dia.ano); break; 
	}
	
	
			
	return 0;
}

