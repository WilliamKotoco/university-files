// escrever um numero e retornar seu inverso usando funcao recursiva'
#include <stdio.h>
int inverter(int num);
int main()
{
    int num;
    scanf("%d", &num);
    inverter(num);
    return 0;
}
int inverter(int num)
{
    if (num == 0)
    {
        return num;
    }
    else
    {
        printf("%d ", num % 10); // imprime a primeira casa
        num /= 10;               // joga pra casa do lado
        return inverter(num);    // rechama a funcao com os novos parametros
    }
}