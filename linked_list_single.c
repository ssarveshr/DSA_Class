#include<stdio.h>
#include<stdlib.h>

typedef struct list
{
    int data;
    struct list* link;
}node;
node *getnode();
node *ins_front(int,node*);
int main()
{
    node* first=NULL;
    int ch;
    for(;;)
    {
        printf("1.insert front\n");
        printf("2.insert rear\n");
        printf("3.delete front\n");
        printf("4.delete rear\n");
        printf("5.delete specific element\n");
        printf("6.traverse\n");
        printf("7.exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:

            int ele;
            printf("Enter the element : ");
            scanf("%d",&ele);
            first=ins_front(ele,first);
            break;

            case 2:
            case 3:
        }
    }
}

node *getnode()
{
    node *temp=(node*)malloc(sizeof(node));
    if(temp==NULL)
    {
        printf("no memmory allocated \n");
        return NULL;
    }
    return temp;
}

node *ins_front(int ele,node* fir)
{
    node *new;
    new->data=ele;
    new->link=NULL;
    if(fir==NULL)
        return new;
    new->link=fir;
    return new;
}

