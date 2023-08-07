/* o programa deve ler decimal e converter em romano e converter romano em decimal
Lembrando que: L = 50, C = 100 , D = 500, M = 1000

LXXVI = 76
XL = 40 (quando vem um menor antes, subtrai o segundo pelo primeiro)

 os numeros romanos sao de 5 em 5

  somar todos os nÂ´umeros
romanos que foram convertidos para decimais, imprimindo esse total no final.

 */
#include <stdio.h>
#include <string.h>
void opcoes(int n);
void num_romano();
int num_decimal();
int conversao_para_decimal(char letra);
void conversao_para_romano(int num);

int main()
{
    int n;
    scanf("%d", &n);
    opcoes(n);
    return 0;
}
void opcoes(int n)
{
    int i, c, acum_romano = 0, decimal;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &c);
        if (c == 1)
        {
            // entra na funcao para converter o romano para decimal
            decimal = num_decimal();
            printf("%d \n", decimal);
            acum_romano += decimal;
        }
        if (c == 2)
        {
            // entra na funcao de converter o decimal para romano
            num_romano();
        }
    }
    printf("%d", acum_romano);
}

void num_romano() // const char Ã© a maneira de criar uma funcao de string
{
    int num;
    // char numero_romano[20];
    scanf("%d", &num);
    conversao_para_romano(num);
    // return numero_romano;
}
void conversao_para_romano(int num)
{
    char numero_romano[20];
    while (num != 0)
    {

        if (num >= 1000)
        {
            printf("M");
            // strcat(numero_romano, "M");
            num -= 1000;
        }

        else if (num >= 900)
        {
            printf("CM");
            // strcat(numero_romano, "CM");
            num -= 900;
        }

        else if (num >= 500)
        {
            printf("D");
            // strcat(numero_romano, "D");
            num -= 500;
        }

        else if (num >= 400)
        {
            printf("CD");
            // strcat(numero_romano, "CD");

            num -= 400;
        }

        else if (num >= 100)
        {
            printf("C");
            // strcat(numero_romano, "C");

            num -= 100;
        }

        else if (num >= 90)
        {
            printf("XC");
            // strcat(numero_romano, "XC");

            num -= 90;
        }

        else if (num >= 50)
        {
            printf("L");
            // strcat(numero_romano, "L");

            num -= 50;
        }

        else if (num >= 40)
        {
            printf("XL");
            // strcat(numero_romano, "XL");

            num -= 40;
        }

        else if (num >= 10)
        {
            printf("X");
            // strcat(numero_romano, "X");

            num -= 10;
        }

        else if (num >= 9)
        {
            printf("IX");
            // strcat(numero_romano, "IX");

            num -= 9;
        }

        else if (num >= 5)
        {
            printf("V");
            // strcat(numero_romano, "V");

            num -= 5;
        }

        else if (num >= 4)
        {
            printf("IV");
            // strcat(numero_romano, "IV");

            num -= 4;
        }

        else if (num >= 1)
        {
            printf("I");
            // strcat(numero_romano, "I");

            num -= 1;
        }
    }
    printf("\n");
}
int num_decimal()
// funcao que recebe o romano e retorna decimal
{
    // printf("\n entrou no num decimal");
    int decimal, i = 0, romano_atual, romano_depois;
    char numero_romano[20];
    scanf("%s", numero_romano);
    decimal = 0;
    while (numero_romano[i] != '\0')
    {

        romano_atual = conversao_para_decimal(numero_romano[i]);
        romano_depois = conversao_para_decimal(numero_romano[i + 1]);

        if (romano_atual >= romano_depois)
        {
            // printf("\n entrou no if maior");
            decimal = decimal + romano_atual;
        }
        else if (romano_atual < romano_depois)
        {
            // printf("\n entrou no if menor");

            decimal = decimal + (romano_depois - romano_atual);
            i++;
            /* esse incremento do i Ã© pra garantir que ele nao vai passar porr romano_depois na proxima execucao
            , visto que ja foi feita a soma no decimal com esse numero
            */
        }
        i++;
    }
    return decimal;
}
int conversao_para_decimal(char letra)
{
    // printf("\n t4");
    int numero = 0;
    switch (letra)
    {
    case 'I':
        numero = 1;
        break;
    case 'V':
        numero = 5;
        break;
    case 'X':
        numero = 10;
        break;
    case 'L':
        numero = 50;
        break;
    case 'C':
        numero = 100;
        break;
    case 'D':
        numero = 500;
        break;
    case 'M':
        numero = 1000;
        break;
    case '\0':
        numero = 0;
        break;
    }
    return numero;
}