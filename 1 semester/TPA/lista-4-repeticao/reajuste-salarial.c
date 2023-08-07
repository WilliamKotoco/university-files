#include<stdlib.h>
int main() {
	int stop;
	char nome[40];
	float salario, salario_reajustado;
do {
	printf("\nDigite o nome do funcionario: ");
	scanf("%s", &nome);
	printf("\n digite o salario: ");
	scanf("%f", &salario);
	
	if (salario < 500){
		salario_reajustado = salario + (salario * 0.15);
	}
	else if (salario >= 500 && salario <= 1000 ){
		salario_reajustado = salario + (salario * 0.1);
	}
	else{
		salario_reajustado = salario + (salario * 0.05);
	}
	printf("\n o funcionario %s agora recebe %.2f, antes recebia %.2f ", nome,salario_reajustado,salario);
	printf("\n Digite 0 para parar, qualquer outra coisa para continuar ");
	scanf("%d", &stop);
} while(stop != 0);
	return 0;
}
