
#include<stdio.h>
#include<stdlib.h>

typedef struct list
{
    int data;
    struct list* link;
}node;

node *getnode();
node *ins_front(int,node*);
node *ins_rear(int,node*);
node *del_front(node*);
node *del_rear(node*);
node *del_specific(int,node*);
void display(node*);
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
        printf("choose : ");
        scanf("%d",&ch);
        int ele;
        switch(ch)
        {
            case 1:
            printf("Enter the element : ");
            scanf("%d",&ele);
            first=ins_front(ele,first);
            break;

            case 2:
            printf("enter an element : ");
            scanf("%d",&ele);
            first=ins_rear(ele,first);
            break;

            case 3:
            first=del_front(first);
            break;

            case 4:
            first=del_rear(first);
            break;

            case 5:
            printf("enter the data,whose node is to be deletd : ");
            scanf("%d",&ele);
            first=del_specific(ele,first);

            case 6:
            if(first==NULL)
                printf("list is empty\n");
            else
                display(first);
            
            case 7:
            printf("code terminated ...\n");
            exit(0);
        }
    }
}
//this is a commnit
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
    node *new=getnode();
    new->data=ele;
    new->link=NULL;
    if(fir==NULL)
        return new;
    new->link=fir;
    return new;
}

node *ins_rear(int ele,node* first)
{
    node *new=getnode();
    new->data=ele;
    new->link=NULL;
    if(first==NULL)
        return new;
    node* temp=first;
    while(temp->link!=NULL)
        temp=temp->link;
    temp->link=new;
    return first;
}

node* del_front(node* first)
{
    if(first==NULL)
        return NULL;
    if(first->link==NULL)
    {
        printf("the deleted is %d",first->data);
        free(first);
        return NULL;
    }
    node *temp=first;
    first=first->link;
    printf("the deleted is %d",temp->data);
    free(temp);
    return first;

}

node* del_rear(node* first)
{
    if(first==NULL)
        return NULL;
    
    if(first->link==NULL)
    {
        printf("delete is %d",first->data);
        free(first);
        return NULL;
    }
    node *prev=NULL,*cur;vgsrgb f
    cur=first;
    while(cur->link!=NULL)
    {
        prev=cur;
        cur=cur->link;
    }
    printf("the deleted is %d\n",cur->data);
    free(cur);
    prev->link=NULL;
    return first;
}

node* del_specific(int ele,node *first)
{
    if(first==NULL)
    {
        printf("List is empty");
        return NULL;
    }
    if(first->data==ele)
    {
        node* temp=first;
        printf("deleted is %d",temp->data);
        first=first->link;
        free(temp);
        return first;
    }
    node* prev=NULL,*cur=first;
    while(cur!=NULL)
    {
        if(cur->data==ele)
        {
            printf("deleted element = %d",cur->data);
            prev->link=cur->link;
            free(cur);
            return first;
        }
        prev=cur;
        cur=cur->link;
        if(cur==NULL)
        {
            printf("element not found");
            return first;
        }
    }
}
void display(node* first)
{
    node* temp=first;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->link;
    }
}
/*stack and queue operations are valid in singly linked list 
    insert front and delete front 
    insert rear and delete rear are stack operations*/