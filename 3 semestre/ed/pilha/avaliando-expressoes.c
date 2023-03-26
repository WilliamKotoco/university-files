#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack
{
    int top;
    char items[100];
};

int checkValidation(char * string);
int main()
{
    char string[40];
    scanf("%s", string);
    if(checkValidation(string))
        puts("A expressão é válida!");
    else
        puts("Expressão inválida!");

}

struct stack *push(struct stack *stack, char c)
{ 
    stack->top++;
    if (stack->top == 100)
        // stack overflow, aí teria que retornar um erro aí
    stack->items[stack->top] =  c;
    return stack;


}

struct stack *pop(struct stack *stack)
{
    // impossível, nesse programa, ele dar pop com a stack vazia, então não é necessário verificar
    stack->top--;
    return stack;
}
int checkValidation( char *string)
{
    int i = 0;
    char c;
    struct stack *stack = malloc(sizeof(struct stack));
    push(stack,c);
    i++;
    while(string[i] != '\0' && stack->top != 0 )
    {
        c = string[i];
        if (c != '(' && c != '[' && c != '{')
        {
            i++;
            continue;
        }
        switch (c)
        {
            case ')':
                if(stack->top == '(')
                    stack = pop(stack);
                else 
                    return 0;
                break;
            case ']':
                if(stack->top == '[')
                    stack = pop(stack);
                else 
                    return 0;
                    break;
            case '}':
              if(stack->top == '{')
                    stack = pop(stack);
                else 
                    return 0;
                break;

            default:
                push(stack, c);
        }
        i++;
    }
    if (stack->top == 0)
        return 1;
    return 0;
}