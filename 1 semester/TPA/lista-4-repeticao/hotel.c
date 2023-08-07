#include<stdlib.h>
#include<stdio.h>
#define diaria 300
int main(){
	char nome[40];
	char endereco[40];
	char cidade[40];
	char estado[40];
	char fone[40];
	int dias, i, pagamento, acum_diarias, acum_pagamento;
	
	for (i = 1; i<4; i++){
	
	printf("\n Digite o nome: ");
	scanf("%s", &nome);
	printf("\nDigite o endereco: ");
	scanf("%s", &endereco);
	printf("\nDigite o estado: ");
	scanf("%s", &estado);
	printf("\nDigite o cidade: ");
	scanf("%s", &cidade);
	printf("\n Digite o fone: ");
	scanf("%s", &fone);
	
	printf("\n Digite quantos dias: ");
	scanf("%d", &dias);
	acum_diarias = acum_diarias + dias;
	
	if (dias < 15) pagamento = (dias * 20) + diaria;
	else if (dias = 15) pagamento = (dias * 14) + diaria;
	else if (dias > 15) pagamento = (dias * 12) + diaria;
	
	acum_pagamento = acum_pagamento + pagamento;
	printf("----------- %s -----------", nome);
	printf("\n total a ser pago: %d", pagamento);
	printf("\n endereco: %s", endereco);
	printf("\n cidade: %s", cidade);
	printf("\n estado: %s", estado);
	printf("\n fone: %s", fone);
	
}
	printf("\n--------------------------------------------------------------");
	printf("\n Total recebido pelo hotel: %d", acum_pagamento);
	printf("\n Total de diarias: %d", acum_diarias);
	return 0;
}
