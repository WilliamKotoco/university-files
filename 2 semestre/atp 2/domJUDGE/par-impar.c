#include <stdio.h>
int main()
{
    int i, N, X, Y;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%d %d", &X, &Y);
        if ((X + Y) % 2 == 0)
        {
            printf("\n A");
        }
        else
        {
            printf("\n B \n");
        }
    }
}