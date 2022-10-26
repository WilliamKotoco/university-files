// // Faca um programa que leia tres valores inteiros e chame uma funcao que receba estes 3
// // valores de entrada e retorne eles ordenados, ou seja, o menor valor na primeira variavel,
// // o segundo menor valor na variavel do meio, e o maior valor na ultima variavel. A funcao
// // deve retornar o valor 1 se os tres valores forem iguais e 0 se existirem valores diferentes. ˆ
// // Exibir os valores ordenados na tela.
// #include <stdio.h>
// void ordenacao(int *a, int *b, int *c, int va, int vb, int vc);
// int main()
// {
//     int a, b, c;
//     scanf("%d %d %d", &a, &b, &c);
//     ordenacao(&a, &b, &c, a, b, c);
//     return 0;
// }
// void ordenacao(int *a, int *b, int *c, int va, int vb, int vc)
// {
//     int aux;
//     if (*b > *a && *b < *c)
//     {
//         aux = *a;
//         *a = *c;
//         *c = aux;
//     }
//     if (*b > *a && *b > *c)
//     {
//         aux = *a;
//         *b = aux;
//         if (*a > *c)
//         {
//             *a = *b;
//         }
//         if (*a < *c)
//         {
//             *a = *c;
//             *b = *c;
//         }
//     }
// }
