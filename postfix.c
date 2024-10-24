#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 10

int evaluate(char post[]);
void push(int token, int *top, int stack[]);
int pop(int *top, int stack[]);
int compute(int o1, int o2, char s);

int main() 
{
    char postfix[MAX];
    int res;

    printf("Enter the postfix expression: ");
    gets(postfix);
    res = evaluate(postfix);
    printf("The result is %d\n", res);
    return 0;
}

int evaluate(char post[]) 
{
    int top = -1, stack[MAX], i = 0, token, op1, op2, res;
    char symbols;

    while (post[i] != '\0') 
    {
        symbols = post[i];
        if (isdigit(symbols)) 
        {
            token = symbols - '0'; // Convert char to int
            push(token, &top, stack);
        } 
        else if (symbols == ' ' || symbols == '\n') 
        {
            // Ignore spaces and newlines
        } 
        else 
        {
            op2 = pop(&top, stack);
            op1 = pop(&top, stack);
            res = compute(op1, op2, symbols);
            push(res, &top, stack);
        }
        i++;
    }
    return pop(&top, stack);
}

void push(int token, int *top, int stack[]) 
{
    if (*top < MAX - 1) 
    {
        *top += 1;
        stack[*top] = token;
    } 
    else 
    {
        printf("Stack overflow\n");
    }
}

int pop(int *top, int stack[]) 
{
    if (*top >= 0) 
    {
        return stack[(*top)--];
    } 
    else 
    {
        printf("Stack underflow\n");
        return 0;
    }
}

int compute(int o1, int o2, char s) 
{
    switch (s) 
    {
        case '+': return (o1 + o2);
        case '-': return (o1 - o2);
        case '*': return (o1 * o2);
        case '/':if (o2 == 0)
                {
                    printf("Division by zero\n");
                    return 0;
                }
                return (o1 / o2);
        case '^': return (int)pow(o1, o2); 
        case '%':return (o1%o2);
        default:printf("Invalid operator\n");
    }
}
