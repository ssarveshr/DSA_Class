#include<stdio.h>
#include<string.h>

void infix_postfix(char[]);
int instackp(char);
int inputp(char );
// void infix_postfix(char);

int main()
{
    char infix[10];
    printf("Enter the infix ");// (a+b)*c-d
    gets(infix);
    infix_postfix(infix);
    return 0;
}

int instackp(char symbol)
{
    switch(symbol)
    {
        case '+':
        case '-': return 2;
        case '*':
        case '/': return 4;
        case '^':
        case '$': return 5;
        case '#': return -1;
        case '(': return 0;
        default : return 8;
    }
    
}
int inputp(char symbol)
{
    switch(symbol)
    {
        case '+':
        case '-': return 2;
        case '*':
        case '/': return 4;
        case '(': return 9;
        case ')': return 0;
        case '^':
        case '$': return 5;
        case '#': return -1;
    }
}
void infix_postfix(char in[])
{
    char post[10];
    int top=-1;
    char stack[10],sym;
    stack[++top]='#';
    // top++;
    int j=0;
    int i=0;
    for(;i<strlen(in);i++)
    {
        sym=in[i];
        while(instackp(stack[top])>inputp(sym))
        {
            post[j]=stack[top--];
            j++;
        }
        if(instackp(stack[top])!=inputp(sym))
            stack[top++]=sym;
        else
            top--;
        while
    }
}