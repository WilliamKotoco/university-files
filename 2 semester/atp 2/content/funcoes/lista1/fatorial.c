#include <stdio.h>
int fatorial(int number);
int main()

{
    int number;
    scanf("%d", &number);
    printf("%d", fatorial(number));
}
int fatorial(int number)
{
    if (number == 0)
        return 1;
    else
        return (number * fatorial(number - 1));
}