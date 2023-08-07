// 4. Considerando a struct do Algoritmo 2 para representar um n �umero complexo, imple-
// mente um programa que calcule:
//
//(a) a soma entre dois n �umeros complexos;
//(b) o produto entre eles;
//(c) o m �odulo de um n �umero complexo;
//(d) o conjugado de um n �umero complexo;
//(e) o �angulo (argumento) de um n �umero complexo.
// Defini �c ~ao da struct numero �complexo�
#include <stdio.h>
#import <math.h>
typedef struct complexo
{
	float re;
	float im;
} complexo;
int main()
{
	complexo n1, n2, soma, produto;
	float modulo, conjulgado;

	printf("Digite a parte real: ");
	scanf("%f", &n1.re);
	prinf("\n Digite a parte imaginaria: ");
	scanf("%f", &n1.im);
	printf("\n outro numero: ");
	printf("\n Digite a parte real: ");
	scanf("%f", &n2.re);
	prinf("\n Digite a parte imaginaria: ");
	scanf("%f", &n2.im);

	// soma
	soma.re = n1.re + n2.re;
	soma.im = n1.im + n2.im;

	// produto
	produto.re = (n1.re * n2.re + n1.re * n2.im);
	produto.im = +(n1.im * n2.re + n1.im * n2.im);

	// modulo
	modulo = sqrt(pow(n1.re, 2) + pow(n1.im, 2));

	// conjulgado
	conjulgado = n1.re(-1 * n1.im);

	return 0;
}
