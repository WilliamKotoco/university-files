#include <stdio.h>
void display(int t[]);
int main()
{
    int t[10], i;
    for (i = 0; i < 10; i++)
        t[i] = i;
    display(t);
    printf("\n ================================================");

    return 0;
}
void display(int t[])
{
    int i;
    for (i = 0; i < 10; i++)
    {
        printf("\n %d ", t[i]);
    }
}
