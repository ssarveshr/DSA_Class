#include<stdio.h>
#include<stdlib.h>
#define max 5
int isfull(int);
int isempty(int);
void cenqueue(int,int *,int *,int []);
int cdequeue(int *,int *,int []);
void display(int,int,int []);
int main()
{
    int cq[max];
    int front=0,rear=-1,ch,count=0;
    while(1)
    {
        printf("1.enqueue\n2.dequeue\n3.display\n4.exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: if(isfull(count))
                        printf("circular queue is full\n");
                    else
                    {
                        int ele;
                        printf("Enter the element to be inserted in the circular queue : ");
                        scanf("%d",&ele);
                        cenqueue(ele,&rear,&count,cq);
                    }
                    break;
            case 2: if(isempty(count))
                        printf("circular queue is empty\n");
                    else
                    {
                        int ele;
                        ele=cdequeue(&front,&count,cq);
                        printf("The deleted element from the circular queue is %d\n",ele);
                    }
                    break;
            case 3: // sir told he will write the code;
                    break;
            case 4: exit(0);
            default:printf("Invalid choice! please try again\n")   ;    
                    break;
        }
    }
    return 0;
}
int isfull(int a)
{
    if(a==max)
        return 1;
    return 0;
}
int isempty(int a)
{
    if(a==0)
        return 1;
    return 0;
}
void cenqueue(int e,int *r,int *c,int q[])
{
    (*r)=((*r)+1)%max;
    q[*r]=e;
    (*c)++;
}
int cdequeue(int *r,int *c,int q[])
{
    int val=q[(*r)];
    (*r)=((*r+1))%max;
    (*c)--;
    return val;
}
// void display(int f, int r,int q[])
// {
//     for(;f<r+1;f++)
//         printf("%d ",q[f]);
//     printf("\n");
// }
