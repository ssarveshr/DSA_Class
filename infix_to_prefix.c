#include<stdio.h>
#include<string.h>

void infix_postfix(char[]);
int in_stackpres(char);
int input_pres(char );

int main()
{
    char infix[10];
    printf("Enter the infix ");// (a+b)*c-d
    gets(infix);
    infix_postfix(infix);
    return 0;
}

int in_stackpres(char symbol)
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
int input_pres(char symbol)
{
    switch(symbol)
    {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 3;
        case '(': return 9;
        case ')': return 0;
        case '^':
        case '$': return 5;
        case '#': return -1;
        default : return 7;
    }
}
void infix_postfix(char infix[])
{
    char post[10];
    int top=-1;
    char stack[10],symbol;
    stack[++top]='#';
    // top++;
    int j=0;
    int i=0;
    for(;i<strlen(infix);i++)
    {
        symbol=infix[i];
        while(in_stackpres(stack[top])>input_pres(symbol))
        {
            post[j]=stack[top--];
            j++;
        }
        if(in_stackpres(stack[top])!=input_pres(symbol))
            stack[++top]=symbol;
        else
            top--;
    }
    while(stack[top]!='#')
    {
        post[j++]=stack[top--];
    }
    post[j]='\0';
    printf("%s\n",post);
}