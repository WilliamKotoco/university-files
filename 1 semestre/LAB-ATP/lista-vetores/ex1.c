/*
Faça um programa que receba um número inteiro positivo N, e que calcule e mostre
na tela a seguinte soma:
S = N + (N – 1)/2 + (N – 2)/3 + ... + 1/N
*/

#include<stdio.h>
int main(){
    int n;
    float soma, acum_soma = 0;
    printf("Digite um numero: ");
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        soma = n + ((n-i)/n+1);
        acum_soma = acum_soma + soma;
        
    }
    printf("A soma eh %2.f", soma);

    return 0;
}