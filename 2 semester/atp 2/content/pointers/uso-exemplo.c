#include <stdio.h>
struct Pessoa
{
    char name[64];
    int age;
};

void update(struct Pessoa *pessoa, int age)
{
    pessoa->age = age;
}
int main()
{
    struct Pessoa testando;
    update(&testando, 14);
    printf("%d", testando.age);
    return 0;
}