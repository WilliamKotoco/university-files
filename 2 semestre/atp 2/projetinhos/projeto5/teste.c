#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *fp;
    fp = fopen("bigint.dat", "w");
    for (int i = 0; i < 20000; i++)
        fprintf(fp, "%ld ", rand()%10);
}