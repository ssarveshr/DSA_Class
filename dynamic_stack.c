#include<stdio.h>
#include<stdlib.h>
int isfull(int,int);
int isempty(int);
void push(int,int *,int []);
int pop(int *,int,int []);
void display(int,int []);
int main()
{
    int c=1,top=-1;
    int *dstk,ele;
    dstk=(int*)malloc(c*sizeof(int));
    int ch;
    while(1)
    {
        printf("1.push\n2.pop\n3.display\n4.exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: if(isfull(top,c))
                    {
                        c*=2;
                        printf("in if c is %d\n",c);
                        dstk=(int*)realloc(dstk,c*sizeof(int));
                    }
                    printf("enter an element to be pushed in to the stack : ");
                    scanf("%d",&ele);
                    push(ele,&top,dstk);
                    break;
            case 2: if(isempty(top))
                    {
                        printf("The stack is empty\n");
                    }
                    else
                    {
                        ele=pop(&top,c,dstk);
                        printf("The deleted element of the stack is %d\n",ele);
                    }
                    break;
            case 3: if(top!=-1)
                        display(top,dstk);
                    else
                        printf("The stack is empty\n");
                    break;
            case 4: exit(0);
                    break;
            default:printf("Invalid input please try aganing \n");

        }
    }
    return 0;
}
int isfull(int t,int cap)
{
    if(t==(cap-1))
        return 1;
    return 0;
}
int isempty(int t)
{
    if(t==-1)
        return 1;
    return 0;
}
void push(int e,int *t,int s[])
{
    (*t)++;
    s[*t]=e;
}
int pop(int *t,int cap,int *s)
{
    int val=s[*t];
    (*t)--;
    s=(int*)realloc(s,(cap*sizeof(int))-1);
    return val;
}
void display(int t,int s[])
{
    for(;t>=0;t--)
        printf("%d ",s[t]);
    printf("\n");
}